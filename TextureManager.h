#pragma once

#include "SFML\Graphics.hpp"

#include <map>

class TextureManager
{
private:
	std::map<std::string, sf::Texture> textures;
	
public:

	void LoadTexture(const std::string& textureName, const std::string& fileName);
	sf::Texture& GetTexture(const std::string& textureName);
};

