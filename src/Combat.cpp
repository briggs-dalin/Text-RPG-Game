#include "Combat.h"
#include "Utils.h"
#include <iostream>

void attack(Character& attacker, Character& defender) {
    int roll = rollDice(20);
    std::cout << attacker.name << " rolls " << roll << "!\n";

    if (roll == 1) {
        std::cout << "Critical miss!\n\n";
        return;
    }

    if (roll == 20) {
        int damage = rollDice(attacker.damageDie) * 2;
        defender.hp -= damage;
        std::cout << "CRITICAL HIT! " << damage << " damage dealt!\n\n";
        return;
    }

    if (roll >= defender.ac) {
        int damage = rollDice(attacker.damageDie);
        defender.hp -= damage;
        std::cout << attacker.name << " hits for " << damage << " damage.\n\n";
    } else {
        std::cout << attacker.name << " misses!\n\n";
    }
}

bool useHealthPotion(Character& player) {
    for (size_t i = 0; i < player.inventory.size(); ++i) {
        if (player.inventory[i] == "Health Potion") {
            player.hp += 10;
            std::cout << player.name << " drinks a Health Potion and restores 10 HP!\n\n";

            // Remove potion from inventory
            player.inventory.erase(player.inventory.begin() + i);
            return true;
        }
    }

    std::cout << "You don't have a Health Potion!\n\n";
    return false;
}


void combat(Character& player, Character& enemy) {
    std::cout << "A wild " << enemy.name << " appears!\n\n";

    while (player.hp > 0 && enemy.hp > 0) {

        // PLAYER TURN
        int choice;
        std::cout << "Your turn:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Use Health Potion\n";
        std::cout << "> ";
        std::cin >> choice;

        if (choice == 1) {
            attack(player, enemy);
        }
        else if (choice == 2) {
            bool used = useHealthPotion(player);
            if (!used) {
                std::cout << "You lose your turn fumbling for a potion!\n\n";
            }
        }
        else {
            std::cout << "Invalid choice! You lose your turn.\n\n";
        }

        if (enemy.hp <= 0) {
            std::cout << enemy.name << " is defeated!\n";
            break;
        }

        // ENEMY TURN
        attack(enemy, player);

        if (player.hp <= 0) {
            std::cout << "You have been slain!\n";
            break;
        }
    }
}

