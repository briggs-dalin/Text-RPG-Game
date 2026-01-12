#include "Dungeon.h"
#include <iostream>

std::vector<Room> buildDungeon() {
    std::vector<Room> dungeon;

    // Starting room
    dungeon.push_back(Room(
        "You enter a dimly lit stone chamber. A cold wind blows...",
        false,
        Character(),
        1, 2
    ));

    // Room with a goblin enemy
    dungeon.push_back(Room(
        "You step into a narrow hallway. A Goblin leaps out!",
        true,
        Character("Goblin", 10, 11, 4),
        3, 2,
        "Health Potion" // room loot
    ));

    // Empty room
    dungeon.push_back(Room(
        "This room is silent. Dust covers the floor...",
        false,
        Character(),
        3, -1
    ));

    // Final boss room
    dungeon.push_back(Room(
        "You found the treasure chamber! A Skeleton Knight blocks your way!",
        true,
        Character("Skeleton Knight", 20, 14, 6),
        -1, -1,
        "Magic Sword" // reward for completing dungeon
    ));

    return dungeon;
}
