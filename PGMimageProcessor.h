#ifndef __PGMimage__
#define __PGMimage__
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
namespace DCHCAS001 // The name of this namespace should normally be your student number for assignments
{


class PGMimageProcessor
{
	// Local Variables
	int row, col;
	unsigned char* binary_data;
	
	public: 
	
	PGMimageProcessor(); // Default Constructor
	PGMimageProcessor(const int row, const int col, const char binary_data); // Custom Constructor
	
	~PGMimageProcessor(); // Destructor
	
	PGMimageProcessor(const PGMimageProcessor& p); // Copy Constructor
	PGMimageProcessor(PGMimageProcessor && p); // Move constructor
	
	PGMimageProcessor& operator=(const PGMimageProcessor& rhs); // Copy Assignment Operator
	
	PGMimageProcessor& operator=(PGMimageProcessor&& rhs); //Move Assignment Operator
	//Accessors
        int getColumn() const;
        int getRow() const;
        //unsigned char & getData();
        //Mutators
        void setColumn(int col);
        void setRow(int row);
        void readImage(ifstream& infile);
	
	};
}
#endif
