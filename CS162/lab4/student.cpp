#include <iostream>
#include <cmath>
#include <cstdlib>

#include "student.hpp"
#include "people.hpp"

using std::cout;
using std::cin;
using std::endl;

void Student::setGPA()                      //generate random gpa from 0.0-4.0 for student
{
    double x = (rand() % 41) / 10.0;
    gpa = x;
}

void Student::doWork()                      //generate random hours student worked on homework from 0-40 hours
{
    int h;
    h = rand() % 40 + 1;

    cout << name << " did " << h << " hours of homework." << endl << endl;
}

void Student::display()                     //display the name, gpa and number of hours worked on homework for student
{
    cout << "Student name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
}