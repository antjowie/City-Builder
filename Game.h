#pragma once

#include <stack>

#include "SFML\Graphics.hpp"

class GameState;

class Game
{
private:
	sf::RenderWindow window;
	std::stack<GameState*> gamestates;
	
	void PushState(GameState* state);
	void PopState();
	void SwitchState(GameState* state);
	GameState* PeekState();
	
	void GameLoop();
	
public:
	Game();
	~Game();
};

