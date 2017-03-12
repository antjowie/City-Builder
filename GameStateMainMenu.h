#pragma once
#include "GameState.h"

class GameStateMainMenu :
	public GameState
{
private:
	sf::View view;

public:

	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();

	GameStateMainMenu(Game* gameAdress);
};