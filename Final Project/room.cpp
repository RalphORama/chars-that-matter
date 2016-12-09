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
