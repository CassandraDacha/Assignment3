#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

namespace DCHCAS001{

class ConnectedComponent{
private:
    int id,pixels;
    static int next;
    std::vector< std::pair<int,int> > coordinates;
public:
	//Default constructor
	ConnectedComponent();
	//Destructor
	~ConnectedComponent();
	//Custom constructor
	ConnectedComponent(int pixels,int id,vector< pair<int,int> > coordinates);
	//Copy constructor
	ConnectedComponent(ConnectedComponent& other);
	//Copy Assignment operator
	ConnectedComponent& operator=(ConnectedComponent& other);
	//Move constructor
	ConnectedComponent(ConnectedComponent&& other);
	//Move assignment operator
	ConnectedComponent& operator=(ConnectedComponent&& other);
	int getPixels() const;
	int getId() const;
	vector< pair<int,int> > getCoordinates();
	//Mutators
	void setPixels(int pixels) const;
	void setId(int id) const;
}

}
