#pragma once
#include <string>
#include "Character.h"

class Room {
public:
    std::string description;
    bool hasEnemy;
    Character enemy;

    int nextRoom1;
    int nextRoom2;
    std::string item;  

    
    Room(std::string desc, bool hasEnemy, Character enemy, int next1, int next2, std::string loot = "")
        : description(desc), hasEnemy(hasEnemy), enemy(enemy),
          nextRoom1(next1), nextRoom2(next2), item(loot) {}
};
