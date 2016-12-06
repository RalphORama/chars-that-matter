#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"

/// <summary>
/// Removes all instances of the " character from a string.
/// Source: http://stackoverflow.com/a/5674399
/// </summary>
/// <param name="str">String to strip quotes from.</param>
#include "room.h"

void stripQuotes(std::string&);

using namespace std;
using json = nlohmann::json;

const int LEVEL_WIDTH = 10;
const int LEVEL_HEIGHT = 10;

int main(void)
{
    ifstream levelFile("level.json");
    json levelJSON;
    levelFile >> levelJSON;

    string flavText = levelJSON["room01"]["ftext"];
    stripQuotes(flavText);
    cout << flavText << endl;
    cout << levelJSON["room01"]["exits"]["e"] << endl;

    // room level[LEVEL_WIDTH][LEVEL_HEIGHT];
}

void stripQuotes(std::string &str)
{
    str.erase(remove(str.begin(), str.end(), '\"'), str.end());
}