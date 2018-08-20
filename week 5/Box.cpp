/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 8th, 2017
** Description: .cpp file for Box
*********************************************************************/

#include <iostream>
#include "Box.hpp"

using namespace std;

/***********************************************
Name: Box::Box()
Description: Default Constructor
************************************************/

Box::Box()
{
    width = 1.0;
    length = 1.0;
    height = 1.0;
}


/***********************************************
Name: Box::Box()
Description: constructor for 3 parameters
************************************************/

Box::Box(double l, double w, double h)
{
    setLength(l);
    setWidth(w);
    setHeight(h);
}

/***********************************************
Name: Box::getWidth()
Description: returns width of object
************************************************/

double Box::getWidth()
{
    return width;
}


/***********************************************
Name: Box::getLength()
Description: returns Length of object
************************************************/
double Box::getLength()
{
    return length;
}

/***********************************************
Name: Box::getHeight()
Description: returns Height of object
************************************************/

double Box:: getHeight()
{
    return height;
}


/***********************************************
Name: Box::setWidth()
Description: sets width of object
************************************************/

void Box:: setWidth(double w)
{
    width = w;
}


/***********************************************
Name: Box::setLength()
Description: sets length of object
************************************************/
void Box::setLength(double l)
{
    length = l;
}


/***********************************************
Name: Box::setHeight()
Description: sets Height of object
************************************************/

void Box::setHeight(double h)
{
    height = h;
}

/***********************************************
Name: Box::getVolume()
Description: gets object voljume
************************************************/
double Box::getVolume()
{
    return length * width * height;
}

/***********************************************
Name: Box::getSurfaceArea()
Description: gets object surface area
************************************************/
double Box:: getSurfaceArea()
{
    return 2 * ((width * length) + (height * length) + (height * width));
}

/*

int main () 
{

	Box box1(2.4, 7.1, 5.0);
	Box box2;
	double volume1 = box1.getVolume();
	double surfaceArea1 = box1.getSurfaceArea();
	double volume2 = box2.getVolume();
	double surfaceArea2 = box2.getSurfaceArea();

    cout << volume1 << endl;
    cout << volume2 << endl;

    cout << surfaceArea1 << endl;
    cout << surfaceArea2 << endl;

    return 0;
}

*/