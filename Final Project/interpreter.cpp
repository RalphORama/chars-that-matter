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

    /// <summary>
    /// Takes a sentence and splits it into an array of words
    /// Source: http://stackoverflow.com/a/16029565
    /// </summary>
    /// <param name="sentence">The sentence to split</param>
    /// <returns>A pointer to the array of words that were in the sentence</returns>
    void splitSentence(std::string sentence, std::string words[MAX_USERINPUT_WORDS])
    {
        // std::string words[MAX_USERINPUT_WORDS];
        std::stringstream wordStream(sentence);

        for (int i = 0; i < MAX_USERINPUT_WORDS; i++)
        {
            if (wordStream.good())
            {
                wordStream >> words[i];
                words[i] = toLowerCasePBV(words[i]);
            }
        }

        // return words;
    }

    /// <summary>
    /// Given the first word of a user's input sentence, interpret what they want
    /// </summary>
    /// <param name="userInput">The first word of the user's input</param>
    /// <returns>An enum declaring what the user wants to do</returns>
    intention interpret(std::string userInput)
    {
        if (userInput == "north" || userInput == "east" ||
            userInput == "south" || userInput == "west")
        {
            return intention::MOVE;
        }
        else if (userInput == "help")
        {
            return intention::HELP;
        }
        else if (userInput == "look")
        {
            return intention::LOOK;
        }
        else if (userInput == "take")
        {
            return intention::ITEM;
        }
        else if (userInput == "ascend")
        {
            return intention::ASCEND;
        }
        else if (userInput == "quit" || userInput == "exit")
        {
            return intention::QUIT;
        }
        else
        {
            return intention::UNDEFINED;
        }
    }

    /// <summary>
    /// Checks to see if the player can get an item.
    /// This is really stupid as of right now, but could be expanded upon in the future.
    /// </summary>
    /// <param name="item">The item the player wants</param>
    /// <returns>Whether the player can get that item</returns>
    grabbedItem getItem(std::string item)
    {
        if (item == "torch")
            return grabbedItem::TORCH;
        else
            return grabbedItem::UNDEFINED;
    }

    /// <summary>
    /// Checks to see if the next room is too dark for the player to enter
    /// </summary>
    /// <param name="hasTorch">Whether the player has a torch</param>
    /// <param name="nextRoom">The room the player is trying to enter</param>
    /// <returns>True if the next room is too dark, false if it isn't</returns>
    bool isNextRoomTooDark(bool hasTorch, room nextRoom)
    {
        if (hasTorch)
            return true;
        else
            return nextRoom.tooDark;
    }

    bool isValidRoom(room r)
    {
        // A valid room will have at least one exit
        return (r.north || r.east || r.south || r.west);
    }

    std::string printExits(room r)
    {
        std::stringstream output;
        output << "You could go ";

        if (r.north)
            output << "north";
        if (r.east)
        {
            if (r.north)
                output << ", or ";
            output << "east";
        }
        if (r.south)
        {
            if (r.north || r.east)
                output << ", or ";
            output << "south";
        }
        if (r.west)
        {
            if (r.north || r.east || r.south)
                output << ", or ";
            output << "west";
        }
        output << ".";

        return output.str();
    }
}
