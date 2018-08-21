/********************************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This is a derived class of the Tool class. The default
** constructor sets strength to 1 and char to 's'. The non-default
** constructor takes an int parameter to initialize the strength.
** The scissors' fight method doubles strength when fighting paper
** and halves strength when fighting rock.
*********************************************************************/
#include "scissors.hpp"

Scissors::Scissors() 
{
	this->strength = 1;
	this->type = 's';
}

Scissors::Scissors(int s) 
{
	this->strength = s;
	this->type = 's';
}

char Scissors::fight(Tool* opponent) 
{
	int s = this->strength;
	if (opponent->getType() == 'p') {
		s *= 2;
	}
	else if (opponent->getType() == 'r') {
		s /= 2;
	}
	if (s > opponent->getStrength()) {
		return 'h';
	}
	else if (s < opponent->getStrength()) {
		return 'o';
	}
	else {
		return 't';
	}
}
