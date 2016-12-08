#include <string>
#include <iostream>
#include "json.hpp"
#include "room.h"
#include "player.h"

using namespace std;
using json = nlohmann::json;

/*class inventory {
public:
//attributes
string slot1;
string slot2;
string slot3;
string slot4;
public:
//functions
inventory(string slot1, string slot2, string slot3, string slot4) {
slot1 = slot1;
slot2 = slot2;
slot3 = slot3;
slot4 = slot4;
}
};*/

char direction(room r, string userChoice);

room dungeon[5][5];

int main(void)
{
    dungeon[0][1] = room("An empty room, much like the others you've seen already.\n", "However, one thing stands out. There is what looks to be a SPOON sitting on the floor in the corner of the room.\n\n", false, false, false, true);
    dungeon[0][3] = room("You enter the room and find it surprisingly clean. \n", "In the middle there is a wooden pedastle with a WHIPPING ROD on it. How odd.\n\n", false, false, false, true);
    dungeon[1][0] = room("As you pass through the passageway, the smell of damp hits your nose. \nStifling a gag, you enter the circular room and see a BLUE ROD dangling from a ROPE on the celing.", "\nThe ROPE appears to be connected to some sort of hook on the celing that looks like it could move.\n\n", false, false, true, false);
    dungeon[1][2] = room("An empty room with light being cast from a massive fireplace.\n", "", false, false, true, true, true);
    // Following 2 rooms are too dark at first.
    dungeon[1][3] = room("This room is too dark for you to see in. \nYou decide to turn back.\n", "", false, true, false, true, true);
    dungeon[2][1] = room("This room is too dark for you to see in. \nYou decide to turn back.\n", "", false, true, false, true);
    // Change these descriptions by using '24.desc =' and '24.td = false'
    dungeon[2][2] = room("As you enter this room, you are confronted by nothing, aside from the TORCHES flaming on the walls.", "\nMaybe you could TAKE one as a light source?\n\n", false, true, false, true);
    dungeon[2][3] = room("You enter this room and see nothing of interest, aside from a few PEBBLES on the ground.\n", "", false, true, false, false, true);
    dungeon[3][0] = room("You see a LEVER on the right wall of the room.\n", "", false, false, true, false);
    dungeon[3][1] = room("You see nothing of interest in this room, \n           aside from a skeleton chained to the wall.\n", "", false, true, true, false, true);
    dungeon[3][2] = room("The room you woke up in. There is nothing of interest here besides a medium sized rock.\n", "", false, true, false, true, true);
    dungeon[3][3] = room("A room that appears to have been sealed off for ages. \nThere is no sign of GARY THE TROLL, but you do see a TREASURE CHEST.\n", "", false, false, false, true);
    dungeon[4][2] = room("An empty room. The stone walls are covered in moss. \nThe emptiness calls you, but you put your mental phone on silent.\n", "", false, true, true, false);
    dungeon[4][3] = room("You enter the room and are confronted by a burly troll.", "\nIt appears he is not keen on moving.\n\n", false, false, true, false, true);
    dungeon[4][4] = room("As you step through the doorframe, you are confronted by the weak sunlight filtering down through the middle of a spiral staircase. \nAs you ascend to the surface, you ask yourself many questions, such as 'What the heck do I do next?'\n", "", false, false, false, false);

    int currentY = 3;
    int currentX = 2;
    player p = player(dungeon[currentY][currentX], false, "");
    cout << "You awake in a dingy, poorly lit room. \nYou find you can't remember much, but you can vaguely remember your name. \nWhat is it?\n\n";
    string inputName;
    cin >> inputName;
    p.name = inputName;
    cout << "Alright, your name is " << p.name << "." << "\n\nYou see three exits, one to the SOUTH, one to the WEST, and one to the NORTH. \nYou also see a ROCK on the floor that you could TAKE. \nWhat do you do?\n\n";
    while (p.dead == false) {
        string ans1;
        cin >> ans1;
        char dir = direction(dungeon[currentY][currentX], ans1);
        if (dir != '\0') {
            switch (dir) {
            case 'E': currentX++;
                p.whatRoom = dungeon[currentY][currentX].roomnum;
                //pritnting only after entering twice
                cout << "You go EAST\n" << dungeon[currentY][currentX].desc << endl << dungeon[currentY][currentX].stuff << endl << endl;
                break;
            case 'N': currentY--;
                p.whatRoom = dungeon[currentY][currentX].roomnum;
                cout << "You go NORTH\n\n" << dungeon[currentY][currentX].desc << endl << dungeon[currentY][currentX].stuff << endl << endl;
                break;
            case 'S': currentY++;
                p.whatRoom = dungeon[currentY][currentX].roomnum;
                cout << "You go SOUTH\n\n" << dungeon[currentY][currentX].desc << endl << dungeon[currentY][currentX].stuff << endl << endl;
                break;
            case 'W': currentX--;
                p.whatRoom = dungeon[currentY][currentX].roomnum;
                cout << "You go WEST\n\n" << dungeon[currentY][currentX].desc << endl << dungeon[currentY][currentX].stuff << endl << endl;
                break;
            case 'M':
                break;
            case 'K':
                return 0;
                break;
            }
        }
        else {
            cout << "You cannot go " << ans1 << ".\n\n";
        }
        if (currentY == 4 && currentX == 4) {
            p.dead = true;
            cout << "The end." << endl;
        }
    }
    return 0;

}

/*
char direction(room r, string userChoice) {
    string ans1 = userChoice;
    if (ans1.compare("EAST") == 0 || ans1.compare("east") == 0 || ans1.compare("East") == 0) {
        if (r.east == true) {
            return 'E';
        }
        else {
            return '\0';
        }
    }
    else if (ans1.compare("WEST") == 0 || ans1.compare("west") == 0 || ans1.compare("West") == 0) {
        if (r.west == true) {
            return 'W';
        }
        else {
            return '\0';
        }
    }
    else if (ans1.compare("NORTH") == 0 || ans1.compare("north") == 0 || ans1.compare("North") == 0) {
        if (r.north == true) {
            return 'N';
        }
        else {
            return '\0';
        }
    }
    else if (ans1.compare("SOUTH") == 0 || ans1.compare("south") == 0 || ans1.compare("South") == 0) {
        if (r.south == true) {
            return 'S';
        }
        else {
            return '\0';
        }
    }
    else if (ans1.compare("MAP") == 0 || ans1.compare("map") == 0 || ans1.compare("Map") == 0) {
        return 'M';
    }
    else if (ans1.compare("quit") == 0 || ans1.compare("stop") == 0 || ans1.compare("kill") == 0) {
        return 'K';
    }
}
*/

/*char mapParse(int currentX, int currentY) {
int i = 0;
for (i; i < 17; i++){
cout << "######000000######000000######" <<endl;
Sleep(50);
}
for (i = 0; i <17; i++){
cout << "########################000000" <<endl;
Sleep(50);
}
}*/