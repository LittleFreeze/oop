#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class board
{
private:
    int W;
    int H;
    int speed;
    bool field[W][H]={0};
public:
    board();
    int getBoardWidth();
    int getBoardHeight();

};

#endif