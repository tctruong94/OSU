/********************************************************************
** Program Name: Rock, Paper, Scissors
** Author: Daniel Kim, Marisol Zamora, Patrick Spencer, Andrei Pestovski, Thanhbinh Truong
** Date: 5/15/17
** Description: This class is for playing a game of rock,
** paper, scissors. It gets input from the user for their
** choice of tool and uses the "novice" method to choose
** a tool for the computer. It also allows the user to
** choose different strengths for the tools at the beginning
** of the game. The user has the option to exit the game at
** the beginning of each round.
*********************************************************************/
#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include "inputValidation.hpp"

#include <iostream>
#include <vector>
#include <cstdlib> //for random computer tool at beginning of game
#include <ctime>

class RPSGame 
{
	private:
		Tool* human;
		Tool* computer;
		int human_wins;
		int computer_wins;
		int ties;
		//the vector is used to keep track of the user's past choices
		//this is used to determine what the computer will choose
		std::vector<char> hChoices;
		void searchVector(int&, int&, int&, int);
		
	public:
		RPSGame();
		void playGame();
};

#endif
