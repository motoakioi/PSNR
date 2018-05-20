psnr : main.o psnr.o yuv.o
	g++ -std=c++11 -Wall -o psnr main.o psnr.o yuv.o
	rm -f *.o 
main.o : ./src/main.cpp
	g++ -std=c++11 -Wall -c ./src/main.cpp
psnr.o : ./src/psnr.cpp
	g++ -std=c++11 -Wall -c ./src/psnr.cpp
yuv.o : ./src/yuv.cpp
	g++ -std=c++11 -Wall -c ./src/yuv.cpp

