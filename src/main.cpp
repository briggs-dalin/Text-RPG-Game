#include "Character.h"
#include "Combat.h"

int main() {
    Character player{"Hero", 20, 13, 6};
    Character goblin{"Goblin", 12, 12, 4};

    combat(player, goblin);

    return 0;
}
