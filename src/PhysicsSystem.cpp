#include "Game.hpp"
#include "PhysicsSystem.hpp"


PhysicsSystem::PhysicsSystem(Game *game)
    : Process(game)
{

}

PhysicsSystem::~PhysicsSystem() {

}

bool PhysicsSystem::checkCollision(Entity *entity, Entity *otherEntity, Collision& collision) {
    float e1x1, e1y1, e1x2, e1y2;
    float e2x1, e2y1, e2x2, e2y2;

    e1x1 = entity->transformation->position.x + entity->drawable->boundingBox.left;
    e1y1 = entity->transformation->position.y + entity->drawable->boundingBox.top;
    e1x2 = e1x1 + entity->drawable->boundingBox.width;
    e1y2 = e1y1 + entity->drawable->boundingBox.height;

    e2x1 = otherEntity->transformation->position.x + otherEntity->drawable->boundingBox.left;
    e2y1 = otherEntity->transformation->position.y + otherEntity->drawable->boundingBox.top;
    e2x2 = e2x1 + otherEntity->drawable->boundingBox.width;
    e2y2 = e2y1 + otherEntity->drawable->boundingBox.height;

    if ((e1x1 <= e2x1 && e2x1 <= e1x2) || (e1x1 <= e2x2 && e2x2 <= e1x2)) {
        if ((e1y1 <= e2y1 && e2y1 <= e1y2) || (e1y1 <= e2y2 && e2y2 <= e1y2)) {
            return true;
        }
    }

    return false;
}

void PhysicsSystem::update(float timeDelta) {
    for (Entity *entity : m_game->entities) {
        if (entity->transformation == NULL) {
            continue;
        }

        sf::Vector2f oldPosition = entity->transformation->position;
        float oldRotation = entity->transformation->rotation;

        entity->transformation->positionalVelocity += entity->transformation->positionalAcceleration * timeDelta;
        entity->transformation->position += entity->transformation->positionalVelocity * timeDelta;

        entity->transformation->rotationalVelocity += entity->transformation->rotationalAcceleration * timeDelta;
        entity->transformation->rotation += entity->transformation->rotationalVelocity * timeDelta;

        if (entity->drawable == NULL || entity->drawable->collidingLayers == 0) {
            continue;
        }

        Collision collision;
        for (Entity *otherEntity : m_game->entities) {
            if (entity == otherEntity) {
                continue;
            }

            if ((entity->drawable->collidingLayers & otherEntity->drawable->layer) == 0) {
                continue;
            }

            if (!checkCollision(entity, otherEntity, collision)) {
                continue;
            }

            entity->transformation->position = oldPosition;
            entity->transformation->rotation = oldRotation;
            break;
        }
    }
}
