#ifndef LIFE_H
#define LIFE_H

class Life
{
private:
int lifeCount;

public:

 Life (int _lifeCount = 0) ;
 void setLifeCount(int _lifeCount);
 int getLifeCount() const;

 void setLifeLoss();
 int getLifeLoss();


};

#endif