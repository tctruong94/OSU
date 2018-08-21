#include "Die.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

Die::Die(int s)                                 //Constructor
{
    num_sides = s;
}


Die::~Die()                                     //Destructor
{

}


int Die::die_roll()                             //selects value between 1 and num_sides
{
    int roll = rand() % num_sides + 1;
    cout << "the die roll was " << roll << '\n';
    return roll;
}
    