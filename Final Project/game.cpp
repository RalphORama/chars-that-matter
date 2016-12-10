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
using movement = player::movement;

int main(void)
{
    // Instantiate our variables
    ifstream levelFile(LEVEL_FILE_NAME);
    json levelJSON;
    room dungeon[LEVEL_WIDTH][LEVEL_HEIGHT];
	int numrooms;

    if (levelFile.fail())
    {
        WordWrap::OutputText("ERROR! level_01.json not found! Copy it to the exe directory and re-run the program.");
        WordWrap::OutputText("Press enter to exit...");
        cin.ignore();
        return 1;
    }

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
        dungeon[x][y] = room(levelJSON[currentRoom]["flavortext"], levelJSON[currentRoom]["itemtext"],
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
        string userInput[MAX_USERINPUT_WORDS];

        WordWrap::OutputText(interpreter::printExits(currentRoom));

        interpreter::splitSentence(interpreter::userInput(), userInput);

        switch (interpreter::interpret(userInput[0]))
        {
        case intention::HELP:
        {
            WordWrap::OutputText(HELPTEXT);
            break;
        }
        case intention::QUIT: 
        {
            WordWrap::OutputText("Do you really want to quit? (y/n)");
            if (interpreter::userInput() == "y")
                ply.dead = 1;
            break;
        }
        case intention::ITEM: 
        {
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
        }
        case intention::MOVE:
        {
            movement plyMovement = ply.move(currentRoom, dungeon, ply, userInput[0]);
            if (plyMovement != movement::NONE)
            {
                switch (plyMovement)
                {
                case movement::NORTH:
                    ply.x -= 1;
                    break;
                case movement::EAST:
                    ply.y += 1;
                    break;
                case movement::SOUTH:
                    ply.x += 1;
                    break;
                case movement::WEST:
                    ply.y -= 1;
                    break;
                default:
                    break;
                }

                WordWrap::OutputText("You go " + userInput[0]);
                WordWrap::OutputText(dungeon[ply.x][ply.y].flavorText);
            }
            else
            {
                WordWrap::OutputText("You cannot go that direction!");
            }
            break;
        }
        case intention::LOOK:
        {
            WordWrap::OutputText(currentRoom.flavorText);
            break;
        }
        case intention::ASCEND:
        {
            int winX = levelJSON["winroom"]["x"], winY = levelJSON["winroom"]["y"];
            
            if (ply.x == winX && ply.y == winY)
            {
                WordWrap::OutputText("You ascend the staircase, shielding your eyes from the light.");
                WordWrap::OutputText("Unsure of what awaits you at the surface, you emerge, ready to take on whatever adventure lies ahead.");
                ply.dead = true;
            }

            break;
        }
        default:
        {
            WordWrap::OutputText("I'm not sure what you mean by " + userInput[0]);
            break;
        }
        }
    }
    while (ply.dead == false);
    // END MAIN GAME LOOP
    // ------------------------------------------------------------------------

    // Ending stuff
    WordWrap::OutputText("Press enter to exit...");
    // Just read garbage, wait for enter key
    cin.ignore();
    return 0;
}