#ifndef DIE_H
#define DIE_H

class Die
{
    protected:
        int num_sides;

    public:
        Die(int s);

        ~Die();

        int die_roll();
};

#endif