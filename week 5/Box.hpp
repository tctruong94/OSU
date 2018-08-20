/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 8th, 2017
** Description: Header file for Box
*********************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

class Box
{
    private:
        double width;
        double length;
        double height;
    
    public:
        Box();                          //Constructor
        Box(double, double, double);

        double getWidth();              //getter
        double getLength();
        double getHeight();

        void setWidth(double);          //setter
        void setLength(double);
        void setHeight(double);

        double getVolume();             //functions
        double getSurfaceArea();
};

#endif