driver.exe: ConnectedComponent.o test.o
	g++ ConnectedComponent.o test.o -o driver.exe -std=c++2a

PGMimageProcessor.o: ConnectedComponent.cpp
	g++ -c ConnectedComponent.cpp -o ConnectedComponent.o -std=c++2a
test.o: test.cpp
	g++ -c test.cpp -o test.o -std=c++2a
clean:
	rm *.o driver.exe 
run:
	./driver.exe

