#ifndef __CONNECTEDCOMPONENTS__
#define __CONNECTEDCOMPONENTS__
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
    std::vector<pair<int,int>> coordinates;
    static int next;
public:
	//Default constructor
	ConnectedComponent();
	//Destructor
	~ConnectedComponent();
	//Custom constructor
	ConnectedComponent(int pixels, vector< pair<int,int> > coordinates);
	//Copy constructor
	ConnectedComponent(const ConnectedComponent& other);
	//Copy Assignment operator
	ConnectedComponent& operator=(const ConnectedComponent& other);
	//Move constructor
	ConnectedComponent(ConnectedComponent&& other);
	//Move assignment operator
	ConnectedComponent& operator=(ConnectedComponent&& other);
	int getPixels() const;
	int getId() const;
	vector< pair<int,int> > getCoordinates();
	//Mutators
	void setPixels(int pixels);
	void setId(int id);
};

}
#endif
