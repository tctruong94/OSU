/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 18th 2017
** Description: Will compute the fewest number of coins returned given a number from 0 to 99
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int cents;
    int change1;
    int change2;
    int change3;
    const int q = 25;
    const int n = 10;
    const int d = 5;
    const int p = 1;

    cout << "Please enter an amount in cents less than a dollar.";
    cin >> cents;
    cout << "\nYour change will be:\n ";

//To calculate the amount of change in quarters,dimes,nickels and pennies
    quarters = cents / q;
    change1 = cents % q;
    dimes = change1 / d;
    change2 = cents % d;
    nickels = change2 / n;
    change3 = change2 % n;
    pennies = change3;

//To display the results
cout << "Q: " << quarters << "\n";
cout << "D: " << dimes << "\n";
cout << "N: " << nickels << "\n";
cout << "P: " << pennies << "\n";
return 0;
}