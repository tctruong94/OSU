#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "people.hpp"

class Student: public People
{
    private:
    double gpa;

    public:
    void setGPA();
    void doWork();
    void display();

};

#endif