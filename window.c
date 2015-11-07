#include "window.h"

#include <SDL2/SDL_image.h>

#include "error.h"

void createAndInitializeWindow(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_Surface *surface = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) fortitude_throwError("SDL_Init Failed!", BAD_SDL_INIT);

	*window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 288, SDL_WINDOW_RESIZABLE);
	if (*window == NULL) fortitude_throwError("Window wasn't able to be initialized!", BAD_WINDOW_INIT);

	surface = IMG_Load("assets/logo/icon1.ico");
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	if (surface == NULL) fortitude_throwError("Window Icon unable to be located!", ESSENTIAL_ASSET_MISSING);
	SDL_SetWindowIcon(*window, surface);
	SDL_FreeSurface(surface);

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (*renderer == NULL) fortitude_throwError("Renderer wasn't able to be initialized!", BAD_RENDERER_INIT);
}

void destroyWindow(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}