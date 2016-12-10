/*
Author: Ralph Drake
Class: CSI-140-05
Assignment: Final Project
Date Assigned: November 29th, 2016
Due Date: 17:00 EST, December 9th, 2016
Description:
    A text-based exploration game
Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the
    definition and consequences of plagiarism and acknowledge that the assessor
    of this assignment may, for the purpose of assessing this assignment:
    - Reproduce this assignment and provide a copy to another member of
      academic staff; and/or
    - Communicate a copy of this assignment to a plagiarism checking
      service (which may then retain a copy of this assignment on its
      database for the purpose of future plagiarism checking)
*/

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