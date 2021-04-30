#define CATCH_CONFIG_MAIN // This tells catch to provide a main() function.

#include "catch.hpp"
#include "ConnectedComponent.h"

using namespace std;

namespace DCHCAS001{

TEST_CASE("MOVE & COPY SEMANTICS","[MOVE COPY]")
{
    vector< pair <int,int> > vect;
    int arr[] = {5, 20, 10, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        vect.push_back( make_pair(arr[i],arr1[i]));
        }
    ConnectedComponent Comp1(40,vect);
    ConnectedComponent Comp2(70,vect);
   
    SECTION("PRE CONDITION image1","[ReturnValue]"){
    	//ConnectedComponent Comp3 = Comp1;
 
        REQUIRE(Comp1.getCoordinates()[0].first==1);
        REQUIRE(Comp1.getCoordinates()[1].second==2);
        REQUIRE(Comp1.getCoordinates()[2].first==3);
        REQUIRE(Comp1.getCoordinates()[3].first==4);
        REQUIRE(Comp1.getCoordinates()[4].second==2);
    }
    /* SECTION("COPY CONSTRUCTOR","[ConnectedComponent Comp3 = Comp1]"){
     	
        REQUIRE(Comp1.getCoordinates()[0].first==1);
        REQUIRE(Comp1.getCoordinates()[1].second==2);
        REQUIRE(Comp1.getCoordinates()[2].first==3);
        REQUIRE(Comp1.getCoordinates()[3].first==4);
        REQUIRE(Comp1.getCoordinates()[4].second==2);
    }*/

}

}
