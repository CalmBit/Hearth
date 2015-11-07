#include "window.h"

#include "error.h"

void createAndInitializeWindow(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) fortitude_throwError("SDL_Init Failed!", BAD_SDL_INIT);

	*window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 288, SDL_WINDOW_RESIZABLE);
	if (*window == NULL) fortitude_throwError("Window wasn't able to be initialized!", BAD_WINDOW_INIT);

	*renderer = SDL_CreateRenderer(*window, -1, NULL);
	if (*renderer == NULL) fortitude_throwError("Renderer wasn't able to be initialized!", BAD_RENDERER_INIT);
}

void destroyWindow(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}