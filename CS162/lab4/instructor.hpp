#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>

#include "people.hpp"

class Instructor: public People
{
    private:
    double rating;

    public:
    void setRating();
    void doWork();
    void display();

};

#endif