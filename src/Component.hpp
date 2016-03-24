#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <queue>


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


struct Bone {
    unsigned int id;
    float length;
    float rotation;
    std::vector<unsigned int> children;

    Bone(unsigned int id, float length, float rotation)
        : id(id), length(length), rotation(rotation) {};

    Bone() : id(0), length(0), rotation(0) {};
};


struct Skeleton {
    sf::Vector2f origin;
    std::vector<Bone> bones;
};


struct KeyFrame {
    float currentTime;
    float finishTime;
    Bone finishState;

    KeyFrame(float currentTime, float finishTime, Bone finishState)
        : currentTime(currentTime), finishTime(finishTime), finishState(finishState) {};
};


typedef std::queue<KeyFrame> KeyFrameQueue;


struct Animation {
    std::vector<KeyFrameQueue> keyFrames;
};
