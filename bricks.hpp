#ifndef BRICKS_H
#define BRICKS_H

#include"board.hpp"
#include "ball.hpp"
#include "score.hpp"
#include "life.hpp"

class Bricks
{
    protected:
        int x, y, width, height, colour ;
        Board *board;
        // Ball *ball;
        Score *score;
        Life *life;
        
        

    public: 

        Bricks (int _x= 0, int _y= 0,  int _width=0, int _height=0, int _colour = 0); 
        void set(int _x, int _y,  int _width, int _height, int _colour);
        
        void setX(int _x);
        void setY(int _y);
        void setwidth(int _width);
        void setheight(int _height);
    
        int getX () const;
        int getY () const;
        int getwidth() const;
        int getheight() const;
        int getcolour() const;

     
        void setcolour(int _colour);

   
        virtual void draw() const ;
        virtual void undraw()const ;
        
        virtual void onCollision(Ball *with); // polymorphism 

        bool collision(Ball *with) const;
        void setBoard(Board*);  // to assosiate with the game board class 
        Board* getBoard() const;

        void setScore(Score*);  // to assosiate with the game board class 
        Score* getScore() const;

        void setLife(Life*);  // to assosiate with the game board class 
        Life* getLife() const;

        // void setBall(Ball*);  // to assosiate with the game board class 
        // Ball* getBall() const;


};

#endif 