#include "ResourceManager.hpp"
#include "../res/fonts/UbuntuMono-R.h"

sf::Font *ResourceManager::loadFont(std::string fontName) {
	sf::Font *font = new sf::Font();

	font->loadFromMemory(res_fonts_UbuntuMono_R_ttf, res_fonts_UbuntuMono_R_ttf_len);

	return font;
};
