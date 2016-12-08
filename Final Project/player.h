#pragma once
#include <string>

class player {
public:
    int x, y;
    std::string name;
    bool dead;

public:
    player(int pos_x, int pos_y, std::string n, bool d = false);
};