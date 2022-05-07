#ifndef BOMBBRICKS_H
#define BOMBBRICKS_H
#include "bricks.hpp"

class Bomb : public Bricks
{
protected:

public:
    Bomb(int _xx= 0, int _yy= 0,  int _wwidth=0, int _hheight=0, int _color = YELLOW);
    void draw() const;
    void undraw() const;
    void onCollision(Ball *with);

};

#endif 