#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    int x, y, width, height,color;

public:
    Board(int _x=0, int _y=0, int _width=0, int _height=0, int _color=0);
    void setBoard(int _x, int _y, int _width, int _height, int _color);
    void draw() const;
    
    int getx() const;
    int gety() const;

    void setx(int val);
    void sety(int val);

    int getWidth() const;
    int getHeight() const;

    void setWidth(int val);
    void setHeight(int val);
    
    int getColor() const;
    void setColor(int val);
    void setSize(int _width, int _height);
    int getRight() const;  
	int getBottom() const;

};

#endif