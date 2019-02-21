#include "Game.h"
#include "textureManager.h"


SDL_Texture* bg_tex;
SDL_Texture* player_tex;
SDL_Rect srcR, destR;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	 
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("init SDL subsystem \n");
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			printf("window created \n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			printf("renderer created \n");
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}


	bg_tex = textureManager::LoadTexture("assets/bg_test1.png", renderer);
	player_tex = textureManager::LoadTexture("assets/player.png", renderer);

}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	destR.h = 64;
	destR.w = 64;
	destR.x = 300;
	destR.y = cnt;
	if (cnt > 300) {
		n++;
		cnt -= cnt - 200;
	}
	SDL_Delay(50);

}

void Game::render()
{
	SDL_RenderClear(renderer);
	//add render stuff
	SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
	SDL_RenderCopy(renderer, player_tex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("game cleaned \n");
}