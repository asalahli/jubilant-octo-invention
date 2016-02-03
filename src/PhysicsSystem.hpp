#pragma once

#include <Box2D/Box2D.h>

#include "Process.hpp"

class Game;

class PhysicsSystem : public Process {
	b2World *m_physicalWorld;
public:
    PhysicsSystem(Game *game);
    ~PhysicsSystem();

    const b2World& getPhysicalWorld() const { return *m_physicalWorld; };

    virtual void update(float timeDelta);
};
