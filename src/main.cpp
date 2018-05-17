#include<iostream>
#include<fstream>

#include"psnr.h"

int main(int argc, char* argv[]){

if( argc != 5){
	std::cout<< "" <<std::endl;
	std::cout<< "usege : file1.yuv, file2.yuv, width, height" <<std::endl;
	return -1;
}

std::ifstream video1( "argv[1]", std::ios::in | std::ios::binary );
std::ifstream video2( "argv[2]", std::ios::in | std::ios::binary );

if( !video1 || !video2 ){
	std::cout<< "can't open file." << std::endl;
	return -1;
}




	return 0;
}

