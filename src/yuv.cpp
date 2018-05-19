#include"yuv.h"

float size_cal(int format){
	float data_size = 0.0;
	switch( format ){
	case 444:
		data_size = 3.0;
		break;
	case 420:
		data_size = 1.5;
		break;
	default:
		break;
	}
	return data_size;
}
