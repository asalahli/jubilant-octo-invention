#include "Game.hpp"
#include "Player.hpp"


const float Player::SPEED = 3.0f;
const float Player::JUMP_COOLDOWN = 1.0f;

Player::Player(Game *game)
    : Entity(game)
{

}

void Player::update(float timeDelta) {
    if (jumpCooldown > 0) {
        jumpCooldown -= timeDelta;
    }

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
        physicalBody->SetLinearVelocity(b2Vec2(-this->SPEED, physicalBody->GetLinearVelocity().y));
    }
    else if (shouldMoveRight && !shouldMoveLeft) {
        physicalBody->SetLinearVelocity(b2Vec2(this->SPEED, physicalBody->GetLinearVelocity().y));
    }
    else {
        physicalBody->SetLinearVelocity(b2Vec2(0.0f, physicalBody->GetLinearVelocity().y));
    }

    if (shouldJump) {
        bool canJump = false;
        for (const b2ContactEdge *contact = physicalBody->GetContactList(); contact; contact = contact->next) {
            if (contact->contact->IsTouching() && contact->other->GetPosition().y <= physicalBody->GetPosition().y) {
                canJump = true;
                break;
            }
        }

        if (canJump && jumpCooldown <= 0) {
            jumpCooldown = this->JUMP_COOLDOWN;
            std::cout << "Jumping" << std::endl;
            physicalBody->ApplyForceToCenter(b2Vec2(0.0f, 300.0f), true);
        }
    }
}
