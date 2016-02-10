// #include <cmath>
#include <sstream>

#include "Game.hpp"
#include "GraphicsSystem.hpp"
#include "PhysicsSystem.hpp"


GraphicsSystem::GraphicsSystem(Game *game)
    : Process(game)
    , cameraPosition(0.0f, 2.5f)
    , viewportSize(9)
{
    // m_debuggerFont = m_game->resourceManager.loadFont("UbuntuMono-R.ttf");
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
    // sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

    // std::stringstream ss;
    // ss << "-:-" << mousePosition.x << "," << mousePosition.y << "    " << floor(1/timeDelta) << " fps";

    // std::string leftSide = "a";
    // std::string rightSide = ss.str();
    // std::string padding;

    // for (unsigned int i = 0; i < 113-(leftSide.length() + rightSide.length()); i++) {
    //     padding += " ";
    // }

    // sf::RectangleShape panel;
    // sf::Text text;

    // panel.setFillColor(sf::Color(200, 200, 200));
    // panel.setPosition(sf::Vector2f(0, 430));
    // panel.setSize(sf::Vector2f(800, 20));

    // // text.setFont(*m_debuggerFont);
    // text.setString(leftSide + padding + rightSide);
    // text.setCharacterSize(14);
    // text.setColor(sf::Color::Black);
    // text.setPosition(sf::Vector2f(4, 431));

    // m_window.draw(panel);
    // // m_window.draw(text);
}

void GraphicsSystem::clearWindow() {
    m_window.clear();
    sf::RectangleShape bg(sf::Vector2f(m_window.getSize()));
    bg.setFillColor(sf::Color(50, 50, 50));
    m_window.draw(bg);
}

void GraphicsSystem::drawEntities() {
    float h = viewportSize;
    float w = h * m_window.getSize().x / m_window.getSize().y;

    {
        float playerPos = m_game->entities[m_game->playerEntityId]->physicalBody->GetPosition().x - cameraPosition.x;

        if (playerPos < 0 && (w / 2.0) + playerPos < 3) {
            cameraPosition.x -= 3 - (w / 2.0) - playerPos;
        }
        else if (playerPos > 0 && (w / 2.0) - playerPos < 3) {
            cameraPosition.x += 3 - (w / 2.0) + playerPos;
        }
    }

    sf::Vector2f cameraTranslation = cameraPosition - sf::Vector2f(w / 2.0f, h / 2.0f);
    float cameraScale = m_window.getSize().y / h;

    // std::cout << "cameraTranslation = (" << cameraTranslation.x << ", " << cameraTranslation.y << ")" << std::endl;
    // std::cout << "cameraScale = " << cameraScale << std::endl;

    sf::Vertex boundingBox[5];

    sf::RenderStates renderStates;

    renderStates.transform = sf::Transform::Identity;

    for (const b2Body *body = m_game->physicalWorld->GetBodyList(); body; body = body->GetNext()) {
        float x = body->GetPosition().x;
        float y = body->GetPosition().y;

        const b2PolygonShape *shape = (b2PolygonShape *) body->GetFixtureList()->GetShape();

        for (unsigned int i=0; i<4; i++) {
            boundingBox[i].position = sf::Vector2f(x + shape->m_vertices[i].x, y + shape->m_vertices[i].y);
            boundingBox[i].color = sf::Color::Green;
        }

        // std::cout << boundingBox[0].position.x << " " << boundingBox[0].position.y << " translates to: ";

        for (unsigned int i=0; i<4; i++) {
            boundingBox[i].position = (boundingBox[i].position - cameraTranslation) * cameraScale;
            boundingBox[i].position.y = m_window.getSize().y - boundingBox[i].position.y;
        }

        boundingBox[4] = boundingBox[0];
        m_window.draw(boundingBox, 5, sf::LinesStrip, renderStates);
        // std::cout << boundingBox[0].position.x << " " << boundingBox[0].position.y << std::endl;
    }

    // std::cout << std::endl;

    // for (Entity *entity : m_game->entities) {
    //     if (entity->drawable == NULL || entity->transformation == NULL) {
    //         continue;
    //     }

    //     renderStates.transform = sf::Transform::Identity;
    //     renderStates.transform.translate(entity->transformation->position);
    //     renderStates.transform.rotate(entity->transformation->rotation);

    //     boundingBox.setSize(sf::Vector2f(entity->drawable->boundingBox.width-2, entity->drawable->boundingBox.height-2));
    //     boundingBox.setPosition(sf::Vector2f(entity->drawable->boundingBox.left, entity->drawable->boundingBox.top));

    //     m_window.draw(boundingBox, renderStates);
    // }


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
