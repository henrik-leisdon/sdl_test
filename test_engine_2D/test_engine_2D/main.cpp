#include <iostream>
#include "SDL.h"
#include "Game.h"

Game *game = nullptr;

int main(int argc, char * argv[])
{
	game = new Game();

	game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	while (game->running()) {
		game->handleEvent();
		game->update();
		game->render();


	}
	game->clean();
	return 0;
}