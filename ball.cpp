#include <graphics.h>
#include "CoOrdinate.hpp"
#include "ball.hpp"



Ball::Ball(CoOrdinate _pos, int _radius, int _color, int _movX, int _movY)
{
    set(_pos, _radius, _color, _movX, _movY );
}

 Ball::Ball(int _x , int _y , int _radius, int _color, int _movX, int _movY) //: Ball(CoOrdinate(_x, _y), _radius, _color, _movX, _movY)
 {
     CoOrdinate(_x, _y);
     radius= _radius;
     color= _color;
     movX= _movX;
     movY= _movY;
 }
void Ball:: set(CoOrdinate _pos, int _radius, int _color, int _movX, int _movY)
{
    pos = _pos;
    radius = _radius;
    color = _color;
    movX = _movX;
    movY = _movY;

}

int Ball:: getRadius() const {return radius;}
int Ball:: getmovX() const {return movX;}
int Ball:: getmovY() const {return movY;}
int Ball:: getColor() const {return color;}

void Ball:: setRadius(int val)
    {radius = val;}
void Ball:: setmovX(int val) 
    {movX = val;}
void Ball:: setmovY(int val) 
    {movY = val;}
void Ball:: setColor(int val) 
    {color = val;}

CoOrdinate Ball:: getPosition() const{ return pos; }

void  Ball:: setPostion(CoOrdinate val)
{ pos = val;}
void  Ball:: setPostion(int x, int y)
{ pos.setCO(x, y); }
void  Ball:: setmovement(int _movX, int _movY)
{ 
    movX = _movX; 
    movY = _movY;
}
void Ball:: reverseHorizontal() {movX = -movX;}
void Ball:: reverseVertical() {movY = -movY;}

int Ball:: getTop()   {return pos.gety();}
int Ball:: getBottom() {return pos.gety()+ radius;}
int Ball:: getLeft()  {return pos.getx();}
int Ball:: getRight()  {return pos.getx() + radius;}



void Ball:: draw() 
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(pos.getx(), pos.gety(), radius, radius);
}
void Ball:: erase() 
{
    setcolor(board-> getColor());
    setfillstyle(SOLID_FILL, board-> getColor());
    fillellipse(pos.getx(), pos.gety(), radius, radius);   
}
 

void Ball:: move()
{
  	erase(); 
	pos.move(movX, movY);

	// Test for collission with the wall of the room where this ball lives
	// If it collides, change its direction of movement
	if(getRight() >= board->getRight()) 
    {   movX = -movX;
        pos.setx(board->getRight()-radius);
    }
	else if (getLeft() <= board->getx()) movX= -movX;

	
	 if (getTop() <= board->gety()) movY = -movY;
 
     if ((getLeft() >= paddle->getX() - (paddle->getwidth()/2) ) && (getLeft() <= (paddle->getX() + paddle->getwidth())) && (getBottom()>= paddle->getY()) && (getBottom() <= paddle-> getY() + paddle-> getheight())) 
    {movY = -movY; }
    else if(getBottom() >= board->getBottom())
    {
        life-> setLifeLoss();

        erase();
        set(CoOrdinate(1914/2,1000), 10, RED, 50, -45 );
        
        paddle->undraw();
        paddle-> set(1914/2-100,1000+10, 200, 10, paddle->getcolour(), 100);
      
        delay(1000);
      
        draw();
        paddle->draw();

        
        
        getch();
      
    }
	draw();  
}


void Ball:: setBoard(Board* _board) {board = _board;}
Board* Ball:: getBoard() const {return board;}

void Ball:: setPaddle(Paddle* _paddle) {paddle = _paddle;}
Paddle* Ball:: getPaddle() const {return paddle;}

void Ball:: setLife(Life* _life) {life = _life;}
Life* Ball:: getLife() const { return life;}
    
void Ball:: setScore(Score* _score) {score = _score;}
Score* Ball:: getScore() const {return score;} 

