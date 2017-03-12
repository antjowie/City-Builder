#include "Game.h"
#include "GameStateMainMenu.h"

int main()
{
	Game game;

	game.PushState(new GameStateMainMenu(&game));
	game.GameLoop();

	return 0;
}