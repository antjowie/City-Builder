#pragma once

#include "SFML\Graphics.hpp"
#include <vector>

#include "AnimationHandler.h"

enum class TileType { VOID, GRASS, FOREST, WATER, RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD };

std::string TileTypeToStr(const TileType type);

class Tile
{
public:

	AnimationHandler animHandler;
	sf::Sprite sprite;

	TileType tileType;
	
	int tileVariant;

	unsigned int regions[1];

	unsigned int cost;

	double population;

	unsigned int maxPopPerLevel;

	unsigned int maxLevels;

	float production;

	float storedGoods;


	Tile();
	Tile();

	void Draw(sf::RenderWindow& window, const float dt);
	void Update();

	std::string getCost();
};

