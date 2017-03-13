#include "Game.h"
#include "GameState.h"

void Game::LoadTextures()
{
	textureManager.LoadTexture("background", "media/background.png");
}

void Game::PushState(GameState * state)
{
	gamestates.push(state);
}

void Game::PopState()
{
	delete gamestates.top();
	gamestates.pop();
}

void Game::SwitchState(GameState * state)
{
	if (!gamestates.empty()) PopState();
	PushState(state);
	
}

GameState* Game::PeekState()
{
	if (gamestates.empty()) return nullptr;
	return gamestates.top();
}

void Game::GameLoop()
{
	sf::Clock clock;
	float dt;

	while (window.isOpen()) {
		dt = clock.getElapsedTime().asSeconds();

		if (PeekState() == nullptr) continue;
		PeekState()->Input();
		PeekState()->Update(dt);
		window.clear(sf::Color::Black);
		PeekState()->Draw(dt);
		window.display();
	}
}

Game::Game()
{
	window.create(sf::VideoMode(800, 600), "City Builder");
	window.setFramerateLimit(60);

	LoadTextures();
	background.setTexture(textureManager.GetTexture("background"));
}


Game::~Game()
{
	while (!gamestates.empty()) PopState();
}
