#pragma once

#include "Process.hpp"

class Game;

class AnimationSystem : public Process {
    void animateEntity(Entity *entity, float timeDelta);
    void animateBone(Bone& bone, KeyFrame& keyFrame, float timeDelta);
public:
    AnimationSystem(Game *game);
    ~AnimationSystem();

    virtual void update(float timeDelta);
};
