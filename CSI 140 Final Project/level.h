#pragma once
#include "room.h"
class level
{
private:
    int width, height;
    room** layout;
public:
    level(int w, int h);
    int getWidth();
    int getHeight();
};

