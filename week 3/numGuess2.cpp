/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 25th 2017
** Description: This program allows the user to enter a number and 
** have someone else attempt to guess the number until he/she is right
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int answer,
        guess,
        attempts = 1;


    //Have the user enter a number to be guessed
    cout << "Enter the number for the player to guess: " << endl;
    cin >> answer;

    //To allow multiple attempts to guess
    do
    {
        //For the player to guess the number
        cout<< "Enter your guess.\n ";
        cin >> guess;

        //If guess is too high
        if(guess>n)
        {
            cout << "Too high - try again.\n";
        }

        //If guess is too low
        else if (guess<n)
        {
            cout<< "Too low - try again.\n";
        }

        //To prompt user how many attempts it took to guess the number
        else
        {
            cout<< "You guessed it in " << attempts << "tries.\n";
            break;
        }
        attempts++;

    while(!(answer==guess));
    }   
    return 0;
}