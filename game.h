#ifndef _FORT_GAME_H
#define _FORT_GAME_H

#include <SDL2/SDL.h>

typedef struct Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} fortitude_Game;

void fortitude_startGame(fortitude_Game *game);

void fortitude_gameRender(fortitude_Game *game);

void fortitude_gameUpdate(fortitude_Game *game);

fortitude_Game *fortitude_createGame(SDL_Window *window, SDL_Renderer *renderer);

void fortitude_destroyGame(fortitude_Game *game);

#endif