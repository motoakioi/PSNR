#include<iostream>
#include<fstream>

#include"psnr.h"
#include"yuv.h"

int main(int argc, char* argv[]){

if( argc != 6){
	std::cerr<< "Error! : " <<std::endl;
	std::cerr<< "usege : file1.yuv, file2.yuv, width, height, format" <<std::endl;
	return -1;
}

std::ifstream video1( argv[1], std::ios::in | std::ios::binary );
std::ifstream video2( argv[2], std::ios::in | std::ios::binary );
if( !video1 || !video2 ){
	std::cerr<< "Error! : can't open file." << std::endl;
	return -1;
}

if( atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0 ){
	std::cerr<< "Error! : resolution should not be 0." <<std::endl;
	return -1;
}

int in_format = atoi(argv[5]);
if( in_format == 420){

}else{
	std::cerr<< "Error! : invalid format." <<std::endl;
	return -1;
}

int width = std::atoi( argv[3] );
int height = std::atoi( argv[4] );
int all_pixels = width * height;
int size_of_1_farme = all_pixels * size_cal( in_format );

unsigned char data1[size_of_1_farme];
unsigned char data2[size_of_1_farme];

int frame_number = 0;
int frame_number_of_none_zero = 0;
//double sum_psnr = 0.0;
double sum_mse = 0.0;
double ave_psnr;
double ave_mse;

while( !video1.eof() ){
	double mse_val = 0.0;
	double psnr_val = 0.0;

	video1.read( (char*)data1, size_of_1_farme );
	video2.read( (char*)data2, size_of_1_farme );

	mse( data1, data2, &size_of_1_farme, &mse_val);
	psnr( &mse_val, &psnr_val ); 

	std::cout<< "Frame(" << frame_number << ") PSNR[dB] : " << psnr_val <<std::endl;
	frame_number++;

	if( mse_val != 0 ){
		sum_mse += mse_val;
		frame_number_of_none_zero++;
	}
}

ave_mse = sum_mse / frame_number_of_none_zero;
psnr( &ave_mse, &ave_psnr );

//std::cout<< "Average PSNR : " << ( sum_psnr / (double)frame_number_of_none_zero ) << std::endl;
std::cout<< "Average PSNR : " << ave_psnr << std::endl;

video1.close();
video2.close();

	return 0;
}

