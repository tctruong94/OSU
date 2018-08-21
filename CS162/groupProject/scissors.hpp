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
#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "tool.hpp"

class Scissors : public Tool 
{
	public:
		Scissors();
		Scissors(int);
		char fight(Tool*);
};
#endif