#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <cstring>
#include <cctype>
#include <ctype.h>
using namespace std;

int main() {
  int row = 0, col = 0, numrows = 0, numcols = 0;
  fstream infile("chess.pgm",ios::in | ios::out | ios::binary);
  string inputLine = "";
  string  line = "";
  string x = "";
  int size;
  bool start = false;
  unsigned char temp;
  unsigned char *charImage = nullptr;
  string max;

if (!infile) {
        cout << "Unable to open file" << endl;
    }
    else {
        cout << "File opened" << endl;
        while (getline(infile, line)) {

            if (line != "P5" && line != "255" && line.at(0) != '#') {
                stringstream ss(line);
                if (start == false) {
                    ss >> numcols;
                    ss >> numrows;
                    cout << numrows << " is " << numcols << endl;
                    size = numrows * numcols;
                    
                    start = true;
                }    
          getline(infile, line); 
           cout << line << endl;
	  cout << "Start reading file data: " << endl;
          charImage = new unsigned char [size];
 
	  infile.read( reinterpret_cast<char *>(charImage), (size)*sizeof(unsigned char));
	  cout << "Successfully read " << endl;
	  infile.close();
	  
	  ofstream myfile;
	  myfile.open ("binary.bin");
	  for(row = 0; row < numrows; ++row) {
	    for(col = 0; col < numcols; ++col) {
	      	temp = charImage[row*numcols+col];
	      	  myfile << temp;

	    }
	   myfile.close();
	  }
            }
          
        }
  }
 
  }
 
