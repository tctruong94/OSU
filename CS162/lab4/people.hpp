#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <iostream>
#include <string>

using std::string;

class People                                //parent class of student and instructor
{
    protected:
        string name;
        int age;

    public:
        People()
        {
        };
        ~People()
        {
        };

    void setValue (string na, int ag)
    {
        name = na;
        age = ag;
    }

    virtual void doWork() = 0;
    virtual void display() = 0;
};

#endif