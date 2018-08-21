#ifndef GAME_H
#define GAME_H

#include "Die.h"


class Game 
{
    private:
        Die *p1;
        Die *p2;
        
        int mostRounds;
        
        int round;

        int score_p1;
        int score_p2;

    
    public:
        void play_round();

        void print_game_result();

        Game(int rounds_to_play,int p1_DiceSides, int p2_DiceSides, bool p1_loaded, bool p2_loaded);
        ~Game();

        void play_game();
};

#endif