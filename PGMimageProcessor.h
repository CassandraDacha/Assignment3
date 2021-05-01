#ifndef __PGMimage__
#define __PGMimage__
#include <sstream>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <sstream>
#include "ConnectedComponent.h"
#include <queue>

using namespace std;
namespace DCHCAS001 // The name of this namespace should normally be your student number for assignments
{


class PGMimageProcessor
{
	// Local Variables
private:
	int row, col;
	unique_ptr<unsigned char[]> binary_data;
	vector<unique_ptr<ConnectedComponent>> components;
public:
	// Default Constructor 	
	PGMimageProcessor();
	// Custom Constructor
	PGMimageProcessor(const int row, const int col,  unique_ptr<unsigned char[]> binary_data); 
	// Destructor
	~PGMimageProcessor();
	// Copy Constructor
	PGMimageProcessor(const PGMimageProcessor& p);
	// Copy Assignment Operator
	PGMimageProcessor& operator=(const PGMimageProcessor& rhs);
	// Move constructor
	PGMimageProcessor(PGMimageProcessor && p); 
	//Move Assignment Operator
	PGMimageProcessor& operator=(PGMimageProcessor&& rhs);
	//Accessors
        int getColumn() const;
        int getRow() const;
        unique_ptr<unsigned char[]>& getData();
        
        //Mutators
        void setColumn(int col);
        void setRow(int row);
        void readImage(string filename);
	//other methods
	int extractComponents(unsigned char threshold, int minValidSize);
	int filterComponentsBySize(int minSize, int maxSize);
	bool writeComponents(const std::string & outFileName);
	int getComponentCount(void) const;
	int getLargestSize(void) const;
	int getSmallestSize(void) const;
	void printComponentData(const ConnectedComponent & theComponent) const;
	};
}
#endif
