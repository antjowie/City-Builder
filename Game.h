#pragma once

#include "SFML\Graphics.hpp"
#include "TextureManager.h"

#include <stack>

class GameState;

class Game
{
private:
	void LoadTextures();

public:
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