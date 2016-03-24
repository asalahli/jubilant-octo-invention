#include <sstream>
#include <string>

#include "Game.hpp"
#include "GraphicsSystem.hpp"
#include "PhysicsSystem.hpp"


GraphicsSystem::GraphicsSystem(Game *game)
    : Process(game)
    , cameraPosition(0.0f, 2.5f)
    , viewportSize(9)
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
        line.setPosition(sf::Vector2f(i-1.0f, 0.0f));
        line.setSize(sf::Vector2f(1.0f, m_window.getSize().y * 1.0f));
        m_window.draw(line);
    }

    for (unsigned int i = 50; i < m_window.getSize().y; i += 50) {
        line.setPosition(sf::Vector2f(0.0f, i-1.0f));
        line.setSize(sf::Vector2f(m_window.getSize().x * 1.0f, 1.0f));
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

    ss.str("");
    ss << leftSide << padding << rightSide;
    std::string debugText = ss.str();

    sf::RectangleShape panel;
    sf::Text text;

    panel.setFillColor(sf::Color(200, 200, 200));
    panel.setPosition(sf::Vector2f(0, 430));
    panel.setSize(sf::Vector2f(800, 20));

    text.setFont(*m_debuggerFont);
	text.setString(debugText);
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

void GraphicsSystem::drawBoundingBox(const b2Body& physicalBody, const sf::Transform& currentTransform) {
    const b2PolygonShape *shape = (b2PolygonShape *) physicalBody.GetFixtureList()->GetShape();

    sf::Vertex boundingBox[5];
    for (unsigned int i=0; i<4; i++) {
        boundingBox[i].position = sf::Vector2f(shape->m_vertices[i].x, shape->m_vertices[i].y);
        boundingBox[i].color = sf::Color::Green;
    }

    boundingBox[4] = boundingBox[0];
    m_window.draw(boundingBox, 5, sf::LinesStrip, currentTransform);
}

void GraphicsSystem::drawSkeleton(const Skeleton& skeleton, const unsigned int boneId, const sf::Transform& currentTransform) {
    sf::Vertex boneBox[5];

    boneBox[0] = sf::Vertex(sf::Vector2f(0.0f, 0.05f), sf::Color::Red);
    boneBox[1] = sf::Vertex(sf::Vector2f(skeleton.bones[boneId].length, 0.05f), sf::Color::Red);
    boneBox[2] = sf::Vertex(sf::Vector2f(skeleton.bones[boneId].length, -0.05f), sf::Color::Red);
    boneBox[3] = sf::Vertex(sf::Vector2f(0.0f, -0.05f), sf::Color::Red);
    boneBox[4] = boneBox[0];

    sf::Transform boneTransform(currentTransform);
    boneTransform.rotate(skeleton.bones[boneId].rotation);

    m_window.draw(boneBox, 5, sf::LinesStrip, boneTransform);

    sf::Vector2f newOrigin = sf::Transform().rotate(skeleton.bones[boneId].rotation).transformPoint(skeleton.bones[boneId].length, 0.0f);
    sf::Transform newTransform(currentTransform);
    newTransform.translate(newOrigin);

    for (unsigned int childBoneId : skeleton.bones[boneId].children) {
        drawSkeleton(skeleton, childBoneId, newTransform);
    }
}

void GraphicsSystem::drawEntities() {
    float h = viewportSize;
    float w = h * m_window.getSize().x / m_window.getSize().y;

    {
        float playerPos = m_game->entities[m_game->playerEntityId]->physicalBody->GetPosition().x - cameraPosition.x;

        if (playerPos < 0 && (w / 2.0) + playerPos < 3) {
            cameraPosition.x -= 3 - (w / 2.0f) - playerPos;
        }
        else if (playerPos > 0 && (w / 2.0) - playerPos < 3) {
            cameraPosition.x += 3 - (w / 2.0f) + playerPos;
        }
    }

    sf::Vector2f cameraTranslation = cameraPosition - sf::Vector2f(w / 2.0f, h / 2.0f);
    float cameraScale = m_window.getSize().y / h;

    sf::Transform viewTransform = sf::Transform(sf::Transform::Identity)
        .translate(0, m_window.getSize().y * 1.0f)
        .scale(cameraScale, -cameraScale)
        .translate(-cameraTranslation);

    for (Entity *entity : m_game->entities) {
        if (entity->physicalBody == NULL) {
            continue;
        }

        b2Vec2 entityPosition = entity->physicalBody->GetPosition();
        sf::Transform modelTransform(viewTransform);
        modelTransform.translate(entityPosition.x, entityPosition.y);

        drawBoundingBox(*entity->physicalBody, modelTransform);

        if (entity->skeleton != NULL) {
            drawSkeleton(*entity->skeleton, 0, modelTransform * sf::Transform().translate(entity->skeleton->origin));
        }
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
