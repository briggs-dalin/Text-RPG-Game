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

void combat(Character& player, Character& enemy) {
    std::cout << "A wild " << enemy.name << " appears!\n\n";

    while (player.hp > 0 && enemy.hp > 0) {
        attack(player, enemy);
        if (enemy.hp <= 0) {
            std::cout << enemy.name << " is defeated!\n";
            break;
        }

        attack(enemy, player);
        if (player.hp <= 0) {
            std::cout << "You have been slain!\n";
            break;
        }
    }
}
