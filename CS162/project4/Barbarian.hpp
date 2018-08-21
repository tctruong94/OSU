#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include <cstring>
#include "Creature.hpp"

using std::cout;
using std::endl;
using std::string;

class Barbarian:public Creature
{
	public:
		Barbarian(int a, int s): Creature(a, s) 
			{
			}

		virtual bool attack(Creature* defender, std::string def);
		virtual int defend(int att);
};
#endif