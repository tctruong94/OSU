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
#ifndef PAPER_HPP
#define PAPER_HPP

#include "tool.hpp"

class Paper : public Tool 
{
	public:
		Paper();
		Paper(int);
		char fight(Tool*);
};
#endif
