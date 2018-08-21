#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void gameRules();
void showMenu();
int inputVal();
char charVal();

using std::cout;
using std::cin;
using std::endl;

int main()
{
    showMenu();

    char p1, 
         p2;

    int p1_sides, 
        p2_sides, 
        rounds;

    srand(time(0));

    cout << "Player 1: Do you want a loaded die? (y/n)" << endl;
    cin >> p1;
    while ((p1 != 'Y') && (p1 != 'y') && (p1 != 'n') && (p1 != 'N'))	
	{
		cin.clear();
		cin.ignore();
		cout << "\nPlease enter y or n: ";
		cin >> p1;
	}
    bool loaded = (p1 == 'y' || p1 == 'Y') ? true : false;

    cout << "Player 2: Do you want a loaded die? (y/n)\n" << endl;
    cin >> p2;
    while ((p2 != 'Y') && (p2 != 'y') && (p2 != 'n') && (p2 != 'N'))	
	{
		cin.clear();
		cin.ignore();
		cout << "\nPlease enter y or n: ";
		cin >> p2;
	}
    bool loaded_2 = (p2 == 'y' || p2 == 'Y') ? true : false;

    cout << "How many sides would player 1 like their Die to have? " << endl;
    cin >> p1_sides;
    while (cin.fail())	
	    {
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Please enter an number: ";
		cin >> p1_sides;
	    }

    cout << "How many sides would player 2 like their Die to have? " << endl;
    cin >> p2_sides;
    while (cin.fail())	
	    {
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Please enter an number: ";
		cin >> p2_sides;
	    }

    cout << "How many rounds do you want to play:";
    cin >> rounds;
    while (cin.fail())	
	    {
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Please enter an number: ";
		cin >> rounds;
	    }

    Game dieGame(rounds, p1_sides, p2_sides, loaded, loaded_2);
    dieGame.play_game();

    return 0;
}




void showMenu()
{
    int choice;
    do
    {
    cout << endl << "1. Start Game" << endl;
    cout << "2. View Game Rules" << endl;
    cout << "3. Exit Game" << endl;

    cin >> choice;

    while ((choice != 1) && (choice != 2) && (choice != 3))	
	    {
		cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Please enter an number: ";
		cin >> choice;
	    }

    switch(choice)
    {
    case 1: 
            cout << "Game will start." << endl;
            break;
    case 2: 
            gameRules();
            break;
    case 3: 
            exit(0);
            break;
    }
    }
    while(choice != 1);
}

void gameRules()
{
    cout << "This game will have 2 players." << endl;
    cout << "Each player will be allowed to choose a regular die or a loaded die." << endl;
    cout << "In either case, you will be asked for the number of sides on the die for each player." << endl;
    cout << "The game will play a number of rounds specified by the players." << endl;
    cout << "The winner of each round will be the player with the higher number on the die after being rolled" << endl;
    cout << "The overall winner will be the player with the most wins." << endl;
}





char charVal()
{
    char a;
    do
    {
        cin >> a;
        if((a != 'Y' && a != 'y') && (a != 'N' && a != 'n'))
            cout << "Not a valid input " << endl;
    }
    while(a != 'Y' && a != 'y' && a != 'N' && a != 'n');

    return a;
}