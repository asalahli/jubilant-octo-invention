#pragma once

#include "Process.hpp"

class Game;

class InputSystem : public Process {
public:
	InputSystem(Game *game);
	~InputSystem();

	virtual void update(float timeDelta);
};
