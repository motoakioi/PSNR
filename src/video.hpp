#pragma once
class Video {
private:
	double totalPixel;
	double sizeofFrame;
public:
	Video(int width, int height, int format);
	double getTotalPixel();
	double getSizeofFrame();
}
