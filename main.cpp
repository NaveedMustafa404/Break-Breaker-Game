//Programming Project (Brick Breaker)

#include <graphics.h>
#include <stdio.h>
#include "board.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "life.hpp"
#include "bricks.hpp"
#include "bonusbricks.hpp"
#include "bombbricks.hpp"
#include "CoOrdinate.hpp"

using namespace std;
                        
#define MAXBRICKS 140


int main()
{
    int screenWidth = 1914;
	int screenHeight = 1051;
    int brickPosX = 125, brickPosY=100;
    initwindow(screenWidth, screenHeight, "Project");
  
    Board board(0,0,screenWidth, screenHeight, COLOR(246,224,181));
    Ball ball( CoOrdinate(screenWidth/2,1000), 10, RED, -50, -45 );
    Paddle paddle(screenWidth/2-100,1000+10, 200, 10, COLOR(226, 83, 47), 100);
    Life life(3);
    Score score(0);
                   
    Bricks *bricks[MAXBRICKS] ;
    int bombrickIndex1=44, bombbrickIndex2=54;

     for(int i=0; i<MAXBRICKS; i++)
    {
        bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(3, 57, 108));
        if(i>19)  bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(66, 94, 128 ));
        if(i>39)  bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(8, 161, 182 ));
        if(i>59)  bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(134, 176, 190 ));
        if(i>79)  bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(13, 151, 172 ));
        if(i>99)  bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(66, 94, 128 ));
        if(i>119) bricks[i] = new Bonus(brickPosX, brickPosY, 80, 30, COLOR(3, 57, 108));
        
        
        if(i == bombrickIndex1 || i== bombbrickIndex2)
        {bricks[i] = new Bomb(brickPosX, brickPosY, 80, 30, COLOR(254,74,73));}
        
        brickPosX += 85;

       
        if (brickPosX > 1750)      // setting the limitations 
            {
                brickPosX    = 125;
                brickPosY   += 50; 
            }
    }
    
    board.draw();
    ball.draw();
      
    for(int i=0; i<MAXBRICKS; i++)
    {   
        bricks[i]->setBoard(&board);
        bricks[i]->setScore(& score);
        bricks[i]->setLife(& life);
      
        bricks[i]->draw();
    }
    
    paddle.draw();   
    
 
    ball.setBoard(&board); // Setting the ball in the game board
    paddle.setBoard(&board);     // Same for the paddle. setting the paddle in the game board and fetching the information 
    ball.setPaddle(& paddle);    // Sending the information of the paddle to ball object
    ball.setLife(&life);   // ball getting the information about life object
     
    int ch = 0;
    Bricks *collided = NULL; // if collide then to detect the action 
    
    ch = getch();
   	while (ch != 27 && life.getLifeCount() != 0)
	{
          char score_array[50];
                sprintf(score_array, "Score: %d",score.getscoreCount() );
                outtextxy(30, 10,  score_array);
            char life_array[50];
                sprintf(life_array, "Life: %d", life.getLifeCount() );
                outtextxy(1700, 10, life_array);

        if(ch = ' ')
        {
            collided = NULL;
            for(int i=0; i<MAXBRICKS; i++)
            {
                if(bricks[i]->collision(& ball))
                {
                    collided = bricks[i];
                    break;
                }
            }
            delay(125);
            if(collided != NULL)
            {
                collided->onCollision(& ball);
                delete collided;
                ball.move();
              
            }
            else ball.move();
        
        }

         if (kbhit())
        {
            
            ch=getch();
            if(ch==0)
                ch= getch();
            switch(ch)
            {
                case 77:
                    paddle.moveRight();
                    break;
                case 75:
                    paddle.moveLeft();
                    break;
                
            }
            
         }
        	
	} 

    string lines[] = { "GAME OVER!"}; 

	for (int i=0, y=500; i<1; i++, y+=200)
		outtextxy (900,y, (char*)lines[i].c_str());

        delay(5000);
    return 0;
    
}