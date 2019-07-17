
//Uploads parameters required for kernels. *p is a pointer to libxc functional, gpu_work_params is a pointer
//to host memory location containing worker paramters 
void* gpu_upload_maple2c_params(const xc_func_type *p){

        void *d_maple_params;
        cudaMalloc((void**)&d_maple_params, p->params_byte_size);
        cudaMemcpy(d_maple_params, (p->params), p->params_byte_size, cudaMemcpyHostToDevice);
        return d_maple_params;

}

//Uploads paramters required for kernels. *p is a pointer to libxc functional, gpu_work_params is a pointer
//to host memory location containing worker paramters 
void* gpu_upload_work_params(const xc_func_type *p, void* gpu_work_params){

        void *d_work_params;
        int work_param_size;

        //check the family
        switch(p->info->family){
        case(XC_FAMILY_GGA):
                //Now check the kind. 
                switch(p->info->kind){
                        case(XC_EXCHANGE):
                                 work_param_size = sizeof(gpu_ggax_work_params);
                        break;
                }
        break;
        }

        cudaMalloc((void**)&d_work_params, work_param_size);
        cudaMemcpy(d_work_params, gpu_work_params, work_param_size, cudaMemcpyHostToDevice);
        return d_work_params;

}

void* gpu_upload_std_libxc_work_params(const xc_func_type *p, void* std_libxc_work_params, int size){

        void *d_work_params;
        int total_arr_size;
        int element_size;

        //check the family
        switch(p->info->family){
        case(XC_FAMILY_GGA):
                //Now check the kind. 
                switch(p->info->kind){
                        case(XC_EXCHANGE):

                                xc_gga_work_x_t *tmp_h_arr;
                                tmp_h_arr = (xc_gga_work_x_t*)std_libxc_work_params;

                                element_size = sizeof(xc_gga_work_x_t);
                                total_arr_size = size*element_size;

                                xc_gga_work_x_t *h_work_params;
                                h_work_params = (xc_gga_work_x_t*)malloc(total_arr_size);

                                for(int i=0;i<size;i++){
                                        h_work_params[i] = *tmp_h_arr;
                                        if(GPU_DEBUG){
                                                printf("FILE: %s, LINE: %d, FUNCTION: %s, h_work_params[i]: %d \n",
						 __FILE__, __LINE__, __func__, h_work_params[i].order);
                                        }
                                }
                                cudaMalloc((void**)&d_work_params, total_arr_size);

                                cudaMemcpy(d_work_params, h_work_params, total_arr_size, cudaMemcpyHostToDevice);

                        break;
                }
        break;
        }

        return d_work_params;

}

//returns a pointer to an empty device array
double* gpu_upload_libxc_out_array(int size){
        double *d_double_arr;
        int arr_size = size * sizeof(double);
        cudaMalloc((void**)&d_double_arr, arr_size);

        return d_double_arr;
}

//returns a pointer to a populated device array 
double* gpu_upload_libxc_input_array(const double *h_input, int size){
        double *d_double_arr;
        int arr_size = size * sizeof(double);
        cudaMalloc((void**)&d_double_arr, arr_size);
        cudaMemcpy(d_double_arr, h_input, arr_size, cudaMemcpyHostToDevice);

        return d_double_arr;
}
//Returns pointer to a memory location on device
gpu_libxc_info* gpu_upload_libxc_info(const xc_func_type *p, gpu_ggax_work_params *ggwp, xc_gga_work_x_t h_r, int np){
	gpu_libxc_info h_glinfo;
	h_glinfo.d_maple2c_params = gpu_upload_maple2c_params(p);
	h_glinfo.d_worker_params = gpu_upload_work_params(p, (void*)ggwp);
        //allocate device memory for some work params required by gga_x worker.
          h_glinfo.d_gdm = gpu_upload_libxc_out_array(np);
          h_glinfo.d_ds = gpu_upload_libxc_out_array(np);
          h_glinfo.d_rhoLDA = gpu_upload_libxc_out_array(np);
        //h_glinfo.d_zk = gpu_upload_libxc_out(np);
        //h_glinfo.d_vrho = gpu_upload_libxc_out(np);
        //h_glinfo.d_vsigma = gpu_upload_libxc_out(np);
        h_glinfo.d_std_libxc_work_params = gpu_upload_std_libxc_work_params(p, &h_r, np);

	gpu_libxc_info* d_glinfo;
	cudaMalloc((void**)&d_glinfo, sizeof(gpu_libxc_info));
	cudaMemcpy(d_glinfo, &h_glinfo, sizeof(gpu_libxc_info), cudaMemcpyHostToDevice);

	return d_glinfo;
}

gpu_libxc_out* gpu_upload_libxc_out(int np){
	gpu_libxc_out h_glout;
	h_glout.d_zk = gpu_upload_libxc_out_array(np);
	h_glout.d_vrho = gpu_upload_libxc_out_array(np);
	h_glout.d_vsigma = gpu_upload_libxc_out_array(np);


	gpu_libxc_out* d_glout;
	cudaMalloc((void**)&d_glout, sizeof(gpu_libxc_out));
	cudaMemcpy(d_glout, &h_glout, sizeof(gpu_libxc_out), cudaMemcpyHostToDevice);

	return d_glout;
}

gpu_libxc_in* gpu_upload_libxc_in(const double* h_rho, const double *h_sigma, int np){
        gpu_libxc_in h_glin;
        h_glin.d_rho = gpu_upload_libxc_input_array(h_rho, np);
        h_glin.d_sigma = gpu_upload_libxc_input_array(h_sigma, np);

        gpu_libxc_in* d_glin;
        cudaMalloc((void**)&d_glin, sizeof(gpu_libxc_in));
        cudaMemcpy(d_glin, &h_glin, sizeof(gpu_libxc_in), cudaMemcpyHostToDevice);

        return d_glin;
}
