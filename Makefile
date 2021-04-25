driver.exe: PGMimageProcessor.o driver.o
	g++ PGMimageProcessor.o driver.o -o driver.exe -std=c++2a

PGMimageProcessor.o: PGMimageProcessor.cpp
	g++ -c PGMimageProcessor.cpp -o PGMimageProcessor.o -std=c++2a
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o -std=c++2a
clean:
	rm *.o driver.exe 
run:
	./driver.exe

