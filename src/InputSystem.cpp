#include <SFML/Window.hpp>

#include "Game.hpp"
#include "InputSystem.hpp"

InputSystem::InputSystem(Game *game)
	: Process(game)
{

}

InputSystem::~InputSystem() {

}

void InputSystem::update(float timeDelta) {
	if (
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
	) {
		m_game->messages.push_back(MSG_MOVE_LEFT);
	}

	if (
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
	) {
		m_game->messages.push_back(MSG_MOVE_RIGHT);
	}

	if (
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
	) {
		m_game->messages.push_back(MSG_JUMP);
	}
}
