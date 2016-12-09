#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "wordWrap.h"
#include "room.h"
#include "player.h"
#include "interpreter.h"

using namespace std;
using json = nlohmann::json;

const string LEVEL_FILE_NAME = "level_01.json";
const int LEVEL_WIDTH = 5, LEVEL_HEIGHT = 5;

int main(void)
{
    // Instantiate our variables
    ifstream levelFile(LEVEL_FILE_NAME);
    json levelJSON;
    room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT];
    string playerName;
	int numrooms;

    // Import our level data into our JSON object
    levelFile >> levelJSON;
    levelFile.close();

    // TODO: Generate rooms in dungeon[5][5].
    numrooms = levelJSON["numrooms"];
    for (int i = 0; i < numrooms; i++)
    {
        int x, y;
        string currentRoom = "room_" + to_string(i + 1);

        x = levelJSON[currentRoom]["x"];
        y = levelJSON[currentRoom]["y"];

        // Instantiate the room
        /*
            We have to define tooDark for each room because the JSON interpreter
            doesn't like it when we try to reference a key that doesn't have a value.
        */
        dungeon[x][y] = room(levelJSON[currentRoom]["flavortext"], "",
            levelJSON[currentRoom]["north"], levelJSON[currentRoom]["east"],
            levelJSON[currentRoom]["south"], levelJSON[currentRoom]["west"],
            levelJSON[currentRoom]["toodark"]);
    }

    // Create our player
    player ply(levelJSON["player"]["x"], levelJSON["player"]["y"], "", 
        levelJSON["player"]["hasTorch"]);

    // Ask the player to name themselves before we start the game loop
    WordWrap::OutputText("All of a sudden, you're awake. The smell of damp surrounds you, and you can barely see in the low light.");
    WordWrap::OutputText("Through the haze of regaining conciousness, you remember your name. What is it?");
    playerName = interpreter::userInput();

    // BEGIN MAIN GAME LOOP
    do
    {
        WordWrap::OutputText("Enter something and you'll die.");
        playerName = interpreter::userInput();
        ply.dead = true;
    }
    while (ply.dead == false);
    // END MAIN GAME LOOP

    return 0;
}