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

#include "player.h"

using movement = player::movement;

player::player(int pos_x, int pos_y, std::string n, bool t, bool d)
{
    x = pos_x;
    y = pos_y;
    name = n;
    hasTorch = t;
    dead = d;
}

movement player::move(room currentRoom, room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT], player ply, std::string direction)
{
    movement newMove = movement::NONE;
    int newX = ply.x;
    int newY = ply.y;

    if (direction == "north")
    {
        newX--;
        newMove = movement::NORTH;
    }
    else if (direction == "east")
    {
        newY++;
        newMove = movement::EAST;
    }
    else if (direction == "south")
    {
        newX++;
        newMove = movement::SOUTH;
    }
    else if (direction == "west")
    {
        newY--;
        newMove = movement::WEST;
    }

    if (newX >= 0 && newX < LEVEL_WIDTH &&
        newY >= 0 && newY < LEVEL_HEIGHT &&
        interpreter::isValidRoom(dungeon[newX][newY]))
    {
        return newMove;
    }
    else
    {
        return movement::NONE;
    }
}