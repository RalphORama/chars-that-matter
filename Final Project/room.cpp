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

/// <summary>
/// Room constructor
/// </summary>
/// <param name="ft">Flavor text the player sees upon entering the room</param>
/// <param name="it">Flavor text the player sees the first time they enter the room</param>
/// <param name="n">Can the player exit north?</param>
/// <param name="e">Can the player exit east?</param>
/// <param name="s">Can the player exit south?</param>
/// <param name="w">Can the player exit west?</param>
/// <param name="td">Is the room too dark for the player to enter?</param>
room::room(std::string ft, std::string it,
    bool n, bool e, bool s, bool w, bool td = false)
{
    flavorText  = ft;
    itemText    = it;
    north       = n;
    east        = e;
    south       = s;
    west        = w;
    tooDark     = td;
}
