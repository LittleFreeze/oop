#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "board.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
private:
    board *b;
    player *p1, *p2;
    RenderWindow *window;
    Sprite *sprite;
public:
    void setupGame();
    void startGame();
    
};

#endif