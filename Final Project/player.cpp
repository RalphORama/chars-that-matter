#include "player.h"

player::player(int pos_x, int pos_y, std::string n, bool d = false)
{
    x = pos_x;
    y = pos_y;
    name = n;
    dead = d;
}
