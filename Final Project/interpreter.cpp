#include "interpreter.h"

namespace interpreter
{
    /// <summary>
    /// Takes a string and transforms it to lower case
    /// </summary>
    /// <param name="str">The string to transform</param>
    /// <returns>The string in lower case</returns>
    std::string toLowerCasePBV(std::string str)
    {
        std::string temp = str;
        // Source: http://stackoverflow.com/a/313990
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        return temp;
    }

    /// <summary>
    /// Transforms a string to lower case in-place
    /// </summary>
    /// <param name="str">The string to transform</param>
    void toLowerCasePBR(std::string &str)
    {
        // Source: http://stackoverflow.com/a/313990
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    /// <summary>
    /// Standardized prompt for getting user input
    /// </summary>
    /// <returns>Text that the user entered</returns>
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
        // Directional input
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
        // Asking for help
        else if (input == "help")
        {
            return 'h';
        }
        // Trying to get an item
        else if (input == "take")
        {
            return 't';
        }
        // Undefined input
        else
        {
            return ' ';
        }
    }
}
