#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "wordWrap.h"
#include "room.h"
#include "player.h"
#include "interpreter.h"

// Namespace declarations
using namespace std;
using json = nlohmann::json;

// Constant declarations
const string LEVEL_FILE_NAME = "level_01.json";
const string HELPTEXT = "Available commands:\n\
  north, east, south, west: Move in specified direction.\n\
  look: Inspect the room you're in.\n\
  take <item>: Take an item.\n\
  help: Displays this message.\n\
  quit: Quit the game.";
const int LEVEL_WIDTH = 5, LEVEL_HEIGHT = 5;
const int MAX_USERINPUT_WORDS = 3;

int main(void)
{
    // Instantiate our variables
    ifstream levelFile(LEVEL_FILE_NAME);
    json levelJSON;
    room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT];
    string lastInput;
	int numrooms;

    // Import our level data into our JSON object
    levelFile >> levelJSON;
    levelFile.close();

    // BEGIN LEVEL GENERATION CODE
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
    // END LEVEL GENERATION CODE

    // Create our player
    player ply(
        levelJSON["player"]["x"], levelJSON["player"]["y"], "", levelJSON["player"]["hastorch"]);

    // Ask the player to name themselves before we start the game loop
    WordWrap::OutputText("All of a sudden, you're awake. The smell of damp surrounds you, and you can barely see in the low light.");
    WordWrap::OutputText("Through the haze of regaining conciousness, you remember your name. What is it?");
    ply.name = interpreter::userInput();

    WordWrap::OutputText("And so, " + ply.name + " your journey begins." + "\n");

    // BEGIN MAIN GAME LOOP
    do
    {
        // Set the current room so we can access its properties
        room currentRoom = dungeon[ply.x][ply.y];

        // Get user input and split it up into words
        // Source: http://stackoverflow.com/a/16029565
        lastInput = interpreter::userInput();
        string words[MAX_USERINPUT_WORDS];
        stringstream wordStream(lastInput);
        for (int i = 0; i < MAX_USERINPUT_WORDS; i++)
        {
            if (wordStream.good())
            {
                wordStream >> words[i];
                words[i] = interpreter::toLowerCasePBV(words[i]);
            }
        }

        if (words[0] == "north" || words[0] == "east" || words[0] == "south" || words[0] == "west")
        {
            if (words[0] == "north")
            {

            }
        }
        else if (words[0] == "help")
        {
            WordWrap::OutputText(HELPTEXT);
        }
        else if (words[0] == "look")
        {
            WordWrap::OutputText(currentRoom.flavorText);
        }
        else if (words[0] == "take")
        {
            if (words[1] == "torch" && currentRoom.tooDark == false)
            {
                WordWrap::OutputText("You grab a torch off the wall to help light your journey.");
            }
            // TODO: Handle other items
            else
            {
                WordWrap::OutputText("There's no " + words[1] + " in this room.");
                // "That item doesn't exist!"
            }
        }
        else if (words[0] == "quit")
        {
            WordWrap::OutputText("You feel a splitting pain in your chest and keel over on the spot. Your journey ends here.");
            ply.dead = true;
        }
        else
        {
            WordWrap::OutputText("I'm not sure what you mean by that.");
            // Undefined input
        }

    }
    while (ply.dead == false);
    // END MAIN GAME LOOP

    return 0;
}