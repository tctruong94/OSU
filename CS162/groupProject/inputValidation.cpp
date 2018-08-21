/******************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description:  This class is used for getting input
from the user and making sure it is valid.
*******************************************************/
#include "inputValidation.hpp"

int InputValidation::getOption() 
{
	int option;
	while (!(cin >> option) || option <= 0 || option > 2) 
	{
		cout << "That is not a valid option" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return option;
}

int InputValidation::getPosInt() 
{
	int q;
	while (!(cin >> q) || q <= 0) 
	{
		cout << "What you entered is not valid" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return q;
}

bool InputValidation::getYN() 
{
	char YN;
	while (!(cin >> YN) || ((YN != 'y') && (YN != 'n'))) 
	{
		cout << "That is not a valid answer. Please enter y or n" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	if (YN == 'y') 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

char InputValidation::getRPS() 
{
		char RPS;
	while (!(cin >> RPS) || ((RPS != 'r') && (RPS != 'p') && (RPS != 's') && (RPS != 'e'))) 
	{
		cout << "That is not a valid answer. Please enter 'r', 'p', 'e' or 's'" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return RPS;
}

/* These functions are not used in program
string InputValidation::getString() {
	string str;
	cin.ignore(256, '\n');
	while (!(std::getline (cin, str))) {
		cout << "What you entered is not valid" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return str;
}

int InputValidation::getInt() {
	int q;
	while (!(cin >> q)) {
		cout << "What you entered is not valid" << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return q;
}

*/
