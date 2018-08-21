#include <iostream>
#include <string>
#include "Determinant.hpp"

using namespace std;

/*********************************
**Function: determinant
**Description:  It will return an integer value which 
is the determinant of the matrix stored in the 2D array.  
*********************************/

int determinant(int** array, int size)
{

   int calculate;   //Determinant calculation variable

   if (size == 2)                       //calcuate determinant if matrix has size 2x2
   {
       int zero0 = array[0][0];
       int zero1 = array[0][1];
       int one0 = array[1][0];
       int one1 = array[1][1];

   calculate = (zero0*one1) - (zero1*one0);
   }

   else                                 //calculate determinant if matrix has size 3x3
   {
       int zero0 = array[0][0];
       int zero1 = array[0][1];
       int zero2 = array[0][2];
       int one0 = array[1][0];
       int one1 = array[1][1];
       int one2 = array[1][2];
       int two0 = array[2][0];
       int two1 = array[2][1];  
       int two2 = array[2][2];

       calculate = zero0 * (one1 * two2 - one2 * two1) - zero1 
       * (one0 * two2 - one2 * two0) + zero2 * (one0 * two1 - one1 * two0);
   }

   return calculate;
}
