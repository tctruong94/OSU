#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


class Medusa: public Creature                   //Medusa Class declaration
{
    public:
        Medusa ();
        ~Medusa ();

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

