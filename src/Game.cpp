#include "Game.hpp"
#include "AnimationSystem.hpp"
#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"
#include "LogicSystem.hpp"
#include "PhysicsSystem.hpp"
#include "Player.hpp"

#include "../res/animations/WalkingAnimation.h"

bool DEBUG_isMouseClicked = false;

Game::Game()
    : isRunning(false)
{
    systems.push_back(new InputSystem(this));
    systems.push_back(new LogicSystem(this));
    systems.push_back(new AnimationSystem(this));
    systems.push_back(new PhysicsSystem(this));
    systems.push_back(new GraphicsSystem(this));

    playerEntityId = 0;

    entities.push_back(new Player(this));
    {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.allowSleep = false;
        bodyDef.bullet = true;
        bodyDef.position.Set(-6.0f, 1.0f);
        bodyDef.fixedRotation = true;
        entities[0]->physicalBody = physicalWorld->CreateBody(&bodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(0.5f, 1.0f, b2Vec2(0.0f, 1.0f), 0);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;

        entities[0]->physicalBody->CreateFixture(&fixtureDef);

        entities[0]->skeleton = new Skeleton();
        entities[0]->animation = new Animation();
        setWalkingAnimation(entities[0]);

        // entities[0]->animation = new Animation();
        // entities[0]->animation->keyFrames.resize(5);
        // entities[0]->animation->keyFrames[1].push(KeyFrame(0.0f, 5.0f, Bone(1, 0.5f, 180)));
        // entities[0]->animation->keyFrames[1].push(KeyFrame(0.0f, 5.0f, Bone(1, 0.5f, 225)));
        // entities[0]->animation->keyFrames[2].push(KeyFrame(0.0f, 10.0f, Bone(2, 0.5f, 405)));
        // entities[0]->animation->keyFrames[4].push(KeyFrame(0.0f, 10.0f, Bone(4, 0.2f, 60)));
    }

    entities.push_back(new Entity(this));
    {
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(-10.0f, 0.0f);

        entities[1]->physicalBody = physicalWorld->CreateBody(&groundBodyDef);

        b2PolygonShape groundBox;
        groundBox.SetAsBox(5.0f, 0.5f, b2Vec2(5.0f, -0.5f), 0);

        entities[1]->physicalBody->CreateFixture(&groundBox, 0.0f);
    }

    entities.push_back(new Entity(this));
    {
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f, 1.0f);

        entities[2]->physicalBody = physicalWorld->CreateBody(&groundBodyDef);

        b2PolygonShape groundBox;
        groundBox.SetAsBox(5.0f, 1.0f, b2Vec2(5.0f, -1.0f), 0);

        entities[2]->physicalBody->CreateFixture(&groundBox, 0.0f);
    }
}

Game::~Game() {
    for (Process *system : systems) {
        delete system;
    }

    for (Entity *entity : entities) {
        delete entity;
    }

    if (physicalWorld) {
        delete physicalWorld;
    }
}

void Game::sleep(int ms) {
    while (clock.getElapsedTime().asMilliseconds() < ms) {
        sf::sleep(sf::milliseconds(5));
    }
}

void Game::run() {
    isRunning = true;
    clock.restart();

    // for (unsigned int i=0; i<25; i++) {
    while (isRunning) {
        sleep(MIN_FRAME_DELAY);
        float timeDelta = clock.restart().asMilliseconds() / 1000.0f;

        messages.clear();

        for (Process *system : systems) {
            system->update(timeDelta);
        }
    }
}
