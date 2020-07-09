#!/bin/bash
# Written by Madu Manathunga 03/07/2019

# This script runs a series of test cases saved in tests folder and verifies the correctness of quick
# You should run from the quick home directory

#Set values for the variables
qhome=$PWD
tstdir=${qhome}/tests
qbasisdir=${qhome}/basis
qbindir=${qhome}/bin
qexe="quick.cuda"
export QUICK_BASIS=$qbasisdir
nprocs=4

echo " Please select the QUICK executable you want to test (type the corresponding number and hit enter):"
echo " 1 --> quick"
echo " 2 --> quick.MPI"
echo " 3 --> quick.cuda"
echo " 4 --> quick.cuda.MPI"

read executable
echo ""
case $executable in
     1) echo "serial version selected." 
	qexe="quick"
     ;;
     2) echo "MPI version selected." 
	qexe="quick.MPI"
     ;;
     3) echo "CUDA version selected."
	qexe="quick.cuda"
     ;;
     4) echo "CUDA MPI version selected."
        qexe="quick.cuda.MPI"
     ;;
     *) echo "Please select the QUICK version by selecting 1-4."
	echo"Aborting.."
        echo ""        
        exit 0
esac

# check if the executable is available
if [ -f "${qbindir}/${qexe}" ]; then
	echo ""
	echo "Running quick tests... This will take several minutes!"
	echo ""

else
	echo "${qbindir}/${qexe} not found."
	echo "Aborting.."
	echo ""
	exit 0
fi

# if the mpi version is selected check if mpirun is available
#ismpirun=$(mpirun --version | grep "Version" | wc -l)

#if [ ("${qexe}"  == 'quick.MPI') && ($ismpirun -gt 0) ]; then
#     echo "mpirun found. Tests will be carried out with ${nprocs} cores."
#     echo ""
#else
#     echo "mpirun executable not found. Tests will be carried out in serial mode."
#     echo ""
#fi

# Make sure tstdir is existing
if [ -d ${tstdir} ]; then
	cd $tstdir
else
	echo "${tstdir} not found. Aborting.."
	exit 0
fi

if [ -d tstrun ]; then
	rm -f ./tstrun/*
else
	mkdir tstrun
fi

#Check if tstlst is located inside the tstdir
if [ -f tstlst ]; then
	#If the file exists, run tests
	total=$(cat tstlst |wc -l)
	a=1
	cd tstrun

	#Run energy tests
	for i in $(awk '{print $1}' ../tstlst| grep "ene")
	do
		echo "Running test ${a} of ${total}"
		cp ../${i}.in ./
		
		#This variable will keep the information of jobcard
		jobcard=$(head -1 ${i}.in)	
                if [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"HF"*) ]]; then
                        echo "This is a RHF energy test..."
                elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"LDA"*) ]]; then
                        echo "This is a DFT energy test... A representative LIBXC LDA functional is used."
                elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"GGA"*) ]]; then
                        echo "This is a DFT energy test... A representative LIBXC GGA functional is used."
                elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"HYB_GGA"*) ]]; then
                        echo "This is a DFT energy test... A representative LIBXC hybrid GGA functional is used."
		elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"BLYP"*) ]]; then
                        echo "This is a DFT energy test... Native BLYP functional is used."
		elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"B3LYP"*) ]]; then
                        echo "This is a DFT energy test... Native B3LYP functional is used."
                elif [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"MP2"*) ]];then
                        echo "This is a MP2 energy test..."
		fi

		#Run the test case
		${qbindir}/${qexe} ${i}.in >${i}.run.log	

		#Check the accuracy
		#For RHF and DFT,  just compare the total energy. For MP2 compare the mp2 energy. 
                if [[ ($jobcard == *"ENERGY"*) && ($jobcard == *"MP2"*) ]];then

                refval=$(grep "#MP2_ENERGY" ${i}.in |awk '{print $2}')
                newval=$(grep -A 20 "REACH CONVERGENCE AFTER" ${i}.out| grep "EMP2" | awk '{print $3}')
                echo "$refval  $newval"|awk '{
                        x=sqrt(($1-$2)^2); 
                        if(x>=0.00001) stat="failed"; else stat="passed"; 
                        print "MP2 energy: " $2 ", Reference value: " $1 ". Test " stat "."
                }'                         

		else 

		refval=$(grep "#TOTAL_ENERGY" ${i}.in |awk '{print $2}')
		newval=$(grep -A 8 "REACH CONVERGENCE AFTER" ${i}.out| grep "TOTAL" | awk '{print $4}')
		echo "$refval  $newval"|awk '{
			x=sqrt(($1-$2)^2); 
			if(x>=0.00001) stat="failed"; else stat="passed"; 
			print "Total energy: " $2 ", Reference value: " $1 ". Test " stat "."
		}'	

		fi

		echo ""
		a=$((a+1))
	done


	#Run gradient tests
	for i in $(awk '{print $1}' ../tstlst|grep "opt")
	do
		echo "Running test ${a} of ${total}"
		cp ../${i}.in ./
		
                #This variable will keep the information of jobcard
                jobcard=$(head -1 ${i}.in)      
                        if [[ ($jobcard == *"OPT"*) && ($jobcard == *"HF"*) ]]; then
                                echo "This is a RHF geometry optimization test..."
                        fi      

                #Run the test case
#                if [ (${qexe} == "quick.MPI") && (${ismpirun} > 0) ]; then
#                else
                    ${qbindir}/${qexe} ${i}.in >${i}.run.log
#                fi		

		#Check the accuracy of gradients of first step
		grep "#ref_grad" ${i}.in |awk '{print $2}'>refGrad.txt
		sed -n '/GEOMETRY FOR OPTIMIZATION STEP   1/,/GEOMETRY FOR OPTIMIZATION STEP   2/p' ${i}.out | sed -n '/NEW_GRAD/,/OPTIMZATION STATISTICS/p' |grep '[0-9]' |awk '{print $4}'>newGrad.txt
		paste refGrad.txt newGrad.txt >compGrad.txt
                awk '{
                        x=sqrt(($1-$2)^2); 
                        if(x>=0.00001) stat="failed"; else stat="passed"; 
                        print "Final gradient: " $2 ", Reference value: " $1 ". Test " stat "."
                }' compGrad.txt
                echo ""
		
		#remove gradient info files
		rm refGrad.txt newGrad.txt compGrad.txt
		
		#Check the minimum energy
                refval=$(grep "#ref_min_ene" ${i}.in |awk '{print $2}')
                newval=$(grep "MINIMIZED ENERGY" ${i}.out| awk '{print $3}')
                echo "$refval  $newval"|awk '{
                        x=sqrt(($1-$2)^2); 
                        if(x>=0.00001) stat="failed"; else stat="passed"; 
                        print "Minimized energy: " $2 ", Reference value: " $1 ". Test " stat "."
                }'
                echo ""


                a=$((a+1))		

	done
		
	echo "All tests are done!"
	echo ""
	cd $qhome
else
	echo "File tstlst not found. Aborting.."
	exit 0 
fi
