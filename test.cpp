#define CATCH_CONFIG_MAIN // This tells catch to provide a main() function.

#include "catch.hpp"
#include "ConnectedComponent.h"
#include "PGMimageProcessor.h"

using namespace std;

namespace DCHCAS001{

TEST_CASE("MOVE & COPY SEMANTICS","[MOVE COPY]")
{
   vector< pair <int,int> > vect;
    vector< pair <int,int> > vect1;
    int arr[] = {5, 20, 10, 40 ,60,5,4,3,2,1};
    int arr1[] = {30, 60, 20, 50,20,2,4,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        vect.push_back( make_pair(arr[i],arr1[i]) );
        vect1.push_back( make_pair(arr1[i],arr[i]) );
        }
    ConnectedComponent Comp1(40,vect);
    ConnectedComponent Comp2(70,vect1);
   
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
TEST_CASE("MOVE & COPY SEMANTICS[MOVE COPY]")
{
  PGMimageProcessor Image1;
  Image1.readImage("chess-thresh.pgm");
  Image1.extractComponents(100,7000);
  Image1.writeComponents("./test/image.pgm");
 
    SECTION("COPY CONSTRUCTOR","[ConnectedComponent Image3 = Image1]"){
     	PGMimageProcessor Image3(Image1);
     	REQUIRE(Image1. getComponentCount()==Image3. getComponentCount());
        REQUIRE(Image1.getSmallestSize()== Image3.getSmallestSize());
        REQUIRE(Image1.getLargestSize()==Image3.getLargestSize());
    }
      SECTION("COPY ASSIGNMENT","[Image2 = Image1]"){
        PGMimageProcessor Image2 = Image1;
        REQUIRE(Image1.getComponentCount()==Image2.getComponentCount());
        REQUIRE(Image1.getSmallestSize()== Image2.getSmallestSize());
        REQUIRE(Image1.getLargestSize()==Image2.getLargestSize());

    }
    SECTION("MOVE CONSTRUCTOR","[PGMimageProcessor Image3(move(Image1))]"){
     	PGMimageProcessor Image3(move(Image1));
     	REQUIRE(Image1.getComponentCount()==0);
     	REQUIRE(Image1.getData()==nullptr);
     	REQUIRE(Image3.getRow() != Image1.getRow() );
        REQUIRE(Image3.getColumn() != Image1.getColumn());
        REQUIRE(Image3.getRow() == 252);
        REQUIRE(Image3.getColumn() == 609);
}
  SECTION("MOVE ASSIGNMENT","[ConnectedComponent Image2 = move(Image1)]"){
     	PGMimageProcessor Image2 = move(Image1);
     	REQUIRE(Image1.getComponentCount()==0);
     	REQUIRE(Image1.getData()==nullptr);
     	REQUIRE(Image2.getRow() != Image1.getRow() );
        REQUIRE(Image2.getColumn() != Image1.getColumn());
        REQUIRE(Image2.getRow() == 252);
        REQUIRE(Image2.getColumn() == 609);
        REQUIRE(Image2.getComponentCount() == 3);
}

}
TEST_CASE("ExtractComponents Function Test")
{
	PGMimageProcessor Image1, Image2,Image3;
	Image1.readImage("chess-thresh.pgm");
	Image2.readImage("chess-thresh.pgm");
	Image3.readImage("chess-thresh.pgm");
  	REQUIRE(Image1.extractComponents(100,7000) == 3);
  	REQUIRE(Image2.extractComponents(200,4000) == 6);
  	REQUIRE(Image3.extractComponents(300,8000)== 1);	
  	
}
TEST_CASE("FilterComponentsBySize Function Test")
{
	PGMimageProcessor Image1, Image2,Image3;
	Image1.readImage("chess-thresh.pgm");
	Image2.readImage("chess-thresh.pgm");
	Image3.readImage("chess-thresh.pgm");
	Image1.extractComponents(100,7000);
	Image2.extractComponents(200,4000);
	Image3.extractComponents(300,8000);
  	REQUIRE(Image1.filterComponentsBySize(0,9000) == 3);
  	REQUIRE(Image2.filterComponentsBySize(0,6000) == 2);
  	REQUIRE(Image3.filterComponentsBySize(0,8000)== 0);	
  	
}
TEST_CASE("WriteComponents Function Test")
{
	PGMimageProcessor Image1, Image2,Image3;
	Image1.readImage("chess-thresh.pgm");
	Image2.readImage("chess-thresh.pgm");
	Image3.readImage("chess-thresh.pgm");
	Image1.extractComponents(100,7000);
	Image2.extractComponents(200,4000);
	Image3.extractComponents(300,8000);
  	REQUIRE(Image1.writeComponents("./test/out.pgm") == true);
  	REQUIRE(Image2.writeComponents("./test/out2.pgm") == true);
  	REQUIRE(Image3.writeComponents("./test/out3.pgm")== true);	
  	
}

}
