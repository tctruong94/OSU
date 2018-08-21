#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>


class Creature
{
protected:
	int str_Point;
	int armor;
	int winTotal;
public:
	Creature(int a, int b)
	{
		armor = a;
		str_Point = b;
		winTotal = 0;
	}

	virtual bool attack(Creature* defender, std::string def) = 0;
	virtual int defend(int) = 0;									//check if defender reached 0 strength

	int getWins() 													//return # of win for a creature
	{ 
		return winTotal; 
		}
	int getSP() 
	{ 
		return str_Point; 
	}							

};

#endif