#include "PlayerCreation.h"
#include <iostream>
#include <limits>

Character createPlayer() {
    std::cout << "Welcome to Dungeon Adventure!\n";
    std::cout << "Choose your class:\n";
    std::cout << "1. Warrior  (High HP, High AC, Lower Damage)\n";
    std::cout << "2. Rogue    (Balanced, Good Damage)\n";
    std::cout << "3. Mage     (Low HP, High Damage)\n";

    int choice;
    while (true) {
        std::cout << "\nEnter choice (1-3): ";
        std::cin >> choice;

        if (!std::cin.fail() && choice >= 1 && choice <= 3)
            break;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Try again.\n";
    }

    std::string playerName;
    std::cout << "\nEnter your character's name: ";
    std::cin >> playerName;

    switch (choice) {
        case 1:
            return Character(playerName + " the Warrior", 30, 15, 6);
        case 2:
            return Character(playerName + " the Rogue", 22, 13, 8);
        case 3:
            return Character(playerName + " the Mage", 18, 11, 10);
        default:
            return Character("Adventurer", 20, 12, 6);
    }
}
