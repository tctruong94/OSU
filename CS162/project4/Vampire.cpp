#include "Vampire.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;


bool Vampire::attack (Creature *defender, string def)                                    //Vampire attack function
{
    int attk_Point = 0;

    for (int i = 0; i < 2; i++)
    {
        attk_Point += rand () % 12 + 1;
    }

    int dmg = defender->defend(attk_Point);

    if (defender->getSP() <= 0){
        cout << "\t" << def << "is at 0 Strength Points and has been defeated." << endl;
        winTotal++;
        if (str_Point > 12)
            str_Point = 12;
        
        return false;
        }
    else{
        return true;
    }

}


int Vampire::defend (int attk)                            //Vampire defend function
{
    int def = 0;
    for(int i = 0; i < 2; i++){
        def += ((rand() % 6) + 1);
    }

    int charmChance = rand () % 2 + 1;

    int total = attk - def;

    if(charmChance == 2)
    {
        str_Point -= 0;
    }
    else{
        if (total < 0)
            {
                str_Point -= 0;
            }
        else
        {
                str_Point -= total;
        }
    
    }
 
    return total;
}





