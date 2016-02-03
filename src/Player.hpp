#pragma once

#include "Entity.hpp"


class Game;

class Player : public Entity {
public:
    static const float SPEED;

    Player(Game *game);

    virtual void update(float timeDelta);
};
