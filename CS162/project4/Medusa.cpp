#include "Medusa.hpp"
#include <cstring>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;


bool Medusa::attack(Creature *defender, std::string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) 
	{
		a += ((rand() % 6) + 1);
	}

	if (a == 12)
	{
		cout << endl << def << " has looked in Medusa's eyes and turned to stone!" << endl;
		cout << endl << def << " has been defeated." << endl;

		winTotal++;

		if (str_Point > 8)
			str_Point = 8;

		return false;
	}

	cout << "\nMedusa does " << a << " hits of damage." << endl;

	int dmg = defender->defend(a);


	if (defender->getSP() <= 0) 
	{
		cout << endl << def << " is at 0 Strength Points and has been defeated." << endl;

		winTotal++;
		return false;
	}
	else 
	{
		return true;
	}
}

int Medusa::defend(int att)
{
	int def = 0;
	def += ((rand() % 6) + 1);

	int total = att - def - armor;

	if (total < 0)
	{
		total = 0;
	}

	cout << "Medusa defends against " << (def + armor) << " hits. \nReceives " << total << " damage." << endl;

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