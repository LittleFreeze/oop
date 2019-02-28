#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class board
{
private:
    const int W=600;
    const int H=480;
    int speed = 4;
    bool field[W][H]={0};
public:
    int getBoardWidth();
    int getBoardHeight();

};

#endif