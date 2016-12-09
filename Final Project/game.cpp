#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "json.hpp"
#include "wordWrap.h"

#include "settings.h"
#include "room.h"
#include "player.h"
#include "interpreter.h"

// Namespace declarations
using namespace std;
using json = nlohmann::json;
using intention = interpreter::intention;
using grabbedItem = interpreter::grabbedItem;

// Function prototypes
bool tryMove(room, room**, player, std::string);

int main(void)
{
    // Instantiate our variables
    ifstream levelFile(LEVEL_FILE_NAME);
    json levelJSON;
    room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT];
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
    player ply(levelJSON["player"]["x"], levelJSON["player"]["y"], "",
        levelJSON["player"]["hastorch"]);

    // Ask the player to name themselves before we start the game loop
    WordWrap::OutputText("All of a sudden, you're awake. The smell of damp surrounds you, and you can barely see in the low light.");
    WordWrap::OutputText("Through the haze of regaining conciousness, you remember your name. What is it?");
    ply.name = interpreter::userInput();

    WordWrap::OutputText("And so, " + ply.name + " your journey begins." + "\n");

    // ------------------------------------------------------------------------
    // BEGIN MAIN GAME LOOP
    do
    {
        // Set the current room so we can access its properties
        room currentRoom = dungeon[ply.x][ply.y];
        string* userInput = interpreter::splitSentence(interpreter::userInput());

        switch (interpreter::interpret(userInput[0]))
        {
        case intention::HELP:
            WordWrap::OutputText(HELPTEXT);
            break;
        case intention::QUIT:
            WordWrap::OutputText("Do you really want to quit? (y/n)");
            if (interpreter::userInput() == "y")
                ply.dead = 1;
            break;
        case intention::ITEM:
            // Check which item the user grabbed
            switch (interpreter::getItem(userInput[1]))
            {
            case grabbedItem::TORCH:
                if (!ply.hasTorch)
                {
                    ply.hasTorch = true;
                    WordWrap::OutputText("You picked up a torch.");
                }
                else
                {
                    WordWrap::OutputText("You already had a torch.");
                }
                break;
            default:
                WordWrap::OutputText("That item doesn't exist.");
                break;
            }
            break;
        case intention::MOVE:
            tryMove(currentRoom, dungeon, ply, userInput[1]);
            break;
        default:
            WordWrap::OutputText("I'm not sure what you mean by " + userInput[0]);
            break;
        }
    }
    while (ply.dead == false);
    // END MAIN GAME LOOP
    // ------------------------------------------------------------------------

    return 0;
}

bool tryMove(room currentRoom, room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT], player ply, string direction)
{
    int newX = ply.x;
    int newY = ply.y;

    if (direction == "north")
    {
        newX--;
        if (newX < 0)
        {
            // Error
        }
        else
        {
            // Move
        }
    }
    else if (direction == "east")
    {
        newY++;
        if (newY > LEVEL_WIDTH - 1)
        {
            // Error
        }
        else
        {
            // Move
        }
    }
    else if (direction == "south")
    {
        newX++;
        if (newX > LEVEL_WIDTH - 1)
        {
            // Error
        }
        else
        {
            // Move
        }
    }
    else if (direction == "west")
    {
        newY--;
        if (newY < 0)
        {
            // Error
        }
        else
        {
            // Move
        }
    }
    else
    {
        // Some error or smth
    }
}