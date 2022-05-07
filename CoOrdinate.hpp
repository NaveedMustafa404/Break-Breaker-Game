#ifndef COORDINATE_H
#define COORDINATE_H

// For the position of ball object 

class CoOrdinate
{
protected:
    int x,y;

public: 
    CoOrdinate(int _x=0, int _y=0);
    
    void setCO(int _x, int _y);
    void setx(int val) ;
    void sety(int val) ;
    int getx() const;
    int gety() const;
    void move(int movX=0, int movY=0);

    


};

#endif