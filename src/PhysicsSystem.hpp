#pragma once

#include "Process.hpp"

class Game;

struct Collision {

};

class PhysicsSystem : public Process {
    bool checkCollision(Entity *entity, Entity *otherEntity, Collision& collision);
public:
    PhysicsSystem(Game *game);
    ~PhysicsSystem();

    virtual void update(float timeDelta);
};
