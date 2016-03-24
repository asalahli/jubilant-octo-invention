#pragma once

#include "Entity.hpp"


const unsigned int ROOT = 0;
const unsigned int HEAD = 1;
const unsigned int BODY = 2;
const unsigned int UPPER_ARM_LEFT = 3;
const unsigned int LOWER_ARM_LEFT = 4;
const unsigned int UPPER_ARM_RIGHT = 5;
const unsigned int LOWER_ARM_RIGHT = 6;
const unsigned int UPPER_LEG_LEFT = 7;
const unsigned int LOWER_LEG_LEFT = 8;
const unsigned int UPPER_LEG_RIGHT = 9;
const unsigned int LOWER_LEG_RIGHT = 10;

const unsigned int BODY_PART_COUNT = 11;


class Game;

class Player : public Entity {
	float jumpCooldown;
public:
    static const float SPEED;
    static const float JUMP_COOLDOWN;

    Player(Game *game);

    virtual void update(float timeDelta);
};
