/*
Author: Ralph Drake
Class: CSI-140-05
Assignment: Final Project
Date Assigned: November 29th, 2016
Due Date: 17:00 EST, December 9th, 2016
Description:
    A text-based exploration game
Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the
    definition and consequences of plagiarism and acknowledge that the assessor
    of this assignment may, for the purpose of assessing this assignment:
    - Reproduce this assignment and provide a copy to another member of
      academic staff; and/or
    - Communicate a copy of this assignment to a plagiarism checking
      service (which may then retain a copy of this assignment on its
      database for the purpose of future plagiarism checking)
*/

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