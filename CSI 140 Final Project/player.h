#pragma once

#ifndef PLAYER_H_
#define PLAYER_H_
class player
{
private:
    int x, y;
public:
    player(int xPos, int yPos);
    int getx();
    int gety();
};
#endif // !PLAYER_H_
