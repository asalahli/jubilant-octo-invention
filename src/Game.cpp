#include "Game.hpp"
#include "GraphicsSystem.hpp"
#include "InputSystem.hpp"
#include "LogicSystem.hpp"
#include "PhysicsSystem.hpp"
#include "Player.hpp"


Game::Game()
    : isRunning(false)
{
    // systems.push_back(new InputSystem(this));
    // systems.push_back(new LogicSystem(this));

    physicsSystem = new PhysicsSystem(this);
    graphicsSystem = new GraphicsSystem(this);
    systems.push_back(physicsSystem);
    systems.push_back(graphicsSystem);

    // playerEntityId = 0;
    // entities.push_back(new Player(this));
    // entities[0]->drawable = new Drawable();
    // entities[0]->drawable->boundingBox = sf::FloatRect(-25, -100, 50, 100);
    // entities[0]->drawable->collidingLayers = LAYER_STATIC_COLLIDABLE;
    // entities[0]->drawable->layer = LAYER_PLAYER;
    // entities[0]->transformation = new Transformation();
    // entities[0]->transformation->position = sf::Vector2f(400, 350);

    // entities.push_back(new Entity(this));
    // entities[1]->drawable = new Drawable();
    // entities[1]->drawable->boundingBox = sf::FloatRect(0, 0, 500, 50);
    // entities[1]->drawable->layer = LAYER_STATIC_COLLIDABLE;
    // entities[1]->transformation = new Transformation();
    // entities[1]->transformation->position = sf::Vector2f(0, 351);

    // entities.push_back(new Entity(this));
    // entities[2]->drawable = new Drawable();
    // entities[2]->drawable->boundingBox = sf::FloatRect(0, 0, 500, 100);
    // entities[2]->drawable->layer = LAYER_STATIC_COLLIDABLE;
    // entities[2]->transformation = new Transformation();
    // entities[2]->transformation->position = sf::Vector2f(501, 301);

    // entities[0]->transformation->positionalVelocity = sf::Vector2f(50, -250);
    // entities[0]->transformation->positionalAcceleration = sf::Vector2f(-12.5, 125);
    // entities[0]->transformation->rotationalVelocity = 60;
    // entities[0]->transformation->rotationalAcceleration = -30;
}

Game::~Game() {
    for (Process *system : systems) {
        delete system;
    }

    for (Entity *entity : entities) {
        delete entity;
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
