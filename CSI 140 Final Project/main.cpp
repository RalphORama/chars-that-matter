#include <iostream>
#include <string>

// Custom classes
#include "player.h"
#include "level.h"
#include "room.h"

using namespace std;

int main(void)
{
    int width, height;
    cout << "Level width: ";
    cin >> width;
    cout << "Level height: ";
    cin >> height;

    cout << "Generating level..." << endl;

    level l = level::level(width, height);
    return 0;
}