#include <iostream>

using namespace std;


/****************************************
**Name:sum
**Description: Sums the numbers in an array
****************************************/
int sum(int arrayValue[], int counterVal)
{
     if (counterVal == 1)
     {
        return arrayValue[0];
     }
     else
     {
         return arrayValue[0] + sum(arrayValue+1,counterVal-1);
     }
}