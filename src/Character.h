#pragma once
#include <string>
#include <vector>
#include <iostream>

class Character {
public:
    std::string name;
    int hp;
    int ac;          // armor class
    int damageDie;   // damage value
    std::vector<std::string> inventory; // Player inventory

    Character() : name(""), hp(0), ac(0), damageDie(0) {}

    Character(const std::string& n, int h, int armor, int dmg)
        : name(n), hp(h), ac(armor), damageDie(dmg) {}

    // Add an item to inventory
    void addItem(const std::string& item) {
        inventory.push_back(item);
    }

    // Show items in inventory
    void showInventory() const {
        if (inventory.empty()) {
            std::cout << name << "'s inventory is empty.\n";
            return;
        }
        std::cout << name << "'s Inventory:\n";
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << i + 1 << ". " << inventory[i] << "\n";
        }
    }
};
