#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include "player.h"

namespace interpreter
{
    static std::string toLowerCasePBV(std::string);
    static void toLowerCasePBR(std::string&);
    static char interpret(std::string);
}