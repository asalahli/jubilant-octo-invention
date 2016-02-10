#pragma once

#include <SFML/Graphics.hpp>

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
public:
    GraphicsSystem(Game *game);
    ~GraphicsSystem();
    virtual void update(float timeDelta);
};
