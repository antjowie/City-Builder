#include "Game.h"
#include "GameState.h"

void Game::LoadTextures()
{
	textureManager.LoadTexture("grass", "media/grass.png");
	textureManager.LoadTexture("forest", "media/forest.png");
	textureManager.LoadTexture("water", "media/water.png");
	textureManager.LoadTexture("residential", "media/residential.png");
	textureManager.LoadTexture("commercial", "media/commercial.png");
	textureManager.LoadTexture("industrial", "media/industrial.png");
	textureManager.LoadTexture("road", "media/road.png");

	textureManager.LoadTexture("background", "media/background.png");
}

void Game::LoadTiles()
{
	Animation staticAnim(0, 0, 1.f);
	tileAtlas["grass"] =
		Tile(tileSize, 1, textureManager.GetTexture("grass"), { staticAnim }, TileType::GRASS, 50, 0, 1);
	tileAtlas["forest"] =
		Tile(tileSize, 1, textureManager.GetTexture("forest"), { staticAnim }, TileType::FOREST, 100, 0, 1);
	tileAtlas["water"] =
		Tile(tileSize, 1, textureManager.GetTexture("water"),
		{ Animation(0, 3, 0.5f), Animation(0, 3, 0.5f), Animation(0, 3, 0.5f) }, TileType::WATER, 0, 0, 1);
	tileAtlas["residential"] =
		Tile(tileSize, 2, textureManager.GetTexture("residential"),
		{ staticAnim,staticAnim,staticAnim,staticAnim,staticAnim,staticAnim }, TileType::RESIDENTIAL, 300, 50, 6);
	tileAtlas["commercial"] =
		Tile(tileSize, 2, textureManager.GetTexture("commercial"),
		{ staticAnim, staticAnim, staticAnim, staticAnim },
			TileType::COMMERCIAL, 300, 50, 4);
	tileAtlas["industrial"] =
		Tile(tileSize, 2, textureManager.GetTexture("industrial"),
		{ staticAnim, staticAnim, staticAnim,
			staticAnim },
			TileType::INDUSTRIAL, 300, 50, 4);
	tileAtlas["road"] =
		Tile(tileSize, 1, textureManager.GetTexture("road"),
		{ staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim },
			TileType::ROAD, 100, 0, 1);
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

	LoadTiles();
	LoadTextures();
	background.setTexture(textureManager.GetTexture("background"));
}


Game::~Game()
{
	while (!gamestates.empty()) PopState();
}
