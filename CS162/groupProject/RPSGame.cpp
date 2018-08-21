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
#include "RPSGame.hpp"
#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> //for random computer tool at beginning of game
#include <ctime>
/*
* This function searches the vector for other occurances of the first n chars
* If another occurance if found it will increment the counter of the char infront
* of that sequence. For example if the vector contained the chars rpsrpsrps
* and n is 3 the function looks at the first 3 char which are rps and sees if that
* sequence occurs anywhere else in the vector. The sequence rps occurs two other times
* in this example and it is preceded by an s both times. The reference variable s would
* then be incremented twice.
*/
void RPSGame::searchVector(int &r, int &p, int &s, int n) 
{
	bool match;
	int j, k;
	//search vector for last n human choices
	for (int i = 1; i < (hChoices.size() - (n - 1)); i++) 
	{
		match = true;
		for (j = i, k = 0; k < n; j++, k++) 
		{
			if (hChoices[k] != hChoices[j]) 
			{
				match = false;
			}
		}
		//if a match is found increment count of
		//the tool after those 4.
		if (match) 
		{
			if (hChoices[i - 1] == 'r') 
			{
				r++;
			}
			else if (hChoices[i - 1] == 'p') 
			{
				p++;
			}
			else 
			{
				s++;
			}
		}
	}
}

RPSGame::RPSGame() 
{
	human = 0;
	computer = 0;
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	hChoices = { };
}

void RPSGame::playGame() 
{
	int seed = std::time(0);
	std::srand(seed);
	InputValidation* valid1 = new InputValidation;

	int rockStrength = 1;
	int paperStrength = 1;
	int scissorsStrength = 1;

	std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
	std::cout << "Would you like to change the tool strengths? (y or n): ";

	bool changeStr = valid1->getYN();

	if (changeStr) 
	{
		std::cout << std::endl << "Enter strength or rock: ";
		rockStrength = valid1->getPosInt();
		std::cout << std::endl << "Enter strength or paper: ";
		paperStrength = valid1->getPosInt();
		std::cout << std::endl << "Enter strength or scissors: ";
		scissorsStrength = valid1->getPosInt();
	}

	char choice = ' '; //for user's input for their tool
	int cChoice = 0; //for computer's tool
	int numberOfRock, //used for determine computer's tool
		numberOfPaper,
		numberOfScissors;

	int round = 0;
	while (choice != 'e') {
		round++;
		std::cout << std::endl << "Choose your tool (r-rock, p-paper, s-scissors, e-exit): ";
		choice = valid1->getRPS();

		if (choice != 'e') 
		{
			//create a new object corresponding to user's input
			if (choice == 'r') 
			{
				human = new Rock(rockStrength);
			}
			else if (choice == 'p') 
			{
				human = new Paper(paperStrength);
			}
			else 
			{
				human = new Scissors(scissorsStrength);
			}
			//if on first 5 rounds get a random tool for computer
			if (round <= 5) 
			{
				cChoice = std::rand() % 3 + 1;
				if (cChoice == 1) 
				{
					computer = new Rock(rockStrength);
				}
				else if (cChoice == 2) 
				{
					computer = new Paper(paperStrength);
				}
				else 
				{
					computer = new Scissors(scissorsStrength);
				}
			}
			//if not on first 5 round use 'novice' method to get computer tool
			else 
			{
				numberOfRock = 0;
				numberOfPaper = 0;
				numberOfScissors = 0;
				//search vector for last 4 human choices
				searchVector(numberOfRock, numberOfPaper, numberOfScissors, 4);
				//if last 4 weren't found search for last 3
				if (numberOfRock == 0 && numberOfPaper == 0 && numberOfScissors == 0) 
				{
					searchVector(numberOfRock, numberOfPaper, numberOfScissors, 3);
				}
				//if last 3 weren't found search for last 2
				if (numberOfRock == 0 && numberOfPaper == 0 && numberOfScissors == 0) 
				{
					searchVector(numberOfRock, numberOfPaper, numberOfScissors, 2);
				}
				//if last 2 weren't found search for last 1
				if (numberOfRock == 0 && numberOfPaper == 0 && numberOfScissors == 0) 
				{
					searchVector(numberOfRock, numberOfPaper, numberOfScissors, 1);
				}
				//if rock count was highest or tied for highest computer tool is paper
				if (numberOfRock >= numberOfPaper && numberOfRock >= numberOfScissors) 
				{
					std::cout << "computer expected you to choose rock" << std::endl;
					computer = new Paper(paperStrength);
				}
				//if paper count was highest or tied for highest computer tool is scissors
				else if (numberOfPaper >= numberOfRock && numberOfPaper >= numberOfScissors) 
				{
					std::cout << "computer expected you to choose paper" << std::endl;
					computer = new Scissors(scissorsStrength);
				}
				//scissors was highest so computer tool is rock
				else 
				{
					std::cout << "computer expected you to choose scissors" << std::endl;
					computer = new Rock(rockStrength);
				}
			}

			if (computer->getType() == 'r') 
			{
				std::cout << "Computer choose rock." << std::endl;
			}
			else if (computer->getType() == 'p') 
			{
				std::cout << "Computer choose paper." << std::endl;
			}
			else {
				std::cout << "Computer choose scissors." << std::endl;
			}

			//add real human choice to vector
			hChoices.insert(hChoices.begin(), human->getType());

			//determine winner
			char winner = human->fight(computer);
			if (winner == 'h') 
			{
				std::cout << "You win!" << std::endl;
				human_wins++;
			}
			else if (winner == 'o') 
			{
				std::cout << "Computer wins" << std::endl;
				computer_wins++;
			}
			else 
			{
				std::cout << "It is a tie" << std::endl;
				ties++;
			}
			
			//print the number of wins
			std::cout << "Player wins: " << human_wins << std::endl;
			std::cout << "Computer wins: " << computer_wins << std::endl;
			std::cout << "Ties: " << ties << std::endl;
			//free pointers for next round
			delete human;
			human = 0;
			delete computer;
			computer = 0;
		}
	}
	delete valid1;
	valid1 = 0;
	hChoices.clear();
}
