#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"

#include "room.h"

void setupLevel(room**, int, int);

using namespace std;
using json = nlohmann::json;

const int LEVEL_WIDTH = 10;
const int LEVEL_HEIGHT = 10;

int main(void)
{
    ifstream levelFile("level.json");
    json levelJSON;
    levelFile >> levelJSON;

    cout << levelJSON["room01"]["ftext"] << endl;

    // room level[LEVEL_WIDTH][LEVEL_HEIGHT];
}

void setupLevel(room** level, int w, int h)
{
    //level[0][0] = room("Flavor test", { false, true, true, false });
}