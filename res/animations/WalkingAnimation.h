#pragma once

const float WALK_ANIMATION_FRAME_DURATION[8] = {
    0.125f,
    0.125f,
    0.125f,
    0.125f,
    0.125f,
    0.125f,
    0.125f,
    0.125f,
};

/*
    Temporary function to hardcode skeleton and animation.
*/
void setWalkingAnimation(Entity *entity) {
    entity->skeleton->origin = sf::Vector2f(0.0f, 1.0f);
    entity->skeleton->bones.resize(BODY_PART_COUNT);

    entity->skeleton->bones[ROOT] = Bone(ROOT, 0.0f, 0);
    entity->skeleton->bones[HEAD] = Bone(HEAD, 0.36f, 90);
    entity->skeleton->bones[BODY] = Bone(BODY, 0.54f, 95);
    entity->skeleton->bones[UPPER_ARM_LEFT] = Bone(UPPER_ARM_LEFT, 0.36f, 300);
    entity->skeleton->bones[LOWER_ARM_LEFT] = Bone(LOWER_ARM_LEFT, 0.36f, 320);
    entity->skeleton->bones[UPPER_ARM_RIGHT] = Bone(UPPER_ARM_RIGHT, 0.36f, 230);
    entity->skeleton->bones[LOWER_ARM_RIGHT] = Bone(LOWER_ARM_RIGHT, 0.36f, 270);
    entity->skeleton->bones[UPPER_LEG_LEFT] = Bone(UPPER_LEG_LEFT, 0.41f, 250);
    entity->skeleton->bones[LOWER_LEG_LEFT] = Bone(LOWER_LEG_LEFT, 0.46f, 235);
    entity->skeleton->bones[UPPER_LEG_RIGHT] = Bone(UPPER_LEG_RIGHT, 0.41f, 290);
    entity->skeleton->bones[LOWER_LEG_RIGHT] = Bone(LOWER_LEG_RIGHT, 0.46f, 290);

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

    for (unsigned int i = 0; i < 60; i++) {
        /*
            Key Frame 1
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_ARM_LEFT, 0.36f, 300)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_ARM_LEFT, 0.36f, 325)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_ARM_RIGHT, 0.36f, 235)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_ARM_RIGHT, 0.36f, 255)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_LEG_LEFT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_LEG_LEFT, 0.46f, 225)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_LEG_RIGHT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_LEG_RIGHT, 0.46f, 275)));

        /*
            Key Frame 2
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(UPPER_ARM_LEFT, 0.36f, 280)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(LOWER_ARM_LEFT, 0.36f, 300)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(UPPER_ARM_RIGHT, 0.36f, 255)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(LOWER_ARM_RIGHT, 0.36f, 270)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(UPPER_LEG_LEFT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(LOWER_LEG_LEFT, 0.46f, 210)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(UPPER_LEG_RIGHT, 0.41f, 270)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[2], Bone(LOWER_LEG_RIGHT, 0.46f, 265)));

        /*
            Key Frame 3
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(UPPER_ARM_LEFT, 0.36f, 265)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(LOWER_ARM_LEFT, 0.36f, 285)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(UPPER_ARM_RIGHT, 0.36f, 280)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(LOWER_ARM_RIGHT, 0.36f, 300)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(UPPER_LEG_LEFT, 0.41f, 305)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(LOWER_LEG_LEFT, 0.46f, 250)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(UPPER_LEG_RIGHT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[3], Bone(LOWER_LEG_RIGHT, 0.46f, 250)));

        /*
            Key Frame 4
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(UPPER_ARM_LEFT, 0.36f, 230)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(LOWER_ARM_LEFT, 0.36f, 270)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(UPPER_ARM_RIGHT, 0.36f, 300)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(LOWER_ARM_RIGHT, 0.36f, 320)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(UPPER_LEG_LEFT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(LOWER_LEG_LEFT, 0.46f, 290)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(UPPER_LEG_RIGHT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[4], Bone(LOWER_LEG_RIGHT, 0.46f, 235)));

        /*
            Key Frame 5
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(UPPER_ARM_LEFT, 0.36f, 235)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(LOWER_ARM_LEFT, 0.36f, 255)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(UPPER_ARM_RIGHT, 0.36f, 300)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(LOWER_ARM_RIGHT, 0.36f, 325)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(UPPER_LEG_LEFT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(LOWER_LEG_LEFT, 0.46f, 275)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(UPPER_LEG_RIGHT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[5], Bone(LOWER_LEG_RIGHT, 0.46f, 225)));

        /*
            Key Frame 6
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(UPPER_ARM_LEFT, 0.36f, 255)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(LOWER_ARM_LEFT, 0.36f, 270)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(UPPER_ARM_RIGHT, 0.36f, 280)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(LOWER_ARM_RIGHT, 0.36f, 300)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(UPPER_LEG_LEFT, 0.41f, 270)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(LOWER_LEG_LEFT, 0.46f, 265)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(UPPER_LEG_RIGHT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[6], Bone(LOWER_LEG_RIGHT, 0.46f, 210)));

        /*
            Key Frame 7
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(UPPER_ARM_LEFT, 0.36f, 280)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(LOWER_ARM_LEFT, 0.36f, 300)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(UPPER_ARM_RIGHT, 0.36f, 265)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(LOWER_ARM_RIGHT, 0.36f, 285)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(UPPER_LEG_LEFT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(LOWER_LEG_LEFT, 0.46f, 250)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(UPPER_LEG_RIGHT, 0.41f, 305)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[7], Bone(LOWER_LEG_RIGHT, 0.46f, 250)));

        /*
            Key Frame 0
        */
        entity->animation->keyFrames[UPPER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_ARM_LEFT, 0.36f, 300)));
        entity->animation->keyFrames[LOWER_ARM_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_ARM_LEFT, 0.36f, 320)));
        entity->animation->keyFrames[UPPER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_ARM_RIGHT, 0.36f, 230)));
        entity->animation->keyFrames[LOWER_ARM_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_ARM_RIGHT, 0.36f, 270)));
        entity->animation->keyFrames[UPPER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_LEG_LEFT, 0.41f, 250)));
        entity->animation->keyFrames[LOWER_LEG_LEFT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_LEG_LEFT, 0.46f, 235)));
        entity->animation->keyFrames[UPPER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(UPPER_LEG_RIGHT, 0.41f, 290)));
        entity->animation->keyFrames[LOWER_LEG_RIGHT].push(KeyFrame(0.0f, WALK_ANIMATION_FRAME_DURATION[1], Bone(LOWER_LEG_RIGHT, 0.46f, 290)));
    }
}
