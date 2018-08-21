/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 1st 2017
** Description: 
*********************************************************************/

#include <iostream>
using namespace std;

void smallSort(int &x,int &y, int &z)
{
    int num, num1, num2;

//swap the first two numbers if they aren't in order
    if (x>y)
    {
        x = y;
        y = num;
    }

//compare second number with third; swap if needed
    if (y > z)
    {
        num1 = y;
        y = z;
        z = num1;
    }

//compare first with the final second number; swap if needed
    if (x > y)
    {
        num2 = x;
        x = y;
        y = num2;
    }
}