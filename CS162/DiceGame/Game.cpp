#include "Game.h"
#include "Die.h"
#include "LoadedDie.h"

using std::cout;
using std::cin;
using std::endl;

Game::Game(int rounds_to_play, int p1_DiceSides, int p2_DiceSides,          //Constructor
            bool p1_loaded, bool p2_loaded) :                               //game is created
    mostRounds(rounds_to_play)                                              
{
    round = 1;
    score_p1 = score_p2 = 0;

    p1 = p1_loaded ? new LoadedDie(p1_DiceSides) : new Die(p1_DiceSides);
    p2 = p2_loaded ? new LoadedDie(p2_DiceSides) : new Die(p2_DiceSides);
}


Game::~Game()                                           //Destructor
{                     
    delete p1;
    delete p2;
}


void Game::play_round()                                //Plays a round of Die
{
    cout << "Round " << round << endl; 
    cout << "Player 1: ";

    int roll_p1 = p1->die_roll();

    cout << "Player 2: ";

    int roll_p2 = p2->die_roll();

    cout << "\n";

    if (roll_p1 > roll_p2)
    {
        ++score_p1;
    }
    else if (roll_p1 < roll_p2)
    {
        ++score_p2;
    }

    cout << "Player 1 score: " << score_p1 << endl;
    cout << "Player 2 score: " << score_p2 << endl;

    ++round;
}


void Game::play_game()                                      //Plays the amount of rounds specified by user
{
    cout << "Starting new game.\n\n";

    while (round <= mostRounds)
        play_round();

    print_game_result();
}


void Game::print_game_result()                              //prints result of entire game
{
    cout << "Result: ";
    if (score_p1 > score_p2)
        {
        cout << "Player 1 wins!\n";
        }
    else if (score_p1 < score_p2)
        {
        cout << "Player 2 wins!\n";
        }
    else
        {
        cout << "It's a draw!\n";
        }
}

