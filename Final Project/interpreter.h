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
    enum intention {
        UNDEFINED,  // Undefined input
        HELP,       // User asked for info about available commands
        QUIT,       // User wants to quit
        LOOK,       // User wants a description of the room they're in
        ITEM,       // User wants to pick up an item
        MOVE        // User wants to move to another room
    };

    enum grabbedItem {
        UNDEFINED,
        TORCH
    };

    std::string toLowerCasePBV(std::string);
    void toLowerCasePBR(std::string&);
    std::string userInput();
    std::string* splitSentence(std::string);
    intention interpret(std::string);
    grabbedItem getItem(std::string);
    bool isNextRoomTooDark(player, room);
}