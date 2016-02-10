#include "Entity.hpp"
#include "Game.hpp"


Entity::Entity(Game *game)
    : Process(game)
    , drawable(NULL)
    , physicalBody(NULL)
{

}

Entity::~Entity() {
    if (drawable != NULL) {
        delete drawable;
    }
}
