#include "player.h"

player::player(int pos_x, int pos_y, std::string n, bool t, bool d)
{
    x = pos_x;
    y = pos_y;
    name = n;
    hasTorch = t;
    dead = d;
}
