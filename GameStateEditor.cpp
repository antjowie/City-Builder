#include "GameStateEditor.h"

void GameStateEditor::Draw(const float dt)
{
	game->window.clear(sf::Color::Black);
	game->window.draw(game->background);
}

void GameStateEditor::Update(const float dt)
{
}

void GameStateEditor::Input()
{
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::Resized:
			gameView.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			gameView.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);
			guiView.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			guiView.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);

			game->background.setPosition(0, 0);
			game->background.setScale(
				static_cast<float>(static_cast<float>(event.size.width)) / static_cast<float>(game->background.getLocalBounds().width),
				static_cast<float>(static_cast<float>(event.size.height)) / static_cast<float>(game->background.getLocalBounds().height));
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) game->window.close();
			break;
		default: break;
		}
	}
}

GameStateEditor::GameStateEditor(Game* gameAdress) :
	GameState(gameAdress)
{
	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	gameView.setSize(pos);
	guiView.setSize(pos);
	pos *= 0.5f;
	gameView.setCenter(pos);
	guiView.setCenter(pos);
}