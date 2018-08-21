#include <iostream>
#include <cstdlib>
#include <cstring>


using std::cout;
using std::endl;
using std::string;
using std::cin;


int creatureOptions()														//displays creature options
{
	int pick;

	cout << "1: Medusa" << endl;
	cout << "2: Barbarian" << endl;
	cout << "3: Vampire" << endl;
	cout << "4: Blue Men" << endl;
	cout << "5: Harry Potter" << endl;

	cout << "Enter your selection: ";

	cin >> pick;

	if (pick > 5 || pick < 0)
	{
		cout << "That is not one of the options. " << endl;
		return creatureOptions();
	}
	else
	{
		return pick;
	}
}


string creatureNames(int a)													//display creature selections
{
	if (a == 1) 
	{
		return "Medusa"; 
	}
	if (a == 2) 
	{
		return "Barbarian"; 
	}
	if (a == 3) 
	{
		return "Vampire"; 
	}
	if (a == 4) 
	{
		return "Blue Men"; 
	}
	if (a == 5) 
	{
		return "Harry Potter"; 
	}
	else
	{
		return "You did not choose a creature.";
	}

}


Creature* creaturePick(int c)													//receives number of creature
{
	if (c == 1)
	{
		return new Medusa(3, 8);
	}
	if (c == 2)
	{
		return new Barbarian(0, 12);
	}
	if (c == 3)
	{
		return new Vampire(3, 12);
	}
	if (c == 4)
	{
		return new BlueMen(3, 12);
	}
	if (c == 5)
	{
		return new HarryPotter(0, 10);
	}
	else
	{
		return NULL;
	}
							
}



Creature* battle(Creature *att, string attacker, Creature *def, string defender)		//recursive function that returns losing creature's pointer
{
	if(att->attack(def, defender))
	{
		return battle(def, defender, att, attacker);
	}
	else
	{
		return def;
	}
}


bool tournament(CreatureList* p1, CreatureList* p2, LoserList *loser1, LoserList *loser2)			//Runs the battle to determine which player lost.
{																									//Loser is held in loser list
																									//loop until returns false which is when one team has lost
	cout << "\n**************************************" << endl;													
	cout << "Player 1's fighters: " << endl;
	p1->printList();
	cout << "Player 2's fighters: " << endl;
	p2->printList();

	cout << "\nPlayer 1's ";
	p1->getName();
	cout << " attacks first, " << endl;

	cout << "Player 2's ";
	p2->getName();
	cout << " defends." << endl;

	Creature *lost = battle( p1->getCurrent(), p1->getType(), p2->getCurrent(), p2->getType());

	if( lost == p1->getCurrent() )															//player 1 loses
	{

		loser1->add(p1->getCurrent(), p1->getType(), p1->getID());
		p1->remove();


		p2->moveNext();

	}
	else if( lost == p2->getCurrent() )													//player 2 loses
	{

		loser2->add(p2->getCurrent(), p2->getType(), p2->getID());
		p2->remove();

		p1->moveNext();

	}
	return ( p1->getHead() && p2->getHead() );												//return false when one player loses
}



CreatureList* select()															//user selects four creatures
{
	Creature *creature1, *creature2, *creature3, *creature4;
	string char1, char2, char3, char4, one, two, three, four;

	CreatureList *userList = new CreatureList;

	//first
	cout << "Choose your first creature: " << endl;

	int charOne = creatureOptions();
	creature1 = creaturePick(charOne);
	char1 = creatureNames(charOne);

	cin.clear();
	cin.ignore();

	cout << "Now, Name your " << char1 << endl;
	getline(cin, one);
	userList->add(creature1, char1, one);

	//second
	cout << "\nPick the second creature: " << endl;

	int charTwo = creatureOptions();
	creature2 = creaturePick(charTwo);
	char2 = creatureNames(charTwo);

	cin.clear();
	cin.ignore();

	cout << "Now, Name your " << char2 << ": " << endl;
	getline(cin, two);
	userList->add(creature2, char2, two);

	//third
	cout << "\nPick your third creature: " << endl;

	int charThree = creatureOptions();
	creature3 = creaturePick(charThree);
	char3 = creatureNames(charThree);

	cin.clear();
	cin.ignore();

	cout << "Now, Name your " << char3 << ": " << endl;
	getline(cin, three);
	userList->add(creature3, char3, three);

	//fourth
	cout << "\nPick your fourth creature: " << endl;

	int charFour = creatureOptions();
	creature4 = creaturePick(charThree);
	char4 = creatureNames(charThree);

	cin.clear();
	cin.ignore();

	cout << "Now, Name your " << char4 << ": " << endl;
	getline(cin, four);
	userList->add(creature4, char4, four);

	return userList;
}



int tallyWins(LoserList* loser)													//count number of wins
{
	int wins = 0;
	for (int i = 0; i < 4; i++)
	{
		wins += loser->getCurrent()->getWins();
		cout << endl;

		loser->moveNext();
	}
	return wins;
}
