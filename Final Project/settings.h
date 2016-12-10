#pragma once
#include <string>

const std::string LEVEL_FILE_NAME = "level_01.json";
const std::string HELPTEXT = "Available commands:\n\
  north, east, south, west: Move in specified direction.\n\
  look: Inspect the room you're in.\n\
  take <item>: Take an item.\n\
  ascend: Ascend a staircase, if there is one.\n\
  help: Displays this message.\n\
  quit: Quit the game.";
const int LEVEL_WIDTH = 5, LEVEL_HEIGHT = 5;
const int MAX_USERINPUT_WORDS = 2;