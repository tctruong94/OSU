#include "HarryPotter.hpp"
#include <cstring>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;


bool HarryPotter::attack(Creature *defender, std::string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) 
	{
		a += ((rand() % 6) + 1);
	}

	cout << "Harry Potter does " << a << " hits of damage." << endl;

	int dmg = defender->defend(a);

	if (defender->getSP() <= 0) 
	{
		cout << endl << def << " is at 0 Strength Points and has been defeated." << endl;

		winTotal++;

		Hogwarts = true;

		if (str_Point > 20)
		{
			str_Point = 20;
		}
		return false;
	}
	else 
	{
		cout << endl << def << " is at " << defender->getSP() << " Strength Points." << endl;
		return true;
	}
}


int HarryPotter::defend(int attk)
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

	cout << "Harry Potter defends against " << def << " hits. \nReceives " << total << " damage." << endl;

	if (total < 0)
	{
		str_Point -= 0;
	}
	else
	{
		str_Point -= total;
	}

	if (str_Point <= 0 && Hogwarts == true)
	{
		cout << "Harry Potter uses Hogwarts ability and regains his Strength." << endl;
		str_Point = 20;
		Hogwarts = false;
	}

	return total;
}