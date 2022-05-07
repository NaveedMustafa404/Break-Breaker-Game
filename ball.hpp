#ifndef BALL_H
#define BALL_H

#include "CoOrdinate.hpp"
#include "board.hpp"
#include "paddle.hpp"
#include "life.hpp"
#include "score.hpp"





class Ball
{
protected:
    CoOrdinate pos; // for center position //Compositon
    int radius, movX, movY, color;
    Board *board;
    Paddle *paddle;
    Life *life;
    Score *score;
   
    
    

public:

    Ball(CoOrdinate _pos= CoOrdinate(0,0), int _radius=10, int _color=10, int _movX=0, int _movY=0);
    Ball(int _x = 0, int _y = 0, int _radius = 50, int _color = 10, int _movX = 0, int _movY = 0);

    int getRadius() const;
    int getmovX() const;
    int getmovY() const;
    int getColor() const;

    void setRadius(int val);
    void setmovX(int val);
    void setmovY(int val);
    void setColor(int val);

    CoOrdinate getPosition() const;
    void setPostion(CoOrdinate val);
    void setPostion(int x, int y);
    void setmovement(int _movX, int _movY);
    void set(CoOrdinate _pos, int _radius, int _color, int _movX, int _movY);


    void move();
    
    void draw() ;
    void erase() ;
    
    int getTop() ;
    int getBottom();
    int getLeft() ;
    int getRight() ;
    void reverseHorizontal();
    void reverseVertical();

    void restart(CoOrdinate _pos, int _radius, int _color, int _movX, int _movY);

    //Assosiating with Board class
    void setBoard(Board*);
    Board* getBoard() const;

    void setPaddle(Paddle*);
    Paddle* getPaddle() const;
    
    void setLife(Life*);
    Life* getLife() const;

    void setScore(Score*);
    Score* getScore() const;





};

#endif