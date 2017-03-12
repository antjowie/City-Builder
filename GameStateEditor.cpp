#include "GameStateEditor.h"

void GameStateEditor::Draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);
}

void GameStateEditor::Update(const float dt)
{
}

void GameStateEditor::Input()
{
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::Resized:
			this->gameView.setSize(event.size.width, event.size.height);
			this->gameView.setCenter(event.size.width / 2, event.size.height / 2);
			this->guiView.setSize(event.size.width, event.size.height);
			this->guiView.setCenter(event.size.width / 2, event.size.height / 2);

			this->game->background.setPostition(this->game->window.mapPixelToCoord(sf::Vector2i(0, 0), this->guiView));
			this->game->background.setScale(
				static_cast<float>(event.size.width) / static_cast<float>(this->game->background.getSize().x),
				static_cast<float>(event.size.height) / static_cast<float>(this->game->background.getSize().y));
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) this->game->window.close;
			break;
		default: break;
		}
	}
}

GameStateEditor::GameStateEditor(Game* gameAdress) :
	GameState(gameAdress)
{
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->gameView.setSize(pos);
	this->guiView.setSize(pos);
	pos *= 0.5f;
	this->gameView.setCenter(pos);
	this->guiView.setCenter(pos);
}