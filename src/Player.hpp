#pragma once

#include "Entity.hpp"


class Game;

class Player : public Entity {
	float jumpCooldown;
public:
    static const float SPEED;
    static const float JUMP_COOLDOWN;

    Player(Game *game);

    virtual void update(float timeDelta);
};
