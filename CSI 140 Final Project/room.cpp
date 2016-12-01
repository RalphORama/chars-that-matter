#include "room.h"

// Begin constructors
room::room()
{
    flavorText = "";
    for (int i = 0; i < 4; i++)
        exits[i] = false;
}

room::room(std::string t, bool e[4])
{
    flavorText = t;
    for (int i = 0; i < 4; i++)
        exits[i] = e[i];
}
// End constructors

// Begin getters
std::string room::getFlavorText()
{
    return flavorText;
}
// End getters

// Begin setters
void room::setExits(int newExits[4])
{
    for (int i = 0; i < 4; i++)
        exits[i] = newExits[i];
}

void room::updateExit(bool open, char direction)
{
    switch (direction)
    {
    case 'n':
    case 'N':
        exits[0] = open;
        break;
    case 'e':
    case 'E':
        exits[1] = open;
        break;
    case 's':
    case 'S':
        exits[2] = open;
        break;
    case 'w':
    case 'W':
        exits[3] = open;
        break;
    default:
        break;
    }
}
// End setters