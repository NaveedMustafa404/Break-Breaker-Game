#include <graphics.h>
#include "bombbricks.hpp"


Bomb:: Bomb(int _xx, int _yy,  int _wwidth, int _hheight, int _color): Bricks( _xx,  _yy,   _wwidth,  _hheight, _color)
{}

void Bomb :: draw()const
{
        setcolor(colour);
        setfillstyle(SOLID_FILL, colour);
        bar(x, y, x+width, y+height);
        

        
       
}

 void Bomb:: undraw() const
    {
        setcolor(board->getColor());
        setfillstyle(SOLID_FILL, board->getColor());
        bar(x, y, x+width, y+height);
        
        

    }

void Bomb:: onCollision(Ball *with)
{
    if((with->getLeft() <= getX() && getX() <= with->getRight() ) || (with->getLeft() <= getX() + getwidth() && getX() + getwidth() <= with->getRight()))
            with->reverseHorizontal();
            undraw();
            life ->setLifeLoss();


        if((with->getTop() <= getY() && getY() <= with->getBottom()) || (with->getTop() <= getY()+ getheight() && getY()+ getheight() <= with->getBottom()))
            with->reverseVertical();
            undraw();
            life ->setLifeLoss();
}