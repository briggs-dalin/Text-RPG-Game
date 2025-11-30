#include "Utils.h"
#include <random>

int rollDice(int sides) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, sides);
    return distr(gen);
}
