#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "board.hpp"
#include "player.hpp"

class game
{
private:
    board *b;
    player *p1, *p2;
public:
    void setupGame();
    void startGame();
    
};

#endif