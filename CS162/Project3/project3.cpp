/**********************************************
* Author: Thanhbinh Truong
* Date: May 15th, 2017
* Description: Create a replication of a basic fantasy combat game.
***********************************************/

#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Creature.hpp"
#include "Harrypotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int player_1, player_2;

    Creature* player1;                              //player 1's creature
    Creature* player2;                              //player 2's creature

    Barbarian p1_Barbarian, p2_Barbarian;
    Bluemen p1_Bluemen, p2_Bluemen;
    Harrypotter p1_Harrypotter, p2_Harrypotter;
    Medusa p1_Medusa, p2_Medusa;
    Vampire p1_Vampire, p2_Vampire;

    bool player1_Win = false;                       //false until player 1 wins
    bool player2_Win = false;                       //false until player 2 wins

    int play_Again;
    int move_First;                                 //random generator to decide which player goes first
    int attk_Pwr;
    
    bool game_End = false;                          //False while game still goes on, will become true if user decides to exit
    
    do
    {
        cout << endl << "Welcome to Fantasy Combat Game!" << endl << endl;
        cout << "This game will consist of 2 players."<< endl;
        cout << "Each Player will choose the creature of their choice to battle." << endl;
        cout << "Player 1 and 2 will battle till their creature is has no more strength to fight." << endl << endl;
        cout << "Player 1: Please select a creature: " << endl;
        cout << "1. Vampire " << endl;
        cout << "2. Barbarian " << endl;
        cout << "3. Blue Men " << endl;
        cout << "4. Medusa " << endl;
        cout << "5. Harry Potter " << endl << endl;
        
        cin >> player_1;

        while ((player_1 != 1) && (player_1 != 2) && (player_1 != 3) && (player_1 != 4) && (player_1 != 5))
	    {
		    cin.clear();
		    cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Please enter a valid choice: ";
		    cin >> player_1;
        }

        
        switch (player_1)
        {
            case 1:
            {
                cout << "Player 1 has chosen the Vampire as his creature for battle!" << endl << endl;
                player1 = &p1_Vampire;
                break;
            }
                
            case 2:
            {
                cout << "Player 1 has chosen the Barbarian as his creature for battle!" << endl << endl;
                player1 = &p1_Barbarian;
                break;
            }
                
            case 3:
            {
                cout << "Player 1 has chosen the Blue Men as his creature(s) for battle!" << endl << endl;
                player1 = &p1_Bluemen;
                break;
            }
                
            case 4:
            {
                cout << "Player 1 has chosen Medusa as his creature for battle!" << endl << endl;
                player1 = &p1_Medusa;
                break;
            }
                
            case 5:
            {
                cout << "Player 1 has chosen Harry Potter as his creature for battle!" << endl << endl;
                player1 = &p1_Harrypotter;
                break;
            }
        }
        

        
        cin.clear();
        cin.ignore();
        
        cout << "Player 2: Please select a creature: " << endl;
        cout << "1. Vampire" << endl;
        cout << "2. Barbian" << endl;
        cout << "3. Bluemen" << endl;
        cout << "4. Medusa" << endl;
        cout << "5. HarryPotter" << endl << endl;
        
        cin >> player_2;

         while ((player_2 != 1) && (player_2 != 2) && (player_2 != 3) && (player_2 != 4) && (player_2 != 5))
	    {
		    cin.clear();
		    cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Please enter a valid choice: ";
		    cin >> player_2;
        }


        switch (player_2)
        {
            case 1:
            {
                cout << "Player 2 has chosen the Vampire as his creature for battle!" << endl << endl;
                player2 = &p2_Vampire;
                break;
            }
                
            case 2:
            {
                cout << "Player 2 has chosen the Barbarian as his creature for battle!" << endl << endl;
                player2 = &p2_Barbarian;
                break;
            }
                
            case 3:
            {
                cout << "Player 2 has chosen the Bluemen as his creature(s) for battle!" << endl << endl;
                player2 = &p2_Bluemen;
                break;
            }
                
            case 4:
            {
                cout << "Player 2 has chosen Medusa as his creature for battle!" << endl << endl;
                player2 = &p2_Medusa;
                break;
            }
                
            case 5:
            {
                cout << "Player 2 has chosen Harry Potter as his creature for battle!" << endl << endl;
                player2 = &p2_Harrypotter;
                break;
            }
        }
        
        cin.clear();
        cin.ignore();
        
        move_First = rand () % 2 + 1;

    
        if (move_First == 1)
        {
            cout << "Player 1 has the first move!" << endl << endl;
        }
        else
        {
            cout << "Player 2 has first move!" << endl << endl;
        }
        

        if (move_First == 1)
        {
            while ((player1_Win == false) && (player2_Win == false))
            {
                cout << "Player 1 " << player1->get_Type() << " attacks!" << endl;
                attk_Pwr = player1->attk();
                player2->defend(attk_Pwr);
                player1_Win = player2->defeated();
                
                if (player1_Win == false)
                {
                    cout << "Player 2 " << player2->get_Type() << " attacks!" << endl;
                    attk_Pwr = player2->attk();
                    player1->defend(attk_Pwr);
                    player2_Win = player1->defeated();
                }
            }
        }
        else
        {
            while ((player1_Win == false) && (player2_Win == false))
            {
                cout << "Player 2 " << player2->get_Type() << " attacks!" << endl;
                attk_Pwr = player2->attk();
                player1->defend(attk_Pwr);
                player2_Win = player1->defeated();
                
                if (player2_Win == false)
                {
                    cout << "Player 1 " << player1->get_Type() << " attacks!" << endl;
                    attk_Pwr = player1->attk();
                    player2->defend(attk_Pwr);
                    player1_Win = player2->defeated();
                }
            }
        }
        

        if (player1_Win == true)
        {
            cout << "Player 1 " << player1->get_Type() << " is the winner!!!" << endl << endl;
        }
        else
        {
            cout << "Player 2 " << player2->get_Type() << " is the winner!!!" << endl << endl;
        }
        
        cout << "Play again?" << endl;
        cout << "1. Restart" << endl;
        cout << "2. Exit Game" << endl << endl;
        

        cin >> play_Again;

        while ((play_Again != 1) && (play_Again != 2))
	    {
		    cin.clear();
		    cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Please enter a valid choice: ";
		    cin >> play_Again;
        }

        switch (play_Again)
        {
            case 1:
            {
                cout << "restarting..." << endl << endl;
                game_End = false;
		        player1_Win = false;
		        player2_Win = false;
                break;
            }
                
            case 2:
            {
                cout << "Game Over" << endl << endl;
                game_End = true;
                break;
            }
        }

    }while(game_End == false);
}
