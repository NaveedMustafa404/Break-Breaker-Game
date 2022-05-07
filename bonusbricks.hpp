#ifndef BONUSBRICKS_H
#define BONUSBRICKS_H
#include "bricks.hpp"

class Bonus: public Bricks
{
protected:
    // int color;
    
public:
    Bonus(int _xx= 0, int _yy= 0,  int _wwidth=0, int _hheight=0, int _color = 0);
    void draw() const ;
    void undraw() const ;
    // void hit();
    void onCollision(Ball *with);

};

#endif 