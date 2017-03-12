#include "Game.h"

void Game::PushState(GameState * state)
{
	gamestates.push(state);
}

void Game::PopState()
{
	delete gamestates.top();
	gamestates.pop;
}

void Game::SwitchState(GameState * state)
{
	PopState();
	PushState(state);
}

GameState* Game::PeekState()
{
	return gamestates.top();
}

Game::Game()
{
}


Game::~Game()
{
	while (!gamestates.empty()) {
		PopState();
	}
}
