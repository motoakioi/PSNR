#include "video.hpp"
#include <stdexcept>
#define YUV444 444
#define YUV420 420

Video::Video(int width, int height, int format) {
	if (format != YUV420 || format != YUV444) {
		throw std::invalid_argument("recieved invalid YUV format");
	}
	totalPixel = width * height;
	sizeofFrame = totalPixel * (format == 444 ? 3.0 : 1.5);
}

Video::getTotalPixel() {
	return totalPixel;
}

Video::getSizeofFrame() {
	return sizeofFrame;
}
