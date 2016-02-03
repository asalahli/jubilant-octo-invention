#include "Entity.hpp"
#include "Game.hpp"


Entity::Entity(Game *game)
    : Process(game)
    , drawable(NULL)
    , transformation(NULL)
{

}

Entity::~Entity() {
    if (drawable != NULL) {
        delete drawable;
    }

    if (transformation != NULL) {
        delete transformation;
    }
}
