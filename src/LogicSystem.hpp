#pragma once

#include "Process.hpp"

class Game;

class LogicSystem : public Process {
public:
	LogicSystem(Game *game);
	~LogicSystem();

	virtual void update(float timeDelta);
};
