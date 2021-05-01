all: test.exe findcomp

test.exe: ConnectedComponent.o PGMimageProcessor.o test.o
	g++ ConnectedComponent.o PGMimageProcessor.o test.o -o test.exe -std=c++2a
findcomp: findcomp.o ConnectedComponent.o PGMimageProcessor.o
	g++ findcomp.o ConnectedComponent.o PGMimageProcessor.o -o findcomp -std=c++2a
ConnectedComponent.o: ConnectedComponent.cpp
	g++ -c ConnectedComponent.cpp -o ConnectedComponent.o -std=c++2a
PGMimageProcessor.o: PGMimageProcessor.cpp
	g++ -c PGMimageProcessor.cpp -o PGMimageProcessor.o -std=c++2a 
test.o: test.cpp
	g++ -c test.cpp -o test.o -std=c++2a
findcomp.o: findcomp.cpp
	g++ -c findcomp.cpp -o findcomp.o -std=c++2a

clean:
	rm *.o test.exe findcomp
run:
	./test.exe

