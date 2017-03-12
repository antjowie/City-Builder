#include "GameStateMainMenu.h"

void GameStateMainMenu::Draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);
}

void GameStateMainMenu::Update(const float dt)
{
}

void GameStateMainMenu::Input()
{
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::Resized:
			this->view.setSize(event.size.width,event.size.height);
			this->game->background.setPostition(this->game->window.mapPixelToCoord(sf::Vector2i(0, 0))));

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

GameStateMainMenu::GameStateMainMenu(Game* gameAdress):
	GameState(gameAdress)
{
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
}