#ifndef HEARTH_GAME_H
#define HEARTH_GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "stddefs.h"
#include "tile.h"
#include "player.h"

/*
	struct hearth_Game -- contains a handle to both the window and the current renderer.
	*window - window instance currently being rendered
	*renderer - renderer to perform render operations
*/
typedef struct hearth_Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	hearth_Player *player;
	uint32_t turnTimer;
	hearth_Tile *tiles[HEARTH_WINDOW_COLUMNS][HEARTH_WINDOW_ROWS];
} hearth_Game;

/*
	hearth_startGame() -- start the game, going through initialization and looping.
	*game - handle to the game we're looking to start looping
*/
void hearth_startGame(hearth_Game *game);

/*
	hearth_gameRender() -- render function (CURRENTLY UNUSED)
	*game - handle to the game we're looking to render for
*/
void hearth_gameRender(hearth_Game *game);

/*
	hearth_gameUpdate() -- update function (CURRENTLY UNUSED)
	*game - handle to the game we want to update
*/
void hearth_gameUpdate(hearth_Game *game);

/*
	hearth_createGame() -- hearth_Game factory
	*window - window instance currently being rendered
	*renderer - renderer to perform render operations
*/
hearth_Game *hearth_createGame(SDL_Window *window, SDL_Renderer *renderer);

/*
	hearth_destroyGame() -- hearth_Game destructor
	*game - pouint32_ter to game for destruction
*/
void hearth_destroyGame(hearth_Game *game);

uint32_t hearth_loadTiles(hearth_Game *game);

#endif