#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>


const unsigned int LAYER_PLAYER            = (1 << 0);
const unsigned int LAYER_STATIC_COLLIDABLE = (1 << 1);

struct Drawable {
    sf::FloatRect boundingBox;
    unsigned int collidingLayers;
    unsigned int layer;
    std::vector<sf::Sprite> sprites;
};

struct Transformation {
    sf::Vector2f position;
    sf::Vector2f positionalAcceleration;
    sf::Vector2f positionalVelocity;
    float rotation;
    float rotationalAcceleration;
    float rotationalVelocity;
};
