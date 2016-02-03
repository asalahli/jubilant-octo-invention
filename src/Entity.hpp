#pragma once

#include "Component.hpp"
#include "Process.hpp"


class Game;

class Entity : public Process {
public:
    Drawable *drawable;
    Transformation *transformation;

    Entity(Game *game);
    ~Entity();

    virtual void update(float timeDelta) { (void) timeDelta; };
};
