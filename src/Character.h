#pragma once
#include <string>

class Character {
public:
    std::string name;
    int hp;
    int ac;
    int damageDie;

    Character() = default;

    Character(const std::string& n, int h, int armor, int dmg)
        : name(n), hp(h), ac(armor), damageDie(dmg) {}
};
