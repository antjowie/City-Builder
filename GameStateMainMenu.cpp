#include "GameStateMainMenu.h"
#include"GameStateEditor.h"

void GameStateMainMenu::LoadGame()
{
	game->PushState(new GameStateEditor(game));
}

void GameStateMainMenu::Draw(const float dt)
{
	game->window.setView(view);

	game->window.clear(sf::Color::Black);
	game->window.draw(game->background);
}

void GameStateMainMenu::Update(const float dt)
{
}

void GameStateMainMenu::Input()
{
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::Resized:
			view.setSize(static_cast<float>(event.size.width),static_cast<float>(event.size.height));
			view.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);

			game->background.setPosition(0,0);
			game->background.setScale(
				static_cast<float>(static_cast<float>(event.size.width)) / static_cast<float>(game->background.getLocalBounds().width),
				static_cast<float>(static_cast<float>(event.size.height)) / static_cast<float>(game->background.getLocalBounds().height));
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) game->window.close();
			else if (event.key.code == sf::Keyboard::Space) LoadGame();
			break;
		default: break;
		}
	}
}

GameStateMainMenu::GameStateMainMenu(Game* gameAdress):
	GameState(gameAdress)
{
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);
}