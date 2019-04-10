#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class player
{
private:
    int x,y,dir;
    Color color;
    int W;
    int H;
    bool jump;
    int jumpCount;
public:
    player(Color,int,int);
    void tick();
    Vector3f getColor();
    void setBoardWidth(int);
    void setBoardHeight(int);
    int getX();
    int getY();
    int getDir();
    bool getJump();
    Color getPColor();
    void setX(int);
    void setY(int);
    void setDir(int);
    void PJump();
};

#endif
