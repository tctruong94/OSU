#include <iostream>
#include <string>
#include "Matrix.hpp"
#include "Determinant.hpp"

using namespace std;

int main()
{
    int size;
    char choice;
    
    cout << "Select the matrix size by entering 1 or 2: " << endl;
    cout << " 1. 2x2 matrix" << endl;
    cout << " 2. 3x3 matrix" << endl << endl;

    cin >> choice;

    if (choice == '1')          //to validate input
    {
        size = 2;
    }
    else if (choice == '2')
    {
        size = 3;
    }
    else
    {
        cout << "You have entered an invalid choice. " << endl;
        return 0;
    }
    
    int** square = new int*[size];               //to initialize an array to hold the size of the matrix

    for (int i = 0; i < size; i++)
    {
        square[i] = new int[size];
    }
  
  readMatrix(square, size);
  
  int determ = determinant(square, size);
  
  cout << endl << "Matrix: " << endl;
    
    for (int row = 0; row < size; row++)         //prints the matrix values
   {
       for (int col = 0; col < size; col++)
       {
           cout << square[row][col] << "\t";
       }
       cout << "\n";
    }

    for (int i = 0; i < size; i++)               //need to free the dynamically allocated memory
    {
        delete[] square[i];
    }
        delete[] square;
        
        cout << endl << "Determinant: " << determ << endl;
        
        return 0;
}



