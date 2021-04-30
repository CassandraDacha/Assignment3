#define CATCH_CONFIG_MAIN // This tells catch to provide a main() function.

#include "catch.hpp"
#include "ConnectedComponent.h"

using namespace std;

namespace DCHCAS001{

TEST_CASE("MOVE & COPY SEMANTICS","[MOVE COPY]")
{
    vector< pair <int,int> > vect;
    int arr[] = {5, 20, 10, 40 ,60,5,4,3,2,1};
    int arr1[] = {30, 60, 20, 50,20,2,4,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        vect.push_back( make_pair(arr[i],arr1[i]) );
        }
    ConnectedComponent Comp1(40,vect);
    ConnectedComponent Comp2(70,vect);
   // ConnectedComponent Comp2();
   
      SECTION("PRE CONDITION Comp1","[ReturnValue]"){
      
        REQUIRE(Comp1.getCoordinates()[0].first==5);
        REQUIRE(Comp1.getCoordinates()[1].second==60);
        REQUIRE(Comp1.getCoordinates()[2].first==10);
        REQUIRE(Comp1.getCoordinates()[3].first==40);
        REQUIRE(Comp1.getCoordinates()[4].second==20);
    }
    SECTION("COPY CONSTRUCTOR","[ConnectedComponent Comp3 = Comp1]"){
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
}

}
}
