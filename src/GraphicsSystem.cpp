// #include <cmath>
#include <sstream>

#include "Game.hpp"
#include "GraphicsSystem.hpp"


GraphicsSystem::GraphicsSystem(Game *game)
    : Process(game)
{
    m_debuggerFont = m_game->resourceManager.loadFont("UbuntuMono-R.ttf");
    m_window.create(sf::VideoMode(800, 450), "SFML works!", sf::Style::Close | sf::Style::Titlebar);
}

GraphicsSystem::~GraphicsSystem() {
    m_window.close();
}

void GraphicsSystem::drawGrid() {
    sf::RectangleShape line;
    line.setOutlineColor(sf::Color::Transparent);
    line.setOutlineThickness(1);
    line.setFillColor(sf::Color(150, 150, 150));

    for (unsigned int i = 50; i < m_window.getSize().x; i += 50) {
        line.setPosition(sf::Vector2f(i-1, 0));
        line.setSize(sf::Vector2f(1, m_window.getSize().y));
        m_window.draw(line);
    }

    for (unsigned int i = 50; i < m_window.getSize().y; i += 50) {
        line.setPosition(sf::Vector2f(0, i-1));
        line.setSize(sf::Vector2f(m_window.getSize().x, 1));
        m_window.draw(line);
    }
}

void GraphicsSystem::drawDebug(float timeDelta) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

    std::stringstream ss;
    ss << "-:-" << mousePosition.x << "," << mousePosition.y << "    " << floor(1/timeDelta) << " fps";

    std::string leftSide = "a";
    std::string rightSide = ss.str();
    std::string padding;

    for (unsigned int i = 0; i < 113-(leftSide.length() + rightSide.length()); i++) {
        padding += " ";
    }

    sf::RectangleShape panel;
    sf::Text text;

    panel.setFillColor(sf::Color(200, 200, 200));
    panel.setPosition(sf::Vector2f(0, 430));
    panel.setSize(sf::Vector2f(800, 20));

    text.setFont(*m_debuggerFont);
    text.setString(leftSide + padding + rightSide);
    text.setCharacterSize(14);
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(4, 431));

    m_window.draw(panel);
    m_window.draw(text);
}

void GraphicsSystem::clearWindow() {
    m_window.clear();
    sf::RectangleShape bg(sf::Vector2f(m_window.getSize()));
    bg.setFillColor(sf::Color(50, 50, 50));
    m_window.draw(bg);
}

void GraphicsSystem::drawEntities() {
    sf::RenderStates renderStates;
    sf::RectangleShape boundingBox;

    boundingBox.setOutlineColor(sf::Color::Green);
    boundingBox.setOutlineThickness(1);
    boundingBox.setFillColor(sf::Color::Transparent);

    for (Entity *entity : m_game->entities) {
        if (entity->drawable == NULL || entity->transformation == NULL) {
            continue;
        }

        renderStates.transform = sf::Transform::Identity;
        renderStates.transform.translate(entity->transformation->position);
        renderStates.transform.rotate(entity->transformation->rotation);

        boundingBox.setSize(sf::Vector2f(entity->drawable->boundingBox.width-2, entity->drawable->boundingBox.height-2));
        boundingBox.setPosition(sf::Vector2f(entity->drawable->boundingBox.left, entity->drawable->boundingBox.top));

        m_window.draw(boundingBox, renderStates);
    }
}

void GraphicsSystem::update(float timeDelta) {
    sf::Event event;
    if (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_game->isRunning = false;
        }
    }

    clearWindow();
    drawGrid();
    drawEntities();
    drawDebug(timeDelta);
    m_window.display();
}
