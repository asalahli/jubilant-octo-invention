#include "Entity.hpp"
#include "Game.hpp"


Entity::Entity(Game *game)
    : Process(game)
    , drawable(NULL)
    , physicalBody(NULL)
    , skeleton(NULL)
    , animation(NULL)
{

}

Entity::~Entity() {
    if (drawable != NULL) {
        delete drawable;
    }
}
