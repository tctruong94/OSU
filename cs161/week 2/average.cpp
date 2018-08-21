/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 18th 2017
** Description: This program will ask user for five numbers and calculate the average
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    double number1;
    double number2;
    double number3;
    double number4;
    double number5;
    int totalNumbers;
    double average;

//Ask the user to input numbers
    cout <<  "Please enter five numbers.";
    cin >> number1;
    cin >> number2;
    cin >> number3;
    cin >> number4;
    cin >> number5;
    cout << "\nThe average of those number is:\n ";

//Calculate and output the average of the five numbers
totalNumbers = 5;
average = (number1 + number2 + number3 + number4 + number5) / totalNumbers;
cout << average;
return 0;
}