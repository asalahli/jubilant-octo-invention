#pragma once

#include <SFML/Graphics.hpp>

#include "Component.hpp"
#include "Process.hpp"

class Game;

class GraphicsSystem : public Process {
    sf::Font *m_debuggerFont;
    sf::RenderWindow m_window;

    sf::Vector2f cameraPosition;
    float viewportSize;

    void clearWindow();
    void drawDebug(float timeDelta);
    void drawEntities();
    void drawGrid();
    void drawSkeleton(const Skeleton& skeleton, const unsigned int boneId, const sf::Transform& currentTransform);
    void drawBoundingBox(const b2Body& physicalBody, const sf::Transform& currentTransform);
public:
    GraphicsSystem(Game *game);
    ~GraphicsSystem();
    virtual void update(float timeDelta);
};
