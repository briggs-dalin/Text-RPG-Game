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

    Room(std::string desc, bool hasEnemy, Character enemy, int next1, int next2)
        : description(desc), hasEnemy(hasEnemy), enemy(enemy),
          nextRoom1(next1), nextRoom2(next2) {}
};
