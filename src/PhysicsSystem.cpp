#include "Game.hpp"
#include "PhysicsSystem.hpp"


const b2Vec2 GRAVITY(0.0f, -10.0f);

PhysicsSystem::PhysicsSystem(Game *game)
    : Process(game)
{
    b2Vec2 gravity(0.0f, -10.0f);

    m_game->physicalWorld = new b2World(gravity);
}

PhysicsSystem::~PhysicsSystem() {

}

void PhysicsSystem::update(float timeDelta) {
    // for (Entity *entity : m_game->entities) {
    //     if (entity->transformation == NULL) {
    //         continue;
    //     }

    //     sf::Vector2f oldPosition = entity->transformation->position;
    //     float oldRotation = entity->transformation->rotation;

    //     entity->transformation->positionalVelocity += entity->transformation->positionalAcceleration * timeDelta;
    //     entity->transformation->position += entity->transformation->positionalVelocity * timeDelta;

    //     entity->transformation->rotationalVelocity += entity->transformation->rotationalAcceleration * timeDelta;
    //     entity->transformation->rotation += entity->transformation->rotationalVelocity * timeDelta;

    //     if (entity->drawable == NULL || entity->drawable->collidingLayers == 0) {
    //         continue;
    //     }

    //     Collision collision;
    //     for (Entity *otherEntity : m_game->entities) {
    //         if (entity == otherEntity) {
    //             continue;
    //         }

    //         if ((entity->drawable->collidingLayers & otherEntity->drawable->layer) == 0) {
    //             continue;
    //         }

    //         if (!checkCollision(entity, otherEntity, collision)) {
    //             continue;
    //         }

    //         entity->transformation->position = oldPosition;
    //         entity->transformation->rotation = oldRotation;
    //         break;
    //     }
    // }

    float timeStep = MIN_FRAME_DELAY / 1000.0;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    m_game->physicalWorld->Step(timeStep, velocityIterations, positionIterations);
}
