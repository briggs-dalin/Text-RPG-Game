#pragma once
#include <vector>
#include "Room.h"
#include "Character.h"

std::vector<Room> buildDungeon();

void runDungeon(Character& player);
