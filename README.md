# CSC3022F Assignment 1

We were tasked to create a  program that can that can extract all the connected components for the image given some user-supplied threshold.

## Files contained in the folder
PGMimageProcessor.cpp,
ConnectedComponent.cpp, 
PGMimageProcessor.h,
ConnectedComponent.h,
findcomp.cpp,
test.cpp

## How to compile the program
	make
## How to run the test program
	./test.exe
## How to run the driver program
	./findcomp [options] <inputPGMfile>
##Example usage:
	./findcomp -p -w out.pgm -s 7000 8000 chess-thresh.pgm 
	
	will return
	
	File opened
	Component Id is 0 Component pixels are 7640
	Component Id is 1 Component pixels are 7137
	The number of components  is 2
	The smallest Component  is 7137

#NOTE: Test are saved in the test folder

## License
[MIT](https://choosealicense.com/licenses/mit/)
