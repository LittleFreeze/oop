#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class board
{
private:
    int W = 600;
    int H = 480;
    int speed = 4;
    bool *field = new bool[W][H];
public:
    board();
    int getBoardWidth();
    int getBoardHeight();

};

#endif