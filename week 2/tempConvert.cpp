/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 18th 2017
** Description: This program will convert celsius temperatures to fahrenheit temperatures
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    double celsius;
    double fahrenheit;

//To ask user for a temperature in celsius
    cout << "Please enter a Celcius temperature.";
    cin >> celsius;

//To convert the celsius temperature into farenheit
    fahrenheit = ((9.0/5.0 * celsius) + 32.0);
    cout << "\nThe equivalent Fahrenheit temperature is:\n ";
    cout << fahrenheit;
return 0;
}