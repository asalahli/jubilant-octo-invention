#pragma once

#include "Process.hpp"


class Game;

class PhysicsSystem : public Process {
public:
    PhysicsSystem(Game *game);
    ~PhysicsSystem();

    virtual void update(float timeDelta);
};
