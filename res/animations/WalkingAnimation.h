#pragma once

const float WALK_ANIMATION_FRAME_DURATION = 0.125f;

/*
    Temporary function to hardcode skeleton and animation.
*/
void setWalkingAnimation(Entity *entity) {
    entity->skeleton->origin = sf::Vector2f(0.0f, 1.0f);
    entity->skeleton->bones.resize(BODY_PART_COUNT);

    entity->skeleton->bones[ROOT] = Bone(ROOT, 0.0f, 0);
    entity->skeleton->bones[HEAD] = Bone(HEAD, 0.36f, 90);
    entity->skeleton->bones[BODY] = Bone(BODY, 0.54f, 97);
    entity->skeleton->bones[UPPER_ARM_LEFT] = Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->skeleton->bones[LOWER_ARM_LEFT] = Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->skeleton->bones[UPPER_ARM_RIGHT] = Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->skeleton->bones[LOWER_ARM_RIGHT] = Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->skeleton->bones[UPPER_LEG_LEFT] = Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->skeleton->bones[LOWER_LEG_LEFT] = Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->skeleton->bones[UPPER_LEG_RIGHT] = Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->skeleton->bones[LOWER_LEG_RIGHT] = Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    entity->skeleton->bones[ROOT].children.push_back(BODY);
    entity->skeleton->bones[ROOT].children.push_back(UPPER_LEG_LEFT);
    entity->skeleton->bones[ROOT].children.push_back(UPPER_LEG_RIGHT);

    entity->skeleton->bones[BODY].children.push_back(HEAD);
    entity->skeleton->bones[BODY].children.push_back(UPPER_ARM_LEFT);
    entity->skeleton->bones[BODY].children.push_back(UPPER_ARM_RIGHT);

    entity->skeleton->bones[UPPER_ARM_LEFT].children.push_back(LOWER_ARM_LEFT);
    entity->skeleton->bones[UPPER_ARM_RIGHT].children.push_back(LOWER_ARM_RIGHT);
    entity->skeleton->bones[UPPER_LEG_LEFT].children.push_back(LOWER_LEG_LEFT);
    entity->skeleton->bones[UPPER_LEG_RIGHT].children.push_back(LOWER_LEG_RIGHT);

    entity->animation->keyFrames.resize(BODY_PART_COUNT);

    /*
        Key Frame 1
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 2
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 3
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 4
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 5
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 6
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);

    /*
        Key Frame 7
    */
    entity->animation->keyFrames[ROOT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(ROOT, 0.0f, 0);
    entity->animation->keyFrames[HEAD].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(HEAD, 0.36f, 90);
    entity->animation->keyFrames[BODY].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(BODY, 0.54f, 97);
    entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_LEFT, 0.36f, 231);
    entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_LEFT, 0.36f, 268);
    entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_ARM_RIGHT, 0.36f, 304);
    entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_ARM_RIGHT, 0.36f, 322);
    entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_LEFT, 0.41f, 252);
    entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(UPPER_LEG_RIGHT, 0.41f, 296);
    entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION, Bone(LOWER_LEG_RIGHT, 0.46f, 288);
}
