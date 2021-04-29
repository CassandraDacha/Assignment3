#include "PGMimageProcessor.h"

using namespace std;
 namespace DCHCAS001{


//default destructor
PGMimageProcessor::PGMimageProcessor() 
  : row(0)
  , col(0)
  , binary_data(nullptr)
{
}

//Custom constructor
PGMimageProcessor::PGMimageProcessor(int row, int col, char binary_data) 
   :row(row)
   , col(col)
   ,binary_data(new unsigned char(binary_data))
{
}
//Destructor
PGMimageProcessor::~PGMimageProcessor()
{
    if(this->binary_data != nullptr) // We have to make sure we're not trying
    // to release a bit of memory that doesn't exist.
    {
    delete this->binary_data;
    }
}

//copy constructor
PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor & p) 
   : row(p.row)
   , col(p.col)
   ,binary_data(nullptr)
   {
  if(p.binary_data != nullptr)
  {
  binary_data = new unsigned char(*p.binary_data);
  }
  }
  //Copy Assignment Operator
PGMimageProcessor& PGMimageProcessor::operator=(const PGMimageProcessor& rhs)
{
  if(this != &rhs) // Checks to make that we are not performing a self-assignment
   {
   this->row = rhs.row;
   this->col = rhs.col;
   if(this->binary_data != nullptr)
    {
   delete this->binary_data; // 'this' may already be managing a bit of
   // memory so we must release it to prevent any memory leaks.
   this->binary_data = nullptr;
    }
   if(rhs.binary_data != nullptr)
    {
   this->binary_data = new unsigned char(*rhs.binary_data);
    }
 }
 return *this;
}
//Move Constructor
PGMimageProcessor::PGMimageProcessor(PGMimageProcessor && p) 
	: row(p.row)
	, col(p.col)
	,binary_data(p.binary_data)
	{
	p.binary_data = nullptr;
	}
//Move assignment operator
PGMimageProcessor& PGMimageProcessor::operator= (PGMimageProcessor && rhs)
{
	if(this != &rhs) // Checks to make that we are not performing a self-assignment
	{
	this->row = rhs.row;
	this->col = rhs.col;
	if(this->binary_data != nullptr)
	{
	delete this->binary_data; 
	this->binary_data = nullptr;
	}
	if(rhs.binary_data != nullptr)
	{
	this->binary_data = rhs.binary_data;
	rhs.binary_data = nullptr; 
	}
	}	
	return *this;
}
//Accessors
int PGMimageProcessor::getColumn() const
{
    return col;
}
int PGMimageProcessor::getRow() const
{
    return row;
}
//Mutators
void  PGMimageProcessor::setColumn(int col)
{
    this->col = col;
}
void PGMimageProcessor::setRow(int row)
{
    this->row = row;
}
void PGMimageProcessor::readImage(ifstream& infile)
{
	
    if (!infile) {
        cout << "Unable to open file" << endl;
    }
    else {
        cout << "File opened" << endl;
        string line;
        int numrows, numcols;
        int size;
        bool start = false;
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
          unique_ptr<unsigned char[]> buffer(new unsigned char[size]);
          infile.read((char*)buffer.get(), size);
	  infile.close();
            }
        }
    }
}
	
}
