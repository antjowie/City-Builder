#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(const unsigned int tileSize, const unsigned int height, sf::Texture & texture, const std::vector<Animation>& animations, const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel, const unsigned int maxLevels):
	tileType(tileType),
	tileVariant(0),
	cost(cost),
	population(0),
	maxPopPerLevel(maxPopPerLevel),
	maxLevels(maxLevels),
	production(production),
	storedGoods(storedGoods)
{
	sprite.setOrigin(sf::Vector2f(0.f, tileSize*(height - 1)));
	sprite.setTexture(texture);
	animHandler.frameSize = sf::IntRect(0, 0, tileSize * 2, tileSize*height);
	for (auto animation : animations) {
		animHandler.AddAnim(animation);
	}
	animHandler.Update(0.0f);
}

void Tile::Draw(sf::RenderWindow & window, const float dt)
{
	animHandler.ChangeAnim(tileVariant);
	animHandler.Update(dt);
	sprite.setTextureRect(animHandler.bounds);
	window.draw(sprite);
}

void Tile::Update()
{
	if (tileType == TileType::RESIDENTIAL ||
		tileType == TileType::COMMERCIAL ||
		tileType == TileType::INDUSTRIAL &&
		population == maxPopPerLevel * (tileVariant + 1) &&
		tileVariant < maxLevels) {
		if (rand() % int(1e4) < 1e2 / (tileVariant + 1)) ++tileVariant;
	}
}

std::string Tile::getCost()
{
	return std::to_string(cost);
}

std::string TileTypeToStr(const TileType type)
{
	switch (type)
	{
	case TileType::VOID:            return "Void";
	case TileType::GRASS:           return "Flatten";
	case TileType::FOREST:          return "Forest";
	case TileType::WATER:           return "Water";
	case TileType::RESIDENTIAL:     return "Residential Zone";
	case TileType::COMMERCIAL:      return "Commercial Zone";
	case TileType::INDUSTRIAL:      return "Industrial Zone";
	case TileType::ROAD:			return "Road";
	}
}
