#include "ant.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Ant::Ant()
{

}

Ant::Ant(int a, int b)
{
    setDirection(south);
    setSpace(' ');

    setRow1(a);
    setRow2(a);
    
    setColumn1(b);
    setColumn2(b);
}

void Ant::setDirection(Direction a)
{
    dir = a;
}

void Ant::setSpace(char c)
{
    space = c;
}

void Ant::setRow1(int r)
{
    row1 = r;
}

void Ant::setColumn1(int c)
{
    column1 = c;
}

void Ant::setRow2(int r2)
{
    row2 = r2;
}

void Ant::setColumn2(int c2)
{
    column2 = c2;
}

Direction Ant::getDirection()
{
    return dir;
}

char Ant::getSpace()
{
    return space;
}

int Ant::getRow1()
{
    return row1;
}

int Ant::getColumn1()
{
    return column1;
}

int Ant::getRow2()
{
    return row2;
}

int Ant::getColumn2()
{
    return column2;
}
