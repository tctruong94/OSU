#include <iostream>
#include <string>
#include "Matrix.hpp"

using namespace std;

/*********************************
**Function: readMatrix
**Description: It will prompt the user to fill a square matrix 
and store the input into the 2D array. 
*********************************/

void readMatrix(int** matrix, int size)
{
   for (int row = 0; row < size; row++)
   {
       for (int column = 0; column < size; column++)
       {
           cout << "Enter value for row " << row+1 << ", column " << column+1 << ": ";
           cin >> matrix[row][column];
       }
   }
}