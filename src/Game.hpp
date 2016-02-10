#pragma once

#include <iostream>
#include <list>
#include <SFML/System.hpp>

#include "Entity.hpp"
#include "Process.hpp"
#include "ResourceManager.hpp"


const int MIN_FRAME_DELAY = 40;

const unsigned int MSG_MOVE_LEFT = 0;
const unsigned int MSG_MOVE_RIGHT = 1;
const unsigned int MSG_JUMP = 2;

class GraphicsSystem;
class PhysicsSystem;

class Game {
    void sleep(int ms);
public:
    sf::Clock clock;
    std::vector<Entity *> entities;
    bool isRunning;
    std::vector<unsigned int> messages;
    b2World *physicalWorld;
    unsigned int playerEntityId;
    ResourceManager resourceManager;
    std::list<Process *> systems;

    Game();
    ~Game();

    void run();
};
