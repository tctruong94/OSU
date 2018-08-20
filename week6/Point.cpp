/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 15th, 2017
** Description: Implementation of Point class
*********************************************************************/

#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/***********************************************
Name: Point::Point()
Description: Default Constructor
************************************************/

Point::Point()
{
    xCoord = 0.0;
    yCoord = 0.0;
}

/***********************************************
Name: Point(double x, double y)
Description: constructor that sets initial values for the 
xCoord and the YCoord
************************************************/

Point::Point(double x, double y)
{
    setXCoord(x);
    setYCoord(y);
}

/***********************************************
Name: Point:: setXCoord(double x)
Description: sets the value for the XCoord
************************************************/

void Point::setXCoord(double x)
{
    xCoord = x;
}

double Point::getXCoord()
{
    return xCoord;
}

/***********************************************
Name: Point::setYCoord(double y)
Description: sets the value for the yCoord
************************************************/

void Point::setYCoord(double y)
{
    yCoord = y;
}

double Point::getYCoord()
{
    return yCoord;
}

/***********************************************
Name: DistanceTo(const Point &other)
Description: A function that calculates the distance between the
current point and another point that is provided.
************************************************/

double Point::distanceTo(const Point& otherPoint)
{
    double x1 = xCoord;
    double y1 = yCoord;

    double endX = otherPoint.xCoord;
    double endY = otherPoint.yCoord;
    double distanceSquared = pow((endX - x1),2) + pow((endY - y1),2); 
    double distance = sqrt(distanceSquared);
    return distance;
}