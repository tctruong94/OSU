/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 25th 2017
** Description: Program that prompts user to enter number of integers to read,
** inputs those integers and displays the minimum and maximum.
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{
    //declare integer variables
    int min,
        max,
        numberOfIntegers,
        value;
    
    //prompts user to enter number of integers that will be entered
    cout<<"How many integers would you like to enter?" << endl;
    cin>>numberOfIntegers;

    //prompts user to enter integers
    cout<<"Please enter " << numberOfIntegers << " integers." << endl;
    cin>>value;

    //preset min and maximum to first value entered
    min = max = value;

    //iterate between each value to compare against one another for min/max
    for(int i = 1; i < numberOfIntegers; i++)
    {
        //prompts for user's input
        cin>>value;

        //compare value against minimum
        if(value<min)
            min = value;

        //compare value against maximum
        if(value>max)
            max = value;
    }
    //print out the minimum and maximum integer
    cout<<"min: " << min << endl;
    cout<<"max: " << max << endl;
    return 0;
}