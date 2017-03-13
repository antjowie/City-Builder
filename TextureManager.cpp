#include "TextureManager.h"

void TextureManager::LoadTexture(const std::string & textureName, const std::string & fileName)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);

	textures.insert(std::make_pair(textureName, texture));
}

sf::Texture & TextureManager::GetTexture(const std::string & textureName)
{
	return textures.at(textureName);
}
