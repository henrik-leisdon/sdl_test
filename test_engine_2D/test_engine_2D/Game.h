#ifndef Game_h
#define Game_h
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"


class Game {

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvent();
	void update();
	void render();
	void clean();
	
	bool running() {
		return isRunning;
	}


private:
	int cnt = 0;
	int n = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;


};



#endif // !Game_h

