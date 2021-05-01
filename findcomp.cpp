
#include "ConnectedComponent.h"
#include "PGMimageProcessor.h"
#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>

using namespace std;

int main(int argc,char* argv[]){

string option;
int min=3;
int max;
unsigned char thresh=190;
string filename = "chess.pgm";
string output = "out.pgm";
DCHCAS001::PGMimageProcessor Image1;

  int i =1;
  bool printselect = false;
  bool writeselect = false;
  bool select = false;
  while(i < argc)
  {
  if (string(argv[i]) == "-s")
  {
  	option = string(argv[i]);
  	min = atoi(argv[i+1]);
  	max = atoi(argv[i+2]);
  	i+=3;
  	select = true;
  
  }
  else if (string(argv[i]) == "-t")
  {
  	option = string(argv[i]);
  	stringstream s(string(argv[i+1]));
  	s >> thresh;
  	i+=2;
  
  }
  else if (string(argv[i]) == "-p")
  {
  	option = string(argv[i]);
  	i+=1;
  	printselect = true;
  
  }
  else if (string(argv[i]) == "-w")
  {
  	option = string(argv[i]);
  	output = string(argv[i+1]);
  	i+=2;
  	writeselect = true;
  
  }
  else
  {
  	filename = string(argv[i]);
  	i++;
  }

  }
   Image1.readImage(filename);
  if(!(select))
  {
  min = 3;
  max = Image1.getRow()*Image1.getColumn();
  }
  
  Image1.extractComponents(thresh,min);
  Image1.filterComponentsBySize(min,max);
  if((writeselect))
  {
	Image1.writeComponents(output);
  }
   if((printselect))
  {
	Image1.printAllComponents();
  }
   
 return 0;
}


