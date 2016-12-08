#pragma once
#include <string>

class room {
public:
    std::string flavorText;
    std::string itemText;
    bool north, east, south, west;
    bool tooDark;

public:
    room();
    room(std::string ft, std::string it,
        bool n, bool e, bool s, bool w, bool td = false);
};