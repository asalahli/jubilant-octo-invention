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

    // std::cout << "Before animation: " << entity->animation->keyFrames[7].size() << " key frames. ";
    // std::cout << entity->animation->keyFrames[7].front().currentTime << " elapsed.";
    // std::cout << std::endl;

    for (Bone& currentBone : entity->skeleton->bones) {
        const unsigned int boneId = currentBone.id;

        // std::cout << "Bone " << boneId << " was " << currentBone.rotation;

        KeyFrameQueue& keyFrameQueue = entity->animation->keyFrames[boneId];

        timeDelta = originalTimeDelta;
        while (!keyFrameQueue.empty() && timeDelta > 0) {
            KeyFrame& currentKeyFrame = keyFrameQueue.front();

            animateBone(currentBone, currentKeyFrame, timeDelta);

            if (currentKeyFrame.currentTime >= currentKeyFrame.finishTime) {
                timeDelta = currentKeyFrame.currentTime - currentKeyFrame.finishTime;
                keyFrameQueue.pop();
            }
            else {
                timeDelta = 0;
            }
        }

        // std::cout << ", is now " << currentBone.rotation << std::endl;
    }

    // std::cout << "After animation: " << entity->animation->keyFrames[7].size() << " key frames. ";
    // std::cout << entity->animation->keyFrames[7].front().currentTime << " elapsed.";
    // std::cout << std::endl;

}

void AnimationSystem::update(float timeDelta) {
    for (Entity *entity : m_game->entities) {
        if (entity->animation == NULL || entity->skeleton == NULL) {
            return;
        }

        //
        //  For debugging purposes
        //
        // if (DEBUG_isMouseClicked) {
        //     std::cout << "animation system: mouse clicked" << std::endl;
        //     animateEntity(entity, 0.125f);
        //     std::cout << std::endl;
        // }
        // continue;

        animateEntity(entity, timeDelta);
    }
}
