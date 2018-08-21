#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstring>

class BlueMen : public Creature
{
	public:
	BlueMen(int a, int s): Creature(a, s) 
	{
	}

	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};
#endif