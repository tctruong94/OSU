#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h"

using std::cout;
using std::cin;
using std::endl;

class LoadedDie: 
public Die 
	{

	public:
        LoadedDie(int);

		void set_sides(int);

		int die_roll(); 
	};
