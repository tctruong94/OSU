/*********************************************************************
** Author:  Thanhbinh(Michael) Truong
** Date: March 1st, 2017
** Description: that takes two parameters - an array of pointers to Students 
** and the size of the array - and returns the standard deviation for the student scores.
*********************************************************************/

#include <iostream>
#include <cmath>
#include "Student.hpp"

using namespace std;

double stdDev(Student *students[], int size);               //function prototype


double stdDev(Student *students[], int size)                //function declaration
{    
    int i;           
    double total = 0.0,
            average = 0.0,
            standardDev = 0.0;

    for(i = 0; i < size; ++i)
    {
        total += students[i] -> getScore();
    }

    average = total / size;

    for(i = 0; i < size; ++i)
    {
        standardDev += pow(students[i]->getScore() - average, 2);
    }

    return sqrt(standardDev/size);
}


int main()
{
   Student *student1 = new Student("Michael", 69.69);            //creating objects for Student
   Student *student2 = new Student("Jonathon", 88.77);
   Student *student3 = new Student("Connor", 46.31);
   Student *student4 = new Student("Kiyoshi", 90.49);

   Student *totalStudents[] = {student1, student2, student3, student4};

   double stanDev = stdDev(totalStudents, 4);                        //uses stdDev function

   cout << "The standard deviation is: " << stanDev <<endl;

   return 0;
}




