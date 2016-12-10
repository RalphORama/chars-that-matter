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