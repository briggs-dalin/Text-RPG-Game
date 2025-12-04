#include "Dungeon.h"

std::vector<Room> buildDungeon() {
    std::vector<Room> dungeon;

    dungeon.push_back(Room(
        "You enter a dimly lit stone chamber. A cold wind blows...",
        false,
        Character(),
        1, 2
    ));

    dungeon.push_back(Room(
        "You step into a narrow hallway. A Goblin leaps out!",
        true,
        Character("Goblin", 10, 11, 4),
        3, 2
    ));

    dungeon.push_back(Room(
        "This room is silent. Dust covers the floor...",
        false,
        Character(),
        3, -1
    ));

    dungeon.push_back(Room(
        "You found the treasure chamber! A Skeleton Knight blocks your way!",
        true,
        Character("Skeleton Knight", 20, 14, 6),
        -1, -1
    ));

    return dungeon;
}
