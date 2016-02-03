#pragma once

#include "SFML/Graphics.hpp"


class ResourceManager {
public:
	sf::Font *loadFont(std::string fontName);
};
