/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 15th, 2017
** Description: Class for point with x and y coordinates
*********************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

class Point                                 //Class Declaration
{
    private:
        double xCoord;                      //the x coordinate in a point (x,y)
        double yCoord;                      //the y coordinate in a point (x,y)
    
    public:
        Point();                            //construtors
        Point(double,double);           

        double getXCoord();                 //getters
        double getYCoord();       

        void setXCoord(double);             //setters
        void setYCoord(double);                     

        double distanceTo(const Point&);           //function that calculates and 
};                                          //returns the distance between the points

#endif