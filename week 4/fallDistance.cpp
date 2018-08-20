#include <iostream>
#include <cmath>
using namespace std;

/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 1st 2017
** Description: Function will takes time in seconds for object to fall 
and convert it into distance in meters that the object has fallen.
*********************************************************************/

double fallingDistance(double time)
{
    double distance;
    const double GRAVITY = 9.8;

    seconds = time;
    
//convert seconds to distance in meters
    distance = 0.5 * GRAVITY * pow(seconds,2);

    return distance;
}

