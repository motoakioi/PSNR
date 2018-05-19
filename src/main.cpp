#include<iostream>
#include<fstream>

#include"psnr.h"
#include"yuv.h"

int main(int argc, char* argv[]){

if( argc != 6){
	std::cout<< "Error! : " <<std::endl;
	std::cout<< "usege : file1.yuv, file2.yuv, width, height, format" <<std::endl;
	return -1;
}

std::ifstream video1( argv[1], std::ios::in | std::ios::binary );
std::ifstream video2( argv[2], std::ios::in | std::ios::binary );
if( !video1 || !video2 ){
	std::cout<< "Error! : can't open file." << std::endl;
	return -1;
}

if( atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0 ){
	std::cout<< "Error! : resolution should not be 0." <<std::endl;
	return -1;
}

int in_format = atoi(argv[5]);
if( in_format == 420){

}else{
	std::cout<< "Error! : invalid format." <<std::endl;
	return -1;
}

int width = std::atoi( argv[3] );
int height = std::atoi( argv[4] );
int all_pixels = width * height;
int size_of_1_farme = all_pixels * size_cal( in_format );


unsigned char data1[size_of_1_farme];
unsigned char data2[size_of_1_farme];
while( !video1.eof() ){
	video1.read( (char*)data1, size_of_1_farme );
	video2.read( (char*)data2, size_of_1_farme );
	int out_mse = 0;

	mse( data1, data2, all_pixels, &out_mse); 

}

video1.close();
video2.close();

	return 0;
}

