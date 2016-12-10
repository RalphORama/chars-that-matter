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

#include "room.h"

/// <summary>
/// Default constructor
/// Really only used for debugging.
/// </summary>
room::room()
{
    flavorText  = "Undefined room.";
    itemText    = "";
    tooDark     = false;
    north = east = south = west = false;
}

room::room(std::string ft, std::string it,
    bool n, bool e, bool s, bool w, bool td)
{
    flavorText  = ft;
    itemText    = it;
    north       = n;
    east        = e;
    south       = s;
    west        = w;
    tooDark     = td;
}
