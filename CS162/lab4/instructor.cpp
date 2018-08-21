#include <iostream>
#include <cmath>
#include <cstdlib>

#include "instructor.hpp"
#include "people.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


void Instructor::setRating()                //generate random rating for instructor from 0.0-5.0
{
rating = (rand() % 50) / 10.0;
}

void Instructor::doWork()                   //generate random hours worked on grading from 0-40 hours
{
    int h;
    h = rand() % 40 + 1;

    cout << "Instructor " << name << " graded homework for " << h << " hours." << endl << endl;
}


void Instructor::display()                  //display instructor's name, age and rating 
{
    cout << "Instructor's Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Instructor Rating: " << rating << endl;
}
