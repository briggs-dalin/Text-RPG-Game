#include <iostream>
#include "PlayerCreation.h"
#include "Combat.h"
#include "Dungeon.h"

int main() {
    Character player = createPlayer();
    std::cout << "\nYour adventure begins, " << player.name << "!\n\n";

    auto dungeon = buildDungeon();
    int currentRoom = 0;

    while (currentRoom != -1) {
        Room& room = dungeon[currentRoom];

        std::cout << "\n--- Room " << currentRoom << " ---\n";
        std::cout << room.description << "\n\n";

        // Enemy encounter
        if (room.hasEnemy) {
            std::cout << "A " << room.enemy.name << " attacks!\n";
            combat(player, room.enemy);

            if (player.hp <= 0) {
                std::cout << "\nYou died... Game Over.\n";
                return 0;
            }

            // Prevent fighting again if revisited
            room.hasEnemy = false;
        }

        // End room
        if (room.nextRoom1 == -1 && room.nextRoom2 == -1) {
            std::cout << "\nYou've reached the end of the dungeon!\n";
            break;
        }

        int choice;
        while (true) {
            std::cout << "Where do you want to go next?\n";
            std::cout << "1. Room " << room.nextRoom1 << "\n";
            std::cout << "2. Room " << room.nextRoom2 << "\n";
            std::cout << "> ";
            std::cin >> choice;

            if (choice == 1) {
                currentRoom = room.nextRoom1;
                break;
            }
            if (choice == 2) {
                currentRoom = room.nextRoom2;
                break;
            }

            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "\nCongratulations! You completed the dungeon!\n";
    return 0;
}
