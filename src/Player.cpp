#include "Game.hpp"
#include "Player.hpp"


const float Player::SPEED = 150;

Player::Player(Game *game)
    : Entity(game)
{

}

void Player::update(float timeDelta) {
    bool shouldMoveLeft = false, shouldMoveRight = false, shouldJump = false;

    for (unsigned int message : m_game->messages) {
        switch (message) {
            case MSG_MOVE_RIGHT:
                shouldMoveRight = true;
                break;
            case MSG_MOVE_LEFT:
                shouldMoveLeft = true;
                break;
            case MSG_JUMP:
                shouldJump = true;
                break;
        }
    }

    if (shouldMoveLeft && !shouldMoveRight) {
        transformation->positionalVelocity.x = -this->SPEED;
    }
    else if (shouldMoveRight && !shouldMoveLeft) {
        transformation->positionalVelocity.x = this->SPEED;
    }
    else {
        transformation->positionalVelocity.x = 0;
    }

    if (shouldJump && transformation->position.y == 350) {
        transformation->positionalVelocity.y = -250;
        transformation->positionalAcceleration.y = 200;
    }
}
