#pragma once

#include "SFML\Graphics.hpp"
#include "TextureManager.h"
#include "Tile.h"
#include <stack>
#include <map>

class GameState;

class Game
{
private:
	void LoadTextures();
	void LoadTiles();

public:

	const static int tileSize = 8;
	std::map<std::string, Tile> tileAtlas;
	
	sf::RenderWindow window;
	std::stack<GameState*> gamestates;

	TextureManager textureManager;
	sf::Sprite background;

	void PushState(GameState* state);
	void PopState();
	void SwitchState(GameState* state);
	GameState* PeekState();
	
	void GameLoop();
	
	Game();
	~Game();
};