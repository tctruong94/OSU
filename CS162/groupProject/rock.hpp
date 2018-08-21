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
#ifndef ROCK_HPP
#define ROCK_HPP

#include "tool.hpp"

class Rock : public Tool 
{
	public:
		Rock();
		Rock(int);
		char fight(Tool*);
};
#endif
