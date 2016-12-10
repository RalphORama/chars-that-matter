#pragma once
#include <string>
#include "settings.h"
#include "room.h"
#include "interpreter.h"

class player {
public:
    int x, y;
    std::string name;
    bool hasTorch, dead;

    enum class movement {
        NONE,
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    player(int pos_x, int pos_y, std::string n, bool t = false, bool d = false);
    movement move(room, room[LEVEL_WIDTH][LEVEL_HEIGHT], player, std::string);
};