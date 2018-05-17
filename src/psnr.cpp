#include<iostream>
#include"psnr.h"

#define pixel_range 255

int mse(char *in1, char *in2, int resoloution){
	int *out_mse;
	for( int i=0 ; i<resoloution ; i++ ){
		int diff = (int)in1[i] - (int)in2[i]; 
		*out_mse += diff * diff; 
	}
	return *out_mse;
}

double psnr(int mse){
	return 10 * log10((pixel_range * pixel_range) / mse);
}
