#ifndef _FORT_WINDOW_H
#define _FORT_WINDOW_H

#include <SDL2/SDL.h>

/*
	 createAndInitializeWindow() -- inititalize SDL, SDL_Window, and SDL_Renderer for essential context creation.
	 *window - pointer to window to initalize.
	 *renderer - pointer to render to initialize
 */
void createAndInitializeWindow(SDL_Window **window, SDL_Renderer **renderer);

/*
	 destroyWindow() -- destroy SDL_Renderer and SDL_Window, and SDL_Quit.
	 *window - pointer to window to destroy.
	 *renderer - pointer to renderer to destroy.
 */
void destroyWindow(SDL_Window *window, SDL_Renderer *renderer);

#endif