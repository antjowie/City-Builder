#pragma once
#include "GameState.h"
class GameStateEditor :
	public GameState
{
private:
	sf::View gameView;
	sf::View guiView;

public:

	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void Input();

	GameStateEditor(Game* gameAdress);
};