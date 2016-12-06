#pragma once
#include <string>
class room
{
private:
    /// <summary>
    /// Text that is displayed to the user when they enter the room.
    /// </summary>
    std::string flavorText;
    /// <summary>
    /// Stores whether the exits in the room are open or closed.
    /// 0 = north, 1 = east, 2 = south, 3 = west
    /// </summary>
    bool exits[4];
public:
    // Constructors
    room();
    /// <summary>
    /// Standard room constructor
    /// </summary>
    /// <param name="t">Flavortext to display to the user</param>
    /// <param name="e">boolean array of 4 exits</param>
    room(std::string t, bool e[4]);

    // Getters
    /// <summary>
    /// Gets the room's current flavor text.
    /// </summary>
    /// <returns>A string containing the flavor text.</returns>
    std::string getFlavorText();


    // Setters
    /// <summary>
    /// Updates all four exits at once.
    /// </summary>
    /// <param name="newExits">An array defining whether the exits are open. Ordered n, e, s, w.</param>
    void setExits(int newExits[4]);
    /// <summary>
    /// Changes the state of a single exit for a room.
    /// </summary>
    /// <param name="open">Whether the exit is open or closed.</param>
    /// <param name="direction">Which exit to open/close. Ordered n, e, s, w.</param>
    void updateExit(bool open, char direction);
};

