#include "Game.hpp"
#include "PhysicsSystem.hpp"


const b2Vec2 GRAVITY(0.0f, -10.0f);

PhysicsSystem::PhysicsSystem(Game *game)
    : Process(game)
{
    b2Vec2 gravity(0.0f, -10.0f);

    m_physicalWorld = new b2World(gravity);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = m_physicalWorld->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 1.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = m_physicalWorld->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
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

    m_physicalWorld->Step(timeStep, velocityIterations, positionIterations);
}
