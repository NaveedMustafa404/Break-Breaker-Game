#include <graphics.h>
#include "bonusbricks.hpp"


Bonus :: Bonus(int _xx, int _yy,  int _wwidth, int _hheight, int _color) : Bricks(_xx,  _yy,   _wwidth,  _hheight, _color){}

void Bonus:: draw() const
{
    setcolor(colour);
    setfillstyle(SOLID_FILL, colour);
    bar(x, y, x+width, y+height);
    // setcolor(WHITE);
	// rectangle(x,y,x+width, y+height);
}
void Bonus:: undraw() const
{
    setcolor(board->getColor());
    setfillstyle(SOLID_FILL, board->getColor());
    bar(x, y, x+width, y+height);

}

void Bonus:: onCollision(Ball *with)
{
    if((with->getLeft() <= getX() && getX() <= with->getRight() ) || (with->getLeft() <= getX() + getwidth() && getX() + getwidth() <= with->getRight()))
            with->reverseHorizontal();
            undraw();
            
            score -> setUpdatedScore();


        if((with->getTop() <= getY() && getY() <= with->getBottom()) || (with->getTop() <= getY()+ getheight() && getY()+ getheight() <= with->getBottom()))
            with->reverseVertical();
            undraw();
            
            score -> setUpdatedScore();
            
}

