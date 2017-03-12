#pragma once

#include <stack>

#include "SFML\Graphics.hpp"

class GameState;

class Game
{
private:
	void PushState(GameState* state);
	void PopState();
	void SwitchState(GameState* state);
	GameState* PeekState();
	
public:
	sf::RenderWindow window;
	std::stack<GameState*> gamestates;
	
	void GameLoop();
	
	Game();
	~Game();
};

