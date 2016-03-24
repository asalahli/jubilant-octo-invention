#include "Game.hpp"
#include "AnimationSystem.hpp"

AnimationSystem::AnimationSystem(Game *game)
    : Process(game)
{

}

AnimationSystem::~AnimationSystem() {

}

void AnimationSystem::animateBone(Bone& bone, KeyFrame& keyFrame, float timeDelta) {
    const float start = keyFrame.currentTime;
    const float end = keyFrame.finishTime;
    const float now = end - start > timeDelta ? start + timeDelta : end;

    if (end == start) {
        return;
    }

    bone.length += (now - start) * (keyFrame.finishState.length - bone.length) / (end - start);
    bone.rotation += (now - start) * (keyFrame.finishState.rotation - bone.rotation) / (end - start);

    keyFrame.currentTime += timeDelta;
}

void AnimationSystem::animateEntity(Entity *entity, float timeDelta) {
    float originalTimeDelta = timeDelta;

    for (Bone& currentBone : entity->skeleton->bones) {
        const unsigned int boneId = currentBone.id;

        KeyFrameQueue& keyFrameQueue = entity->animation->keyFrames[boneId];

        timeDelta = originalTimeDelta;
        while (!keyFrameQueue.empty() && timeDelta > 0) {
            KeyFrame& currentKeyFrame = keyFrameQueue.front();

            animateBone(currentBone, currentKeyFrame, timeDelta);

            if (currentKeyFrame.currentTime > currentKeyFrame.finishTime) {
                timeDelta = currentKeyFrame.currentTime - currentKeyFrame.finishTime;
                keyFrameQueue.pop();
            }
            else {
                timeDelta = 0;
            }
        }
    }
}

void AnimationSystem::update(float timeDelta) {
    for (Entity *entity : m_game->entities) {
        if (entity->animation == NULL || entity->skeleton == NULL) {
            return;
        }

        animateEntity(entity, timeDelta);
    }
}
