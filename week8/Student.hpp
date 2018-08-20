/*********************************************************************
** Author:  Thanhbinh(Michael) Truong
** Date: March 1st, 2017
** Description:  Class declaration of Student
*********************************************************************/

#include <string>
using namespace std;

class Student
{ private:
   string name;                        //private members
   double score;

 public:
   Student(string n, double s);        // constructor
   string getName();                   // getter
   double getScore();                  // getter
};