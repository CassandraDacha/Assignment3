
#include "ConnectedComponent.h"
using namespace std;

namespace DCHCAS001{
//Default constructor
ConnectedComponent::ConnectedComponent()
	{
	next = 0;
	}
//Destructor
ConnectedComponent::~ConnectedComponent()
{
}
//Custom constructor
ConnectedComponent::ConnectedComponent(int pixels,vector< pair<int,int> > coordinates)
	:pixels(pixels),
	,coordinates(coordinates)
	,id(next)
	{
	next++;
	}
//Copy constructor
ConnectedComponent::ConnectedComponent(const ConnectedComponent& other):
	:pixels(other.pixels)
	,id(next)
{
next++;

 for (int i=0; i<other.size(); i++){
 	this->coordinates.push_back(make_pair(other.coordinates[i].first,other.coordinates[i].second))
 }
}
//Copy Assignment operator
ConnectedComponent::ConnectedComponent& operator=(ConnectedComponent& other)
{
 if (this!= &other)
 {
 this->pixels = other.pixels;
 next++;
 for (int i=0; i<other.size(); i++){
 	this->coordinates.push_back(make_pair(other.coordinates[i].first,other.coordinates[i].second))
 }
 }
}

//Move constructor
ConnectedComponent::ConnectedComponent(ConnectedComponent&& other)
	:pixels(pixels),
	,coordinates(coordinates)
	,id(other.id)
{
other.id = -1;
}
//Move assignment operator
ConnectedComponent::ConnectedComponent& operator=(ConnectedComponent&& other)
{
if (this!= &other){
  this->pixels = other.pixels;
  this->id = other.id;
  other.id = -1;
   for (int i=0; i<other.size(); i++){
 	this->coordinates.push_back(make_pair(other.coordinates[i].first,other.coordinates[i].second))
 other.coordinates.clear();
}
}
}
//Accessors
int getPixels() const
{
	return pixels;
}
int getId() const
{
	return id;
}
vector< pair<int,int> > getCoordinates()
{
	return coordinates;
}
//Mutators
void setPixels(int pixels) const
{
	this->pixels = pixels;
}
void setId(int id) const
{
	this->id = id;
}
}

}
