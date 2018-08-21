/********************************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This is a derived class of the Tool class. The default
** constructor sets strength to 1 and char to 'p'. The non-default
** constructor takes an int parameter to initialize the strength.
** The paper's fight method doubles strength when fighting rock
** and halves strength when fighting scissors.
*********************************************************************/
#include "paper.hpp"

Paper::Paper() 
{
	this->strength = 1;
	this->type = 'p';
}

Paper::Paper(int s) 
{
	this->strength = s;
	this->type = 'p';
}

char Paper::fight(Tool* opponent) 
{
	int s = this->strength;
	if (opponent->getType() == 'r') 
	{
		s *= 2;
	}
	else if (opponent->getType() == 's') 
	{
		s /= 2;
	}
	if (s > opponent->getStrength()) 
	{
		return 'h';
	}
	else if (s < opponent->getStrength()) 
	{
		return 'o';
	}
	else 
	{
		return 't';
	}
}
