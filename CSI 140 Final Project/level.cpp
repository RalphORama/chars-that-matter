#include "level.h"

level::level(int w, int h)
{
    width = w;
    height = h;
    layout = new room*[w];
    for (int i = 0; i < w; i++)
    {
        layout[i] = new room[h];
    }
}

int level::getWidth()
{
    return width;
}

int level::getHeight()
{
    return height;
}
