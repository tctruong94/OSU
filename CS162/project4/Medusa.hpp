#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstring>


class Medusa : public Creature
{
	public:
		Medusa(int a, int s): Creature(a, s) 
		{
		}
	
		virtual bool attack(Creature* defender, std::string def);
		virtual int defend(int att);
};
#endif
