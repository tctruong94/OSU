/*********************************************************************
** Author:  Thanhbinh(Michael) Truong
** Date: March 1st, 2017
** Description:  A Void Function, smallSort2, that takes as parameters the addresses of 
** three int variables and sorts the ints at those addresses into ascending order
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

void smallSort2(int *point1, int *point2, int *point3)
{
   int holder;
    if (*point1 > *point2)
    {
        holder = *point1;
        *point1 = *point2;
        *point2 = holder;
    }

    if (*point1 > *point3)
    {
        holder = *point1;
        *point1 = *point3;
        *point3 = holder;
    }

    if (*point2 > *point3)
    {
        holder = *point3;
        *point3 = *point2;
        *point2 = holder;
    }
}


int main()
{
    int a = 50,
        b = -6,
        c = 100;

    smallSort2(&a, &b, &c);

    cout << a << ", " << b << ", " << c << endl;

    return 0;
}
