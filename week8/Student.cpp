/*********************************************************************
** Author:  Thanhbinh(Michael) Truong
** Date: March 1st, 2017
** Description:  Declaration of Student's functions
*********************************************************************/

#include <string>
#include "Student.hpp"
using namespace std;

Student::Student(string n, double s)
{
   name = n;
   score = s;
}

string Student::getName()
{
   return name;
}

double Student::getScore()
{
   return score;
}