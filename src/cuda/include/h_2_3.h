#include "../gpu_common.h"
#include "./h_all_files.h"
// Class for L =            2  B =            3
__device__ __inline__  f_2_3_t :: f_2_3_t ( f_1_3_t t_1_3_0, f_1_3_t t_1_3_1, f_0_3_t t_0_3_0, f_0_3_t t_0_3_1, QUICKDouble ABtemp, QUICKDouble CDcom, f_1_2_t t_1_2_1, QUICKDouble ABCDtemp, QUICKDouble Ptempx, QUICKDouble Ptempy, QUICKDouble Ptempz,  QUICKDouble WPtempx, QUICKDouble WPtempy, QUICKDouble WPtempz) {
    x_4_10 = Ptempx * t_1_3_0.x_2_10 + WPtempx * t_1_3_1.x_2_10 + ABCDtemp * t_1_2_1.x_2_5 ;
    x_4_11 = Ptempx * t_1_3_0.x_2_11 + WPtempx * t_1_3_1.x_2_11 + 2 * ABCDtemp * t_1_2_1.x_2_4 ;
    x_4_12 = Ptempx * t_1_3_0.x_2_12 + WPtempx * t_1_3_1.x_2_12 + ABCDtemp * t_1_2_1.x_2_8 ;
    x_4_13 = Ptempx * t_1_3_0.x_2_13 + WPtempx * t_1_3_1.x_2_13 + 2 * ABCDtemp * t_1_2_1.x_2_6 ;
    x_4_14 = Ptempx * t_1_3_0.x_2_14 + WPtempx * t_1_3_1.x_2_14 + ABCDtemp * t_1_2_1.x_2_9 ;
    x_4_15 = Ptempx * t_1_3_0.x_2_15 + WPtempx * t_1_3_1.x_2_15 ;
    x_4_16 = Ptempx * t_1_3_0.x_2_16 + WPtempx * t_1_3_1.x_2_16 ;
    x_4_17 = Ptempx * t_1_3_0.x_2_17 + WPtempx * t_1_3_1.x_2_17 + 3 * ABCDtemp * t_1_2_1.x_2_7 ;
    x_4_18 = Ptempx * t_1_3_0.x_2_18 + WPtempx * t_1_3_1.x_2_18 ;
    x_4_19 = Ptempx * t_1_3_0.x_2_19 + WPtempx * t_1_3_1.x_2_19 ;
    x_5_10 = Ptempy * t_1_3_0.x_3_10 + WPtempy * t_1_3_1.x_3_10 + ABCDtemp * t_1_2_1.x_3_6 ;
    x_5_11 = Ptempy * t_1_3_0.x_3_11 + WPtempy * t_1_3_1.x_3_11 + ABCDtemp * t_1_2_1.x_3_7 ;
    x_5_12 = Ptempy * t_1_3_0.x_3_12 + WPtempy * t_1_3_1.x_3_12 + 2 * ABCDtemp * t_1_2_1.x_3_4 ;
    x_5_13 = Ptempy * t_1_3_0.x_3_13 + WPtempy * t_1_3_1.x_3_13 ;
    x_5_14 = Ptempy * t_1_3_0.x_3_14 + WPtempy * t_1_3_1.x_3_14 ;
    x_5_15 = Ptempy * t_1_3_0.x_3_15 + WPtempy * t_1_3_1.x_3_15 + 2 * ABCDtemp * t_1_2_1.x_3_5 ;
    x_5_16 = Ptempy * t_1_3_0.x_3_16 + WPtempy * t_1_3_1.x_3_16 + ABCDtemp * t_1_2_1.x_3_9 ;
    x_5_17 = Ptempy * t_1_3_0.x_3_17 + WPtempy * t_1_3_1.x_3_17 ;
    x_5_18 = Ptempy * t_1_3_0.x_3_18 + WPtempy * t_1_3_1.x_3_18 + 3 * ABCDtemp * t_1_2_1.x_3_8 ;
    x_5_19 = Ptempy * t_1_3_0.x_3_19 + WPtempy * t_1_3_1.x_3_19 ;
    x_6_10 = Ptempx * t_1_3_0.x_3_10 + WPtempx * t_1_3_1.x_3_10 + ABCDtemp * t_1_2_1.x_3_5 ;
    x_6_11 = Ptempx * t_1_3_0.x_3_11 + WPtempx * t_1_3_1.x_3_11 + 2 * ABCDtemp * t_1_2_1.x_3_4 ;
    x_6_12 = Ptempx * t_1_3_0.x_3_12 + WPtempx * t_1_3_1.x_3_12 + ABCDtemp * t_1_2_1.x_3_8 ;
    x_6_13 = Ptempx * t_1_3_0.x_3_13 + WPtempx * t_1_3_1.x_3_13 + 2 * ABCDtemp * t_1_2_1.x_3_6 ;
    x_6_14 = Ptempx * t_1_3_0.x_3_14 + WPtempx * t_1_3_1.x_3_14 + ABCDtemp * t_1_2_1.x_3_9 ;
    x_6_15 = Ptempx * t_1_3_0.x_3_15 + WPtempx * t_1_3_1.x_3_15 ;
    x_6_16 = Ptempx * t_1_3_0.x_3_16 + WPtempx * t_1_3_1.x_3_16 ;
    x_6_17 = Ptempx * t_1_3_0.x_3_17 + WPtempx * t_1_3_1.x_3_17 + 3 * ABCDtemp * t_1_2_1.x_3_7 ;
    x_6_18 = Ptempx * t_1_3_0.x_3_18 + WPtempx * t_1_3_1.x_3_18 ;
    x_6_19 = Ptempx * t_1_3_0.x_3_19 + WPtempx * t_1_3_1.x_3_19 ;
    x_7_10 = Ptempx * t_1_3_0.x_1_10 + WPtempx * t_1_3_1.x_1_10 + ABtemp * ( t_0_3_0.x_0_10 -  CDcom * t_0_3_1.x_0_10 ) + ABCDtemp * t_1_2_1.x_1_5 ;
    x_7_11 = Ptempx * t_1_3_0.x_1_11 + WPtempx * t_1_3_1.x_1_11 + ABtemp * ( t_0_3_0.x_0_11 -  CDcom * t_0_3_1.x_0_11 ) + 2 * ABCDtemp * t_1_2_1.x_1_4 ;
    x_7_12 = Ptempx * t_1_3_0.x_1_12 + WPtempx * t_1_3_1.x_1_12 + ABtemp * ( t_0_3_0.x_0_12 -  CDcom * t_0_3_1.x_0_12 ) + ABCDtemp * t_1_2_1.x_1_8 ;
    x_7_13 = Ptempx * t_1_3_0.x_1_13 + WPtempx * t_1_3_1.x_1_13 + ABtemp * ( t_0_3_0.x_0_13 -  CDcom * t_0_3_1.x_0_13 ) + 2 * ABCDtemp * t_1_2_1.x_1_6 ;
    x_7_14 = Ptempx * t_1_3_0.x_1_14 + WPtempx * t_1_3_1.x_1_14 + ABtemp * ( t_0_3_0.x_0_14 -  CDcom * t_0_3_1.x_0_14 ) + ABCDtemp * t_1_2_1.x_1_9 ;
    x_7_15 = Ptempx * t_1_3_0.x_1_15 + WPtempx * t_1_3_1.x_1_15 + ABtemp * ( t_0_3_0.x_0_15 -  CDcom * t_0_3_1.x_0_15 ) ;
    x_7_16 = Ptempx * t_1_3_0.x_1_16 + WPtempx * t_1_3_1.x_1_16 + ABtemp * ( t_0_3_0.x_0_16 -  CDcom * t_0_3_1.x_0_16 ) ;
    x_7_17 = Ptempx * t_1_3_0.x_1_17 + WPtempx * t_1_3_1.x_1_17 + ABtemp * ( t_0_3_0.x_0_17 -  CDcom * t_0_3_1.x_0_17 ) + 3 * ABCDtemp * t_1_2_1.x_1_7 ;
    x_7_18 = Ptempx * t_1_3_0.x_1_18 + WPtempx * t_1_3_1.x_1_18 + ABtemp * ( t_0_3_0.x_0_18 -  CDcom * t_0_3_1.x_0_18 ) ;
    x_7_19 = Ptempx * t_1_3_0.x_1_19 + WPtempx * t_1_3_1.x_1_19 + ABtemp * ( t_0_3_0.x_0_19 -  CDcom * t_0_3_1.x_0_19 ) ;
    x_8_10 = Ptempy * t_1_3_0.x_2_10 + WPtempy * t_1_3_1.x_2_10 + ABtemp * ( t_0_3_0.x_0_10 -  CDcom * t_0_3_1.x_0_10 ) + ABCDtemp * t_1_2_1.x_2_6 ;
    x_8_11 = Ptempy * t_1_3_0.x_2_11 + WPtempy * t_1_3_1.x_2_11 + ABtemp * ( t_0_3_0.x_0_11 -  CDcom * t_0_3_1.x_0_11 ) + ABCDtemp * t_1_2_1.x_2_7 ;
    x_8_12 = Ptempy * t_1_3_0.x_2_12 + WPtempy * t_1_3_1.x_2_12 + ABtemp * ( t_0_3_0.x_0_12 -  CDcom * t_0_3_1.x_0_12 ) + 2 * ABCDtemp * t_1_2_1.x_2_4 ;
    x_8_13 = Ptempy * t_1_3_0.x_2_13 + WPtempy * t_1_3_1.x_2_13 + ABtemp * ( t_0_3_0.x_0_13 -  CDcom * t_0_3_1.x_0_13 ) ;
    x_8_14 = Ptempy * t_1_3_0.x_2_14 + WPtempy * t_1_3_1.x_2_14 + ABtemp * ( t_0_3_0.x_0_14 -  CDcom * t_0_3_1.x_0_14 ) ;
    x_8_15 = Ptempy * t_1_3_0.x_2_15 + WPtempy * t_1_3_1.x_2_15 + ABtemp * ( t_0_3_0.x_0_15 -  CDcom * t_0_3_1.x_0_15 ) + 2 * ABCDtemp * t_1_2_1.x_2_5 ;
    x_8_16 = Ptempy * t_1_3_0.x_2_16 + WPtempy * t_1_3_1.x_2_16 + ABtemp * ( t_0_3_0.x_0_16 -  CDcom * t_0_3_1.x_0_16 ) + ABCDtemp * t_1_2_1.x_2_9 ;
    x_8_17 = Ptempy * t_1_3_0.x_2_17 + WPtempy * t_1_3_1.x_2_17 + ABtemp * ( t_0_3_0.x_0_17 -  CDcom * t_0_3_1.x_0_17 ) ;
    x_8_18 = Ptempy * t_1_3_0.x_2_18 + WPtempy * t_1_3_1.x_2_18 + ABtemp * ( t_0_3_0.x_0_18 -  CDcom * t_0_3_1.x_0_18 ) + 3 * ABCDtemp * t_1_2_1.x_2_8 ;
    x_8_19 = Ptempy * t_1_3_0.x_2_19 + WPtempy * t_1_3_1.x_2_19 + ABtemp * ( t_0_3_0.x_0_19 -  CDcom * t_0_3_1.x_0_19 ) ;
    x_9_10 = Ptempz * t_1_3_0.x_3_10 + WPtempz * t_1_3_1.x_3_10 + ABtemp * ( t_0_3_0.x_0_10 -  CDcom * t_0_3_1.x_0_10 ) + ABCDtemp * t_1_2_1.x_3_4 ;
    x_9_11 = Ptempz * t_1_3_0.x_3_11 + WPtempz * t_1_3_1.x_3_11 + ABtemp * ( t_0_3_0.x_0_11 -  CDcom * t_0_3_1.x_0_11 ) ;
    x_9_12 = Ptempz * t_1_3_0.x_3_12 + WPtempz * t_1_3_1.x_3_12 + ABtemp * ( t_0_3_0.x_0_12 -  CDcom * t_0_3_1.x_0_12 ) ;
    x_9_13 = Ptempz * t_1_3_0.x_3_13 + WPtempz * t_1_3_1.x_3_13 + ABtemp * ( t_0_3_0.x_0_13 -  CDcom * t_0_3_1.x_0_13 ) + ABCDtemp * t_1_2_1.x_3_7 ;
    x_9_14 = Ptempz * t_1_3_0.x_3_14 + WPtempz * t_1_3_1.x_3_14 + ABtemp * ( t_0_3_0.x_0_14 -  CDcom * t_0_3_1.x_0_14 ) + 2 * ABCDtemp * t_1_2_1.x_3_6 ;
    x_9_15 = Ptempz * t_1_3_0.x_3_15 + WPtempz * t_1_3_1.x_3_15 + ABtemp * ( t_0_3_0.x_0_15 -  CDcom * t_0_3_1.x_0_15 ) + ABCDtemp * t_1_2_1.x_3_8 ;
    x_9_16 = Ptempz * t_1_3_0.x_3_16 + WPtempz * t_1_3_1.x_3_16 + ABtemp * ( t_0_3_0.x_0_16 -  CDcom * t_0_3_1.x_0_16 ) + 2 * ABCDtemp * t_1_2_1.x_3_5 ;
    x_9_17 = Ptempz * t_1_3_0.x_3_17 + WPtempz * t_1_3_1.x_3_17 + ABtemp * ( t_0_3_0.x_0_17 -  CDcom * t_0_3_1.x_0_17 ) ;
    x_9_18 = Ptempz * t_1_3_0.x_3_18 + WPtempz * t_1_3_1.x_3_18 + ABtemp * ( t_0_3_0.x_0_18 -  CDcom * t_0_3_1.x_0_18 ) ;
    x_9_19 = Ptempz * t_1_3_0.x_3_19 + WPtempz * t_1_3_1.x_3_19 + ABtemp * ( t_0_3_0.x_0_19 -  CDcom * t_0_3_1.x_0_19 ) + 3 * ABCDtemp * t_1_2_1.x_3_9 ;
}
