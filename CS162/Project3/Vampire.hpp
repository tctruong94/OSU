#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


class Vampire: public Creature                      //Vampire Class declaration
{
    public:
        Vampire ();
        ~Vampire ();

        string get_Type ();
        int getArmor ();
        int get_Str ();

        int attk ();
        void defend (int damage);

        int attk_Roll ();
        int def_Roll ();

        bool defeated ();
};

#endif

