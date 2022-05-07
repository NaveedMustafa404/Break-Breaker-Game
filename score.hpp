#ifndef SCORE_H
#define SCORE_H

class Score
{
    private:
        int scoreCount;
    public:

    Score (int _scoreCount = 0) ;
    void setscoreCount(int _scoreCount);
    int getscoreCount() const;

    void setUpdatedScore();
    
};

#endif