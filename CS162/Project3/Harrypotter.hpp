#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


class Harrypotter: public Creature                      //Harry Potter Class Declaration
{
    public:
        Harrypotter ();
        ~Harrypotter ();

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

