#ifndef PADDLE_H
#define PADDLE_H
#include "board.hpp"
// #include "ball.hpp"
// #include "CoOrdinate.hpp"

class Paddle
{
    private:
        int x, y, width, height, colour, pmovX;
        
        Board* board;
        
       

    public:
        Paddle(int _x= 0, int _y= 0,  int _width=0, int _height=0, int _colour=0, int _pmovX=0); 
        void set(int _x, int _y,  int _width, int _height, int _colour, int _pmovX);
        int getX () const;
        int getY () const;
        int getpmovX() const;
        // int getpmovY() const;
        int getwidth() const;
        int getheight() const;
        int getcolour() const;

        void setX(int _x);
        void setY(int _y);
         void setpmovX(int _pmovX);
        // void setpmovY(int _pmovY);
        void setwidth(int _width);
        void setheight(int _height);
        void setcolour(int _colour);

        void draw() const;
        void undraw() const;
        
        void setBoard(Board*);      // assosiating because need to know about the boundary of the game board 
        Board* getBoard() const;

        // void setBall(Ball*);
        // Ball* getBall() const;

        // void setCo(CoOrdinate*);
        // CoOrdinate* getCo() const;

        void moveRight() ;
        void moveLeft() ;
};

#endif