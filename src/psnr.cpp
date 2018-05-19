#include<iostream>
#include"psnr.h"

#define pixel_range 255

void mse(unsigned char *in1, unsigned char *in2, int resoloution, int *out_mse){
	for( int i=0 ; i < resoloution ; i++ ){
		int diff = in1[i] - in2[i]; 
		*out_mse += diff * diff; 
	}
}

void psnr(int *in_mse, double *out_psnr){
	*out_psnr = 10 * log10((pixel_range * pixel_range) / *in_mse);
}
