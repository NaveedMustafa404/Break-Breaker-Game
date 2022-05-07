#include "life.hpp"

 Life :: Life (int _lifeCount) 
 {
    setLifeCount(_lifeCount);
 } 
 void Life:: setLifeCount(int _lifeCount) {lifeCount= _lifeCount;}
 int  Life:: getLifeCount() const {return lifeCount;}

 void Life:: setLifeLoss()
 {
    lifeCount  -= 1;
 }

