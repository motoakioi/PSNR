#include<iostream>
#include"psnr.h"

#define pixel_range 255

void mse(unsigned char *in1, unsigned char *in2, int *resoloution, double *out_mse){
	double tmp_mse = 0.0;
	for( int i=0 ; i < *resoloution ; i++ ){
		tmp_mse += (in1[i] - in2[i]) * (in1[i] - in2[i]); 
	}
	*out_mse = tmp_mse / (double)*resoloution;
}

void psnr(double *in_mse, double *out_psnr){
	*out_psnr = 10 * log10((pixel_range * pixel_range) / *in_mse);
}
