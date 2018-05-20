psnr : main.o psnr.o yuv.o
	g++ -Wall -o psnr main.o psnr.o yuv.o
	rm -f *.o 
main.o : ./src/main.cpp
	g++ -Wall -c ./src/main.cpp
psnr.o : ./src/psnr.cpp
	g++ -Wall -c ./src/psnr.cpp
yuv.o : ./src/yuv.cpp
	g++ -Wall -c ./src/yuv.cpp

