#pragma once

#include <Box2D/Box2D.h>

#include "Component.hpp"
#include "Process.hpp"


class Game;

class Entity : public Process {
public:
    Drawable *drawable;
	b2Body *physicalBody;
    Skeleton *skeleton;
    Animation *animation;

    Entity(Game *game);
    ~Entity();

    virtual void update(float timeDelta) { (void) timeDelta; };
};
