#include "board.hpp"

board::board()
{
    W = 600;
    H = 480;
    speed = 4;
    
}

int board::getBoardWidth()
{
    return W;
}

int board::getBoardHeight()
{
    return H;
}