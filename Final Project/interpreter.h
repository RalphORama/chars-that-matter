#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include "settings.h"
#include "room.h"
#include "player.h"

namespace interpreter
{
    enum class intention{
        UNDEFINED,  // Undefined input
        HELP,       // User asked for info about available commands
        QUIT,       // User wants to quit
        LOOK,       // User wants a description of the room they're in
        ITEM,       // User wants to pick up an item
        MOVE,       // User wants to move to another room
        ASCEND      // Climb the staircase to win the game
    };

    enum class grabbedItem {
        UNDEFINED,
        TORCH
    };

    std::string toLowerCasePBV(std::string);
    void toLowerCasePBR(std::string&);
    std::string userInput();
    void splitSentence(std::string, std::string[]);
    intention interpret(std::string);
    grabbedItem getItem(std::string);
    bool isNextRoomTooDark(bool, room);
    bool isValidRoom(room);
    std::string printExits(room);
}