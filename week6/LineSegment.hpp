/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 15th, 2017
** Description: Implementation of Point class
*********************************************************************/

#include <iostream>
#include <math.h>
#include "Point.hpp"

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP


class LineSegment                           //Class Declaration
{
    private:
        Point p1;                     
        Point p2;

    public:
        LineSegment();                      //constructors
        LineSegment(Point, Point);

        void setEnd1(double, double);                //setters
        void setEnd2(double, double);

        Point getEnd1();                    //getters
        Point getEnd2();

        double length();                    //functions
        double slope();
};

#endif