#include <graphics.h>
#include "paddle.hpp"



Paddle:: Paddle(int _x, int _y, int _width, int _height, int _colour,int _pmovX)
{
  
    set( _x,  _y,  _width,  _height,  _colour, _pmovX );

} 
void Paddle:: set(int _x, int _y,  int _width, int _height, int _colour, int _pmovX)
{
    setX(_x);
    setY(_y);
    pmovX= _pmovX;
    width= _width;
    height=_height;
    colour=_colour;

}

    int Paddle:: getX () const {return x;}
    int Paddle:: getY () const {return y;}
    int Paddle:: getpmovX() const {return pmovX;}
  
    int Paddle:: getwidth() const {return width;}
    int Paddle:: getheight() const {return height;}
    int Paddle:: getcolour() const {return colour;}

    void Paddle:: setX(int _x) { x=  _x;}
    void Paddle:: setY(int _y) { y=  _y;}
    void Paddle:: setpmovX(int _pmovX) {pmovX=_pmovX;}
    
    void Paddle:: setwidth(int _width) {width= _width;}
    void Paddle:: setheight(int _height) {height=_height;}
    void Paddle:: setcolour(int _colour) {colour=_colour;}

    void Paddle:: draw() const
    {
        setcolor(colour);
        setfillstyle(SOLID_FILL, colour);
        bar(x, y, x+width, y+height);

    }
    void Paddle:: undraw() const
    {
        setcolor(board->getColor());
        setfillstyle(SOLID_FILL, board->getColor());
        bar(x, y, x+width, y+height);

    }
    void Paddle:: moveRight() 
    {   if( (x+width) < board->getRight())
        {
            undraw();
            x = x + pmovX;
            draw();
        }
    } 
    void Paddle:: moveLeft() 
    {   if( x  > board->getx())
    {
        undraw();
        x = x - pmovX;
        draw();
        }
    } 

    void Paddle:: setBoard(Board* _board) {board = _board;}
    Board* Paddle:: getBoard() const {return board;}

    
