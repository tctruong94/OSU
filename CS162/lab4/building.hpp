#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>

using std::string;

class Building
{
    private:
    string buildingName;
    string buildingAddress;
    int buildingSize;

    public:
    Building();
    ~Building();

    void setBuildingName(string name);              //to set the name of building
    void setBuildingSize (int size);                //set the sqft of building
    void setBuildingAddress(string address);        //set the address of the building
    void displayBuilding();                         //display name, size, and address of building

};

#endif