/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 1st 2017
** Description: Function that takes the starting integer as a parameter 
and returns how many steps it takes to reach 1. If that integer is even,
then you divide it by two to get the next integer in the sequence, but 
if it is odd, then you multiply it by three and add one to get the next 
integer in the sequence. 
*********************************************************************/

#include <iostream>
using namespace std;


int hailstone(int x)
{
    int count = 0;

    while (x != 1)
    {
        //if number is even
        if (x % 2 == 0)
        {
            x = (x / 2); 
            count++;
        }
        //if number is odd
        else if (x % 2 ==1)
            {
                x = (x * 3) + 1;
                count++;
            }
        
    }
    return count;
}