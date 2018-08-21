#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstring>


class HarryPotter : public Creature
{
	private:
		bool Hogwarts;

	public:
	HarryPotter(int a, int s): Creature(a, s) 
	{
	
	}
	virtual bool attack(Creature* defender, std::string def);

	virtual int defend(int attk);
};
#endif