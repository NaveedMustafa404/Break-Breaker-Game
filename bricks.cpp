#include <graphics.h>
#include "bricks.hpp"


Bricks :: Bricks(int _x, int _y,  int _width, int _height, int _colour)
    {
      x = _x;
      y = _y;
      width = _width;
      height = _height;
      colour = _colour;
    
    }
    void Bricks:: set(int _x, int _y,  int _width, int _height, int _colour)
    {
        setX(_x);
        setY(_y);
        setwidth( _width);
        setheight(_height);
        setcolor(_colour);
        
    }
    int Bricks:: getX () const {return x;}
    int Bricks:: getY () const {return y;}
    
    int Bricks:: getwidth() const {return width;}
    int Bricks:: getheight() const {return height;}
    int Bricks:: getcolour() const {return colour;}

    void Bricks:: setX(int _x) { x=  _x;}
    void Bricks:: setY(int _y)  { y=  _y;}
        
    void Bricks:: setwidth(int _width) {width= _width;}
    void Bricks:: setheight(int _height) {height=_height;}
    void Bricks:: setcolour(int _colour) {colour=_colour;}


     void Bricks:: draw() const
    {
        setcolor(colour);
        setfillstyle(SOLID_FILL, colour);
        bar(x, y, x+width, y+height);
        setcolor(WHITE);
	    rectangle(x,y,x+width, y+height);
    }
      

    
    void Bricks:: undraw() const
    {
        setcolor(board->getColor());
        setfillstyle(SOLID_FILL, board->getColor());
        bar(x, y, x+width, y+height);
    }

  
    bool Bricks:: collision(Ball *with) const
    {
        CoOrdinate c2 = with ->getPosition();
         int cx1 = getX() + getwidth() / 2;
        int cy1 = getY() + getheight() / 2;

        int dx = abs( cx1 - c2.getx()  );
        int dy = abs(cy1 - c2.gety() );
        int sum_rx = getwidth()/2 + with->getRadius();
        int sum_ry = getheight()/2 + with->getRadius();

        return ((dx <= sum_rx) && (dy <= sum_ry));
    }

      void Bricks:: onCollision(Ball *with)
     {
         if((with->getLeft() <= getX() && getX() <= with->getRight() ) || (with->getLeft() <= getX() + getwidth() && getX() + getwidth() <= with->getRight()))
            with->reverseHorizontal();

        if((with->getTop() <= getY() && getY() <= with->getBottom()) || (with->getTop() <= getY()+ getheight() && getY()+ getheight() <= with->getBottom()))
            with->reverseVertical();
     }

    

    void Bricks:: setBoard(Board* _board) {board = _board;}  
    Board* Bricks:: getBoard() const {return board;}
    void Bricks:: setScore(Score* _score) {score = _score;}  // to assosiate with the game board class 
    Score* Bricks:: getScore() const {return score;}
    void Bricks:: setLife(Life* _life) {life = _life;}  // to assosiate with the game board class 
    Life* Bricks:: getLife() const {return life;}

    // void Bricks:: setBall(Ball* _ball) {ball = _ball;} // to assosiate with the game board class 
    // Ball* Bricks:: getBall() const {return ball;}
