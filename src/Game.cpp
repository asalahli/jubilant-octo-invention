#include "Game.hpp"
#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"
#include "LogicSystem.hpp"
#include "PhysicsSystem.hpp"
#include "Player.hpp"


Game::Game()
    : isRunning(false)
{
    systems.push_back(new InputSystem(this));
    systems.push_back(new LogicSystem(this));
    systems.push_back(new PhysicsSystem(this));
    systems.push_back(new GraphicsSystem(this));

    playerEntityId = 0;

    entities.push_back(new Player(this));
    {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.allowSleep = false;
        bodyDef.bullet = true;
        bodyDef.position.Set(-6.0f, 4.0f);
        bodyDef.fixedRotation = true;
        entities[0]->physicalBody = physicalWorld->CreateBody(&bodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(0.5f, 1.0f, b2Vec2(0.0f, 1.0f), 0);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;

        entities[0]->physicalBody->CreateFixture(&fixtureDef);
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
        float timeDelta = clock.restart().asMilliseconds() / 1000.0;

        messages.clear();

        for (Process *system : systems) {
            system->update(timeDelta);
        }
    }
}
