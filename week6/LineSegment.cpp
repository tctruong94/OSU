/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 15th, 2017
** Description: class for LineSegment that calculates length and slope
*********************************************************************/

#include <iostream>
#include <math.h>
#include "LineSegment.hpp"

using namespace std;

/***********************************************
Name: LineSegment::LineSegment()
Description: constructor for LineSegment
************************************************/

LineSegment::LineSegment(Point point1, Point point2)
{
    setEnd1(point1.getXCoord(), point1.getYCoord());
    setEnd2(point2.getXCoord(), point2.getYCoord());
}

/***********************************************
** name: LineSegment::setEnd1(Point point)
** Description: sets value for end1
************************************************/

void LineSegment:: setEnd1(double xCoord, double yCoord)
{
    p1.setXCoord(xCoord);
    p1.setYCoord(yCoord);
}

/***********************************************
** name: LineSegment::setEnd2(Point point)
** Description: sets value for end2
************************************************/

void LineSegment::setEnd2(double xCoord, double yCoord)
{
    p2.setXCoord(xCoord);
    p2.setYCoord(yCoord);
}

/***********************************************
** name: LineSegment::getEnd1()
** Description: function that returns the current value of end1
************************************************/

Point LineSegment::getEnd1()
{
    return p1;
}


/***********************************************
** name: LineSegment::getEnd2()
** Description: returns current value of end2
************************************************/

Point LineSegment::getEnd2()
{
    return p2;
}

/***********************************************
** name: LineSegment::length()
** Description: Function that calculates and returns the length of LineSegment object
************************************************/

double LineSegment::length()
{
    double distance;

    distance = (p1.distanceTo(p2));
    
    return distance;
}

/***********************************************
** name: LineSegment::slope()
** Description: Function that calculates and returns the slope of LineSegment object
************************************************/

double LineSegment::slope()
{
    double startX = p1.getXCoord();
    double startY = p1.getYCoord();

    double endX = p2.getXCoord();
    double endY = p2.getYCoord();

    double slope = (endY - startY)/(endX - startX);

    return slope;

}

