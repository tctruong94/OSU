/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: January 25th 2017
** Description: Program that prompts user to enter number of integers to read,
** inputs those integers and displays the minimum and maximum.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    //Declare variables, input and output file objects
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    int value;
    double total = 0.0;

    //Prompt user to enter file name
    cout << "Please enter the name of the file: " << endl;
    cin >> fileName;

    //open the input file
    inputFile.open(fileName.c_str());

    //sum up the integers in the file
    if(inputFile)
    { 
        while (inputFile >> value)
            {
                total += value;
            }   
    }
    else
    {
        cout<< "could not access file" << endl;
        return 0;
    }

    //close input file 
    inputFile.close();

    //open output file
    outputFile.open("sum.txt");

    //to write the total sum of integers in file
    outputFile << total;

    //close the file
    outputFile.close();
    return 0;
}

