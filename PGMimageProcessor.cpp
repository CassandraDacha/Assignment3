#include "PGMimageProcessor.h"

using namespace std;
 namespace DCHCAS001{


//default constructor
PGMimageProcessor::PGMimageProcessor() 
  : row(0)
  , col(0)
  , binary_data(nullptr)
{
}

//Custom constructor
PGMimageProcessor::PGMimageProcessor(int row, int col, unique_ptr<unsigned char[]>  binary_data) 
   :row(row)
   , col(col)
   ,binary_data(move(binary_data))
{
}
//Destructor
PGMimageProcessor::~PGMimageProcessor()
{
   if(binary_data){
         this->binary_data = nullptr;
    }
    this->components.clear();
}

//copy constructor
PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor & p) 
   : row(p.row)
   , col(p.col)
   {
this->binary_data.reset(new unsigned char[col * row]);

for (int i = 0; i < p.row; i++) {
	for (int j = 0; j < p.col; j++) {
	 *(this->binary_data.get() +i*col +j) = *(p.binary_data.get() + i*p.col +j);
	}
}

 for (int i=0; i<p.components.size(); i++){
 unique_ptr<ConnectedComponent> temp(new ConnectedComponent(*(p.components[i])));
	this->components.push_back(move(temp));

}
  }
  //Copy Assignment Operator
PGMimageProcessor& PGMimageProcessor::operator=(const PGMimageProcessor& rhs)
{
  if(this != &rhs) // Checks to make that we are not performing a self-assignment
   {
   this->row = rhs.row;
   this->col = rhs.col;
   this->binary_data.reset(new unsigned char[col * row]);
   for (int i = 0; i < rhs.row; i++) {
	for (int j = 0; j < rhs.col; j++) {
	 *(this->binary_data.get() +i*col +j) = *(rhs.binary_data.get() + i*rhs.col +j);
	}
 }
 if(this->components.size()!=0){
 	this->components.clear();

 for (int i=0; i<rhs.components.size(); i++){
  unique_ptr<ConnectedComponent> temp(new ConnectedComponent(*(rhs.components[i])));
	this->components.push_back(move(temp));
}
 }
 }
 return *this;
}
//Move Constructor
PGMimageProcessor::PGMimageProcessor(PGMimageProcessor && p) 
	: row(p.row)
	, col(p.col)
	,binary_data(move(p.binary_data))
	{
	
	for (int i=0; i<p.components.size(); i++){
		this->components.push_back(move(p.components[i]));
	}
	p.components.clear();
	p.binary_data.reset(nullptr);
	p.row = 0;
	p.col = 0;
	}
//Move assignment operator
PGMimageProcessor& PGMimageProcessor::operator= (PGMimageProcessor && rhs)
{
	if(this != &rhs) // Checks to make that we are not performing a self-assignment
	{
	this->row = rhs.row;
	this->col = rhs.col;
	 
	for (int i=0; i<rhs.components.size(); i++){
		this->components.push_back(move(rhs.components[i]));
	}
	this->binary_data.reset(new unsigned char[col * row]);
	this->binary_data = move(rhs.binary_data);
	rhs.binary_data.reset(nullptr);
	rhs.row = 0;
	rhs.col = 0;
	rhs.components.clear();
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
void PGMimageProcessor::readImage(string filename)
{
ifstream infile;
 infile.open(filename,ios::binary);
	
    if (!infile) {
        cout << "Unable to open file" << endl;
    }
    else {
        cout << "File opened" << endl;
        string line;
        int size;
        bool start = false;
           while (getline(infile, line)) {

            if (line != "P5" && line != "255" && line.at(0) != '#') {
                stringstream ss(line);
                if (start == false) {
                    ss >> row;
                    ss >> col;
                    cout << row << " is " << col << endl;
                    size = row * col;
                    
                    start = true;
                }    
          getline(infile, line); 
           cout << line << endl;
          this->binary_data.reset(new unsigned char[size]);
          infile.read((char*)this->binary_data.get(), size);
	  infile.close();
            }
        }
    }
}
//other methods

/* process the input image to extract all the connected components,
based on the supplied threshold (0...255) and excluding any components
of less than the minValidSize. The final number of components that
you store in your container (after discarding undersized one)
must be returned.
*/
int PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){



for (int i = 0; i < this->row; i++) {
	for (int j = 0; j < this->col; j++) {
	   if(*(this->binary_data.get() +i*col +j) > threshold){
	   ConnectedComponent Comp;
	   queue<pair<int, int>> visit;
	   	visit.push(make_pair(i,j));
	   while(!visit.empty())
	   {
	   	pair<int,int> s = visit.front();
	   	Comp.setCoordinates(s);
	   	*(this->binary_data.get() +s.first*col +(s.second))=0;
	   	visit.pop();
	   	
		if(*(this->binary_data.get() +s.first*col +(s.second+1))> threshold)
	   	{
	   		visit.push(make_pair(s.first,s.second+1));
	   		*(this->binary_data.get() +s.first*col +(s.second+1)) =0;
	   	}
	   	if(*(this->binary_data.get() +(s.first-1)*col +(s.second)) > threshold)
	   	{
	   		visit.push(make_pair(s.first-1,s.second));
	   		*(this->binary_data.get() +(s.first-1)*col +(s.second))=0;
	   	}
	   	if(*(this->binary_data.get() +(s.first+1)*col +(s.second)) > threshold)
	   	{
	   		visit.push(make_pair(s.first+1,s.second));
	   		*(this->binary_data.get() +(s.first+1)*col +(s.second))  =0;
	   	}
	   	if(*(this->binary_data.get() +(s.first)*col +(s.second-1)) > threshold)
	   	{
	   		visit.push(make_pair(s.first,s.second-1));
	   		*(this->binary_data.get() +(s.first)*col +(s.second-1)) =0;
	   	}
	   }
	   if(Comp.getPixels() > minValidSize){
 	 	unique_ptr<ConnectedComponent> temp(new ConnectedComponent(Comp));   
  		this->components.push_back(move(temp));
 		 }
	   
	   }
}
}

return components.size();
}
/* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.
*/
int PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize)
{

for (auto it = components.begin(); it != components.end(); it++)
{
	if((*(*it)).getPixels() > minSize && (*(*it)).getPixels() < maxSize ){
		components.erase(it);
		it--;
		
	}
}
return components.size();
}
/* create a new PGM file which contains all current components
(255=component pixel, 0 otherwise) and write this to outFileName as a
valid PGM. the return value indicates success of operation
*/
bool PGMimageProcessor::writeComponents(const std::string & outFileName){

	
	int size = row*col;
	 char buffer[size];
	 for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
        		*(buffer + i * col + j)=0;
        		  }
        		 }
       for (auto it = components.begin(); it != components.end(); it++)
       {
       	vector< pair<int,int> > temp = (*(*it)).getCoordinates();
       	
        for (int i = 0; i < temp.size(); i++) {
        	*(buffer + temp[i].first * col + temp[i].second)=255;

        }
       }
	ofstream out;
	out.open(outFileName,ios::binary);
	if (!out) {
        cout << "Unable to open file" << endl;
        return false;
   	 }
	else{
 	cout << "start writing to out file" << endl;
 	cout << "width: " << col << " height: " << row << endl;
	cout << "File size: " << size << endl;
 	out << "P5" << endl;
	out << "#Cassandra" << endl;
 	out << col << " " << row << endl;
 	out << 255 << endl;
	out.write(buffer, size);
 	out.close();
	cout << "out file closed" << endl;
	return true;
	}
}

// return number of pixels in largest component
int PGMimageProcessor::getLargestSize(void) const{
	return components.size();
}
// return number of pixels in smallest component
int PGMimageProcessor::getSmallestSize(void) const{
int minSize = -1;
for (auto it = components.begin(); it != components.end(); it++)
{	
	if(minSize = -1){
		minSize = (*(*it)).getPixels();
	}
	else if ((*(*it)).getPixels() < minSize ){
		minSize = (*(*it)).getPixels();
		
	}
}
	return minSize;
}
/* print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels
*/
void PGMimageProcessor::printComponentData(const ConnectedComponent & theComponent) const{
	
	cout<<"Component Id is" << theComponent.getId() << " Component pixels are " << theComponent.getPixels() << endl;

}
	
}
