#include "board.hpp"
#include <graphics.h>

Board::Board(int _x, int _y, int _width, int _height, int _color)
{
    x = _x;
    y=_y;
    width = _width;
    height = _height;
    color = _color;
  
}
void Board:: setBoard(int _x, int _y, int _width, int _height, int _color)
{
    x = _x;
    y=_y;
    width = _width;
    height = _height;
    color = _color;
}
void Board:: draw() const
{
    setfillstyle(SOLID_FILL,color);
	bar(x,y,x+width, y+height);

    setcolor(RED);
	rectangle(x,y,x+width, y+height);
    
}
int Board:: getx() const {return x;}
int Board:: gety() const {return y;}

void Board:: setx(int val) {x = val;}
void Board:: sety(int val) {y = val;}

int Board:: getWidth() const {return width;}
int Board:: getHeight() const{return height;}

void Board:: setWidth(int val){ width = val;}
void Board:: setHeight(int val){ height = val;}
    
int Board:: getColor() const {return color;}
void Board:: setColor(int val) {color = val;}
void Board:: setSize(int _width, int _height) {width = _width; height = _height;}

int Board:: getRight() const {return x+width ;}  
int Board:: getBottom() const {return y+height; }