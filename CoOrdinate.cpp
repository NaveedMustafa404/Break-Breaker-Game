#include "CoOrdinate.hpp"

CoOrdinate:: CoOrdinate(int _x, int _y)
{
    setCO(_x, _y);
}

void CoOrdinate:: setCO(int _x, int _y)
    {
        x= _x;
        y= _y;
    }
void CoOrdinate:: setx(int val) { x= val;}
void CoOrdinate:: sety(int val) {y= val;}
int CoOrdinate:: getx() const  {return x;}
int CoOrdinate:: gety() const {return y;}
void CoOrdinate:: move(int movX, int movY)
{
    x = x+movX;
    y = y+movY;
}

