#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


class Bluemen: public Creature
{
    public:
        Bluemen ();
        ~Bluemen ();

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

