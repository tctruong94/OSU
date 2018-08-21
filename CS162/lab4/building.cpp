#include <iostream>
#include "university.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Building::Building()                            //default constructor
{

}

Building::~Building()                           //default destructor
{

}

void Building::setBuildingName(string name)     //set name of building
{
    buildingName = name;
}

void Building::setBuildingSize(int size)        //set size (sqft) of building
{
    buildingSize = size;
}

void Building::setBuildingAddress(string address)   //set address of building
{
    buildingAddress = address;
}

void Building::displayBuilding()                    //display building name, size, and address
{
    cout << endl << "Building Name: " << buildingName << endl;
    cout << "Building Size: " << buildingSize << "sqft " << endl;
    cout << "Building Address: " << buildingAddress << endl;
}