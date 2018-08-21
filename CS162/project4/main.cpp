/*****************************************
** Name: Thanhbinh Truong
** Assignment: Program 4
** Date: 5/29/2017
** Description: This is a one-user-two-players game. A user will enter the number of 
** fighters both players will use. The user should also enter the type of creatures and fighter names. 
** You can give fighters different names.  
** So player A’s first fighter could by Harry Potter and he could name the Harry Potter Creature "Larry Snotter" or 
** just Harry Potter No.1. One team could have more than 1 of the same character 
** The first player supplies a lineup of creatures in order. 
** The second player then supplies his lineup of creatures in order. By lineup I mean something like a batting 
** order in baseball or softball. The head of each lineup fight in the same way they fight in project 3. 
** The winner gets put at the back of her/his team’s lineup; the loser goes to the container for those who lost 
** The lineup order cannot be changed once the players are entered. 
** Similarly, the loser pile should have the last loser at the top and the first loser at the bottom.
******************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "CreatureList.hpp"
#include "HarryPotter.hpp"
#include "LoserList.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Tournament.cpp"


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;



int main()
{
	LoserList *loser1 = new LoserList;
	LoserList *loser2 = new LoserList;
	int creatureCount;
	int roundCount = 1;

	srand (time(NULL));

	cout << "\nWelcome to the Tournament of Champions! " << endl << endl;
	cout << "Each Player will will be allowed 4 creatures of their own choosing. " << endl << endl;

	cout << "\nPlayer One, please select your creatures: " << endl;
	CreatureList *p1 = select();

	cout << "\nPlayer Two, please select your creatures: " << endl;
	CreatureList *p2 = select();

	cout << endl << endl;

	do
	{
		cout << "\nRound " << roundCount << " ! " << endl;
		roundCount++;
	} while ( tournament(p1, p2, loser1, loser2) );

	cout << endl << endl;

	while (p1->getHead())
	{
		loser1->add(p1->getCurrent(), p1->getType(), p1->getID());
		p1->remove();
	}
	while (p2->getHead())
	{
		loser2->add(p2->getCurrent(), p2->getType(), p2->getID());
		p2->remove();
	}


	int p1wins = tallyWins(loser1);
	int p2wins = tallyWins(loser2);

	cout << endl << "\nPlayer One's creatures have " << p1wins << " combined wins." << endl;

	cout << "\nPlayer Two's creatures have " << p2wins << " combined wins." << endl;

	if (p1wins > p2wins)
	{
		cout << "\nPlayer 1 has won the tournament!" << endl;
	}
	else if (p2wins > p1wins)
	{
		cout << "\nPlayer 2 has won the tournament!" << endl;
	}

	return 0;
}