#include "SaveSystem.h"
#include <iostream>

void savePlayer(const Character& player) {
    std::ofstream file("save.txt");

    if (!file.is_open()) {
        std::cout << "Error: Could not create save file.\n";
        return;
    }

    file << "Name: " << player.name << "\n";
    file << "HP: " << player.hp << "\n";
    file << "AC: " << player.ac << "\n";
   

    file.close();

    std::cout << "Game saved to save.txt!\n";
}
