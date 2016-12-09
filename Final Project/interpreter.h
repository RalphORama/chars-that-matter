#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include "player.h"

namespace interpreter
{
    std::string toLowerCasePBV(std::string);
    void toLowerCasePBR(std::string&);
    std::string userInput();
    char interpret(std::string);
}