#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics/Color.hpp>

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
    Vector3f getColor();
    void setBoardWidth(int);
    void setBoardHeight(int);
};

#endif