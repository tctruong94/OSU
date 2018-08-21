/********************************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This is a derived class of the Tool class. The default
** constructor sets strength to 1 and char to 'r'. The non-default
** constructor takes an int parameter to initialize the strength.
** The rock's fight method doubles strength when fighting scissors
** and halves strength when fighting paper.
*********************************************************************/
#include "rock.hpp"

Rock::Rock() 
{
	this->strength = 1;
	this->type = 'r';
}

Rock::Rock(int s) 
{
	this->strength = s;
	this->type = 'r';
}

char Rock::fight(Tool* opponent) 
{
	int s = this->strength;
	if (opponent->getType() == 's') 
	{
		s *= 2;
	}
	else if (opponent->getType() == 'p') 
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
