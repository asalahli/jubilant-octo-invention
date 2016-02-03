#pragma once

class Game;

class Process {
protected:
	Game *m_game;
public:
	Process(Game *game=NULL) : m_game(game) {};
	virtual void update(float timeDelta) = 0;
};
