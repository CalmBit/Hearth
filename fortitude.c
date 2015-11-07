#include <stdio.h>

#include <SDL2/SDL.h>

#include "error.h"
#include "window.h"
#include "game.h"


int main(int argc, char* argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	fortitude_Game *game = NULL;

	createAndInitializeWindow(&window, &renderer);
	game = fortitude_createGame(window, renderer);
	fortitude_startGame(game);
	destroyWindow(window, renderer);
	return 0;
}