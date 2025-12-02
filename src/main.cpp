#include <iostream>
#include "PlayerCreation.h"
#include "Combat.h"

int main() {
    Character player = createPlayer();

    Character goblin("Goblin", 12, 11, 4);

    std::cout << "\nYour adventure begins, " << player.name << "!\n\n";

    combat(player, goblin);

    return 0;
}
