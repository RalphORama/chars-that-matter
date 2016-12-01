#include "player.h"

player::player(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
}

int player::getx()
{
    return x;
}

int player::gety()
{
    return y;
}