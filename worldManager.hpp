#pragma once
#include "dungeon.hpp"
#include <vector>

class WorldManager {
private:
    std::vector<Dungeon> world;
    Dungeon* currentDungeon = nullptr;
public:
    void addDungeon(Dungeon dungeon);
    void setDungeon(int id);
    Dungeon* getDungeon();
};