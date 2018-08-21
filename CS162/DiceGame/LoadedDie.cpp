#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LoadedDie.h"

using std::cout;
using std::cin;
using std::endl;

LoadedDie::LoadedDie(int y) : Die(y)                    //Constructor
{
}


void LoadedDie::set_sides(int n)
{
	num_sides = n;
	cout << "there are this many sides on the die " << num_sides << endl;
}


int LoadedDie::die_roll()
{
	int x =0;
    x = rand() % 1 - num_sides;
	cout << "the dice(loaded) was " << x <<endl;
	return x;
}
