#include "Game.hpp"
#include "LogicSystem.hpp"

LogicSystem::LogicSystem(Game *game)
	: Process(game)
{

}

LogicSystem::~LogicSystem() {

}

void LogicSystem::update(float timeDelta) {
	for (Entity *entity : m_game->entities) {
        entity->update(timeDelta);
	}
}
