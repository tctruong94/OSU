#include "Barbarian.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;


bool Barbarian::attack(Creature *defender, string def)						//attack() function 
{
	int attk = 0;

	for (int i = 0; i < 2; i++) 
	{
		attk += ((rand() % 6) + 1);
	}

	cout << "\nBarbarian does " << attk << " damage." << endl;

	int dmg = defender->defend(attk);

	if (defender->getSP() <= 0) 
	{
		cout << "\n" << def << " has been defeated." << endl;
        winTotal++;

        if (str_Point > 12)
		{
        	str_Point = 12;
		}
        return false;
	}
	else 
	{
		return true;
	}
}



int Barbarian::defend(int attk)
{
	int def = 0;

	for (int i = 0; i < 2; i++) 
	{
		def += ((rand() % 6) + 1);
	}

	int total = attk - def;

	if (total < 0)
	{
		total = 0;
	}

	cout << "\tBarbarian defends against " << def << " hits." << endl;
	cout << "Receives " << total << " damage." << endl;

	if (total < 0)
	{
		str_Point -= 0;
	}
	else
	{
		str_Point -= total;
	}

	return total;
}