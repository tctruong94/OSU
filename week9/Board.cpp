/*****************************
** Author: Thanhbinh(Michael) Truong
** Date: March 8th 2017
** Description: The function declarations for the Board class
******************************/

#include <iostream>
#include "Board.hpp"

using namespace std;

/*****************************
** Name: Board::Board()
** Description: Default constructor for the Board class
******************************/
Board::Board() 
{
	for (int row = 0; row < 3; row++) 
    {
		for (int column = 0; column < 3; column++) 
        {
			layout[row][column] = '\0';
		}
	}
}

/*****************************
** Name: bool Board::makeMove
** Description: Makes a move in the TicTacToe game
******************************/
bool Board::makeMove(int x, int y, char c) 
{
	bool move = false;

	if (((x >= 0) && (x <= 2)) && ((y >= 0) && (y <= 2))) 
    {		
		if (layout[x][y] == '\0') 
        {
			layout[x][y] = c;
			move = true;
		} 
        else 
        {
			cout << "That square is already taken." << endl;
		}
	} 
    else 
    {
		cout << "Invalid move." << endl;
	}

	return move;
}

/*****************************
** Name: GameState Board::gameState
** Description: Views the board and figures out if the game has been won,
** if its a draw, or if it is still in progress.
******************************/
GameState Board::gameState() 

{
    //Check if there is a winner horizontally in the first row
	if ((layout[0][0] != '\0') && ((layout[0][0] == layout[0][1]) && (layout[0][1] == layout[0][2]))) 
    {
		if (layout[0][0] == 'X') 
        {
			return X_WINS;
		} 
        else 
        {
			return O_WINS;
		}
	} 

    //Check if there is a winner horizontally in the second row
    else if ((layout[1][0] != '\0') && ((layout[1][0] == layout[1][1]) && (layout[1][1] == layout[1][2])))
    {
		if (layout[1][0] == 'X')
        {
			return X_WINS;
		} 
        else 
        {
			return O_WINS;
		}
	
	} 
    
    //Check if there is a winner horizontally in the third row
    else if ((layout[2][0] != '\0') && ((layout[2][0] == layout[2][1]) && (layout[2][1] == layout[2][2]))) 
    {
		if (layout[2][0] == 'X') 
        {
			return X_WINS;
		} else 
        {
			return O_WINS;
		}
	
	} 

    //Check if there is a winner vertically in the first column
    else if ((layout[0][0] != '\0') && ((layout[0][0] == layout[1][0]) && (layout[1][0] == layout[2][0]))) 
    {
		if (layout[1][0] == 'X') 
        {
			return X_WINS;
		} else 
        {
			return O_WINS;
		}
    }
    
    //Check if there is a winner vertically in the second column.
    else if ((layout[0][1] != '\0') && ((layout[0][1] == layout[1][1]) && (layout[1][1] == layout[2][1]))) 
    {
		if (layout[0][1] == 'X') 
        {
			return X_WINS;
		} else 
        {
			return O_WINS;
		}

	} 
    
    //Check if there is a winner vertically in the third column.
    else if ((layout[0][2] != '\0') && ((layout[0][2] == layout[1][2]) && (layout[1][2] == layout[2][2]))) 
    {
		if (layout[0][2] == 'X') 
        {
			return X_WINS;
		} else 
        {
			return O_WINS;
		}
	}

    ////Check if there is a winner diagonally starting from [0][0] to [2][2]
    else if ((layout[0][0] != '\0') && ((layout[0][0] == layout[1][1]) && (layout[1][1] == layout[2][2]))) 
    {
		if (layout[0][0] == 'X') 
        {
			return X_WINS;
		} else 
        {
			return O_WINS;
		}
    } 
    
    //Check if there is a winner diagnoally starting from [2][0] to [0][2]
    else if ((layout[2][0] != '\0') && ((layout[2][0] == layout[1][1]) && (layout[1][1] == layout[0][2]))) 
    {
		if (layout[2][0] == 'X')
        {
			return X_WINS;
		} else {
			return O_WINS;
		}
    }
    
    //Checks if there are empty slots left, 
    //if so, then the game is still in progress,
    //if not, then the game ends in a draw
    else 
    {
	    for (int row = 0; row < 3; row++) 
        {
			for (int column = 0; column < 3; column++) 
            {
				if (layout[row][column] == '\0') 
                {
					return IN_PROGRESS;
				}
			}
		}
		return DRAW;
	}
}

/*****************************
** Name: Board::print() 
** Description: Prints updated board with moves from Player1 or 2
******************************/
void Board::print() 
{
	cout << "  0 1 2" << endl;
	for (int row = 0; row < 3; row++) 
    {	
		cout << row << " ";	
		for (int column = 0; column < 3; column++) 
        {
			if (layout[row][column] == '\0') 
            {
				cout << ". ";
			} 
            else 
            {
				cout << layout[row][column] << " ";
			}
		}
		cout << endl;
	}
}