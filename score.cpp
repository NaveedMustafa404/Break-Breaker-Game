#include "score.hpp"

Score :: Score(int _scoreCount )
{
    setscoreCount(_scoreCount) ;
}
void Score:: setscoreCount(int _scoreCount)
{
    scoreCount = _scoreCount;
}
int Score:: getscoreCount() const
{
    return scoreCount;
}


 void Score:: setUpdatedScore()
 {
     scoreCount += 5;
 }
   
