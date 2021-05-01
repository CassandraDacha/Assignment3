
#include "ConnectedComponent.h"
using namespace std;

namespace DCHCAS001{

int ConnectedComponent:: next = 0;
//Default constructor
ConnectedComponent::ConnectedComponent():
	id(next)
	{
	next++;
	}
//Destructor
ConnectedComponent::~ConnectedComponent()
{
}
//Custom constructor
ConnectedComponent::ConnectedComponent(int pixels,vector< pair<int,int> > coordinates)
	:pixels(pixels)
	,coordinates(coordinates)
	,id(next)
	{
	next++;
	}
//Copy constructor
ConnectedComponent::ConnectedComponent(const ConnectedComponent& other)
	:pixels(other.pixels)
	,id(next)
{
next++;

 for (int i=0; i<other.coordinates.size(); i++){
 	this->coordinates.push_back(make_pair(other.coordinates[i].first,other.coordinates[i].second));
 }
}
//Copy Assignment operator
ConnectedComponent& ConnectedComponent::operator=(const ConnectedComponent& other)
{
 if (this!= &other)
 {
 this->pixels = other.pixels;
 this->id = next;
 next++;
 if(this->coordinates.size()!=0){
 	this->coordinates.clear();
 for (int i=0; i<other.coordinates.size(); i++){
 	this->coordinates.push_back(make_pair(other.coordinates[i].first,other.coordinates[i].second));
 }
 }
 }
 return *this;
}

//Move constructor
ConnectedComponent::ConnectedComponent(ConnectedComponent&& other)
	:pixels(other.pixels)
	,coordinates(other.coordinates)
	,id(other.id)
{
	other.id = -1;
	other.pixels = 0;
	other.coordinates.clear();
}
//Move assignment operator
ConnectedComponent& ConnectedComponent::operator=(ConnectedComponent&& other)
{
if (this!= &other){
  this->pixels = other.pixels;
  this->id = other.id;
  other.id = -1;
  this->coordinates = other.coordinates;
  other.coordinates.clear();
}
return *this;
}
//Accessors
int ConnectedComponent::getPixels() const
{
	return pixels;
}
int ConnectedComponent::getId() const
{
	return id;
}
vector< pair<int,int> > ConnectedComponent::getCoordinates()
{
	return coordinates;
}
//Mutators
void ConnectedComponent::setPixels(int pixels)
{
	this->pixels = pixels;
}
void ConnectedComponent::setId(int id)
{
	this->id = id;
}
void ConnectedComponent::setCoordinates(pair <int,int> num)
{
	coordinates.push_back(num);
	this->pixels++;
}
}

