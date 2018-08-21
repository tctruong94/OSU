#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Creature                                              //Creature Parent Class
{
    protected:
        std::string creatureType;

        int attk_Point, def_Point, arm_Point, str_Point;

        bool defeat;
    
    public:
        virtual int attk () = 0;
        virtual void defend (int damage) = 0;

        virtual int attk_Roll () = 0;
        virtual int def_Roll () = 0;

        virtual string get_Type () = 0;
        virtual int getArmor () = 0;
        virtual int get_Str () = 0;

        virtual bool defeated () = 0;
};

#endif

