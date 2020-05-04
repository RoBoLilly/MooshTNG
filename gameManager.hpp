#pragma once
#include "worldManager.hpp"
#include "graphicsManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class GameManager {
public:
    WorldManager worldM;
    GraphicsManager graphicsM;
    int parceDungeon(std::string filename);
    void drawWorld(sf::RenderWindow &window);
};