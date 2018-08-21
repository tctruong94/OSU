#ifndef ANT_HPP
#define ANT_HPP

enum Direction { north, east, south, west };

class Ant
{
private:
    char space;
    Direction dir;
    int row1, 
        column1, 
        row2, 
        column2;

public:
    Ant();
    Ant(int a, int b);

    void setDirection(Direction a);
    Direction getDirection();

    void setSpace(char c);
    void setRow1(int r);
    void setColumn1(int c);
    void setRow2(int r2);
    void setColumn2(int c2);

    char getSpace();
    int getRow1();
    int getColumn1();
    int getRow2();
    int getColumn2();
};

#endif

