#define CATCH_CONFIG_MAIN // This tells catch to provide a main() function.

#include "catch.hpp"
#include "ConnectedComponent.h"
#include "PGMimageProcessor.h"

using namespace std;

namespace DCHCAS001{

TEST_CASE("MOVE & COPY SEMANTICS","[MOVE COPY]")
{
     
    /*Initializing binary data*/ 
    unsigned char* data = new unsigned char[15]{0,1,255,12,4,5,10,255,0,1,6,9,22,33,150};
    PGMimageProcessor Image1(1,4,nullptr);
    PGMimageProcessor Image2(0,5,nullptr);
    Image1.getData().reset(data);
    
     vector< pair <int,int> > vect;
     vector< pair <int,int> > vect1;
     vector< pair <int,int> > vect2;
     vector< pair <int,int> > vect3;
    int arr[] = {5, 20, 10, 40 ,60,5,4,3,2,1};
    int arr1[] = {30, 60, 20, 50,20,2,4,6,8,10};
    int arr2[] = {0, 6, 2, 5,2,20,40,60,80,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        vect.push_back( make_pair(arr[i],arr1[i]) );
        vect1.push_back( make_pair(arr1[i],arr[i]));
        vect2.push_back( make_pair(arr2[i],arr1[i])); 
        vect3.push_back( make_pair(arr1[i],arr2[i])); 
        
        }
    /*Declaring and Initializing ConnectedComponent objects*/ 
    ConnectedComponent Comp1(40,vect);
    ConnectedComponent Comp2(70,vect1);
    ConnectedComponent Comp3(55,vect2);
    ConnectedComponent Comp4(170,vect3);
    ConnectedComponent Comp5;
    
    /*Wrapping Connected component objects with unique pointers*/ 
    unique_ptr<ConnectedComponent> Temp1(new ConnectedComponent(Comp1));
    unique_ptr<ConnectedComponent> Temp2(new ConnectedComponent(Comp2));
    unique_ptr<ConnectedComponent> Temp3(new ConnectedComponent(Comp3));
    unique_ptr<ConnectedComponent> Temp4(new ConnectedComponent(Comp4));
    unique_ptr<ConnectedComponent> Temp5(new ConnectedComponent(Comp5));
    
    /*Initializing container of unique pointers of ConnnectedComponent objects*/ 
    vector<unique_ptr<ConnectedComponent>> ConnectedVec;
    ConnectedVec.push_back(move(Temp1));
    ConnectedVec.push_back(move(Temp2));
    ConnectedVec.push_back(move(Temp3));
    ConnectedVec.push_back(move(Temp4));
    ConnectedVec.push_back(move(Temp5));
   
      SECTION("PRE CONDITION Comp1","[ReturnValue]"){
      
        REQUIRE(Comp1.getData()[0]==0);
        REQUIRE(Comp1.getData()[1]==1);
        REQUIRE(Comp1.getData()[2]==255);
        REQUIRE(Comp1.getData()[3]==12;
        REQUIRE(Comp1.getData()[4]==4);
    }
   /* SECTION("COPY CONSTRUCTOR","[ConnectedComponent Comp3 = Comp1]"){
     	ConnectedComponent Comp3 = Comp1;
     	REQUIRE(Comp3.getId()!= Comp1.getId());
        REQUIRE(Comp1.getCoordinates()[5].first==5);
        REQUIRE(Comp3.getCoordinates()[6].second==4);
        REQUIRE(Comp3.getCoordinates()[7].first==3);
        REQUIRE(Comp3.getCoordinates()[8].first==2);
        REQUIRE(Comp3.getCoordinates()[9].second==10);
    }
      SECTION("COPY ASSIGNMENT","[Comp2 = Comp1]"){
        Comp2 = Comp1;
        REQUIRE(Comp1.getCoordinates().size()!=0);
        //REQUIRE(Comp2.getId()==1);
        REQUIRE(Comp2.getId()!= Comp1.getId());
        REQUIRE(Comp2.getPixels()== Comp1.getPixels());
        REQUIRE(Comp2.getCoordinates()[5].first==5);
        REQUIRE(Comp2.getCoordinates()[6].second==4);
        REQUIRE(Comp2.getCoordinates()[7].first==3);
        REQUIRE(Comp2.getCoordinates()[8].first==2);
        REQUIRE(Comp2.getCoordinates()[9].second==10);

    }
    SECTION("MOVE CONSTRUCTOR","[ConnectedComponent Comp3 = std::move(Comp1)]"){
     	ConnectedComponent Comp3 = move(Comp1);
     	REQUIRE(Comp1.getCoordinates().size()==0);
        REQUIRE(Comp3.getCoordinates()[5].first==5);
        REQUIRE(Comp3.getCoordinates()[6].second==4);
        REQUIRE(Comp3.getCoordinates()[7].first==3);
        REQUIRE(Comp3.getCoordinates()[8].first==2);
        REQUIRE(Comp3.getCoordinates()[9].second==10);
}
  SECTION("MOVE ASSIGNMENT","[ConnectedComponent Comp2 = std::move(Comp1)]"){
     	ConnectedComponent Comp2 = move(Comp1);
     	REQUIRE(Comp1.getCoordinates().size()==0);
        REQUIRE(Comp2.getCoordinates()[5].first==5);
        REQUIRE(Comp2.getCoordinates()[6].second==4);
        REQUIRE(Comp2.getCoordinates()[7].first==3);
        REQUIRE(Comp2.getCoordinates()[8].first==2);
        REQUIRE(Comp2.getCoordinates()[9].second==10);
}*/

}
}
