#include "BlueMen.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::string;


bool BlueMen::attack(Creature *defender, string def)
{
	int attk = 0;

	for (int i = 0; i < 2; i++) 
	{
		attk += ((rand() % 10) + 1);
	}

	cout << "\nBlue Men does " << attk << " hits of damage." << endl;

	int dmg = defender->defend(attk);

	if (defender->getSP() <= 0) 
	{
		cout << "\n" << def << " is at 0 Strength Points and has been defeated." << endl;

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



int BlueMen::defend(int attk)
{
	int defense = 0;

	if (str_Point < 4)													//mob special ability
	{
		defense += ((rand() % 6) + 1);
	}
	else if (str_Point < 8)
	{
		for(int i = 0; i < 2; i++) 
		{
			defense += ((rand() % 6) + 1);
		}
	}
	else
	{
		for(int i = 0; i < 3; i++)
		{
			defense += ((rand() % 6) + 1);
		}
	}


	int total = attk - defense - armor;

	if (total < 0)
	{
		total = 0;
	}

	cout << "\nBlue Men defends against " << (defense + armor) << " hits." << endl;
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