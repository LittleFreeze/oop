#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics/Color.hpp>
#include <time.h>

using namespace sf;

class player
{ 
private:
    int x,y,dir;
    Color color;
    int W;
    int H;
public:
    player(Color);
    void tick();
    sf::Vector3f getColor();
    void setBoardWidth(int);
    void setBoardHeight(int);
    int getX();
    int getY();
    int getDir();
    Color getPColor();
    void setX(int);
    void setY(int);
    void setDir(int);
};

#endif