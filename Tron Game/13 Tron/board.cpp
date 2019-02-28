#include "board.hpp"

board::board()
{

}

int board::getBoardWidth()
{
    return W;
}

int board::getBoardHeight()
{
    return H;
}

int board::getSpeed()
{
    return speed;
}

void board::setFieldPositon(int playerx, int playery, int set)
{
    field[playerx][playery] = set;
}

bool board::checkFieldPosition(int playerx, int playery)
{
    return field[playerx][playery] != 0;
}