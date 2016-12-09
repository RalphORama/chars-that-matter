#include "interpreter.h"

namespace interpreter
{
    std::string toLowerCasePBV(std::string str)
    {
        std::string temp = str;
        // Source: http://stackoverflow.com/a/313990
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        return temp;
    }

    void toLowerCasePBR(std::string &str)
    {
        // Source: http://stackoverflow.com/a/313990
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    std::string userInput()
    {
        std::string temp;
        std::cout << " > ";
        std::getline(std::cin, temp);
        return temp;
    }

    char interpret(std::string input)
    {
        toLowerCasePBR(input);
        if (input == "north" || input == "east" || input == "south" || input == "west")
        {
            if (input == "north") {
                return 'n';
            }
            else if (input == "east") {
                return 'e';
            }
            else if (input == "south") {
                return 's';
            }
            else {
                return 'w';
            }

        }
        else if (input == "help")
        {
            return 'h';
        }
        else if (input == "take")
        {
            return 't';
        }
        else
        {
            // A space indicates an error interpreting user input, I dunno
            return ' ';
        }
    }
}
