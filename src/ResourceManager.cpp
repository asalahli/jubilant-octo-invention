#include "ResourceManager.hpp"

sf::Font *ResourceManager::loadFont(std::string fontName) {
	sf::Font *font = new sf::Font();

	// font->loadFromFile("../res/fonts/" + fontName);

	return font;
};
