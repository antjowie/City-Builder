#include "Game.h"
#include "GameState.h"

void Game::PushState(GameState * state)
{
	this->gamestates.push(state);
}

void Game::PopState()
{
	delete this->gamestates.top();
	this->gamestates.pop;
}

void Game::SwitchState(GameState * state)
{
	if (!this->gamestates.empty()) PopState();
	PushState(state);
	
}

GameState* Game::PeekState()
{
	if (this->gamestates.empty()) return nullptr;
	return this->gamestates.top();
}

void Game::GameLoop()
{
	sf::Clock clock;
	float dt;

	while (!this->window.isOpen()) {
		float dt = clock.getElapsedTime().asSeconds();

		if (PeekState() == nullptr) continue;
		PeekState()->Input();
		PeekState()->Update(dt);
		this->window.clear(sf::Color::Black);
		PeekState()->Draw(dt);
		window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "City Builder");
	this->window.setFramerateLimit(60);
}


Game::~Game()
{
	while (!gamestates.empty()) PopState();
}
