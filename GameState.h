#pragma once

#include "Game.h"
#include "SFML\Graphics.hpp"

class GameState
{
private:
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	Game* game;
	
public:
	
	GameState(Game& gameAdress);
};