#ifndef _FORT_GAME_H
#define _FORT_GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "stddefs.h"
#include "material.h"

/*
	struct fortitude_Game -- contains a handle to both the window and the current renderer.
	*window - window instance currently being rendered
	*renderer - renderer to perform render operations
	*materials[FORTITUDE_MATERIAL_COUNT] - array of pointers for materials currently loaded in game
*/
typedef struct Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	fortitude_Material *materials[FORTITUDE_MATERIAL_COUNT];
	int materialCount;
} fortitude_Game;

/*
	fortitude_startGame() -- start the game, going through initialization and looping.
	*game - handle to the game we're looking to start looping
*/
void fortitude_startGame(fortitude_Game *game);

/*
	fortitude_gameRender() -- render function (CURRENTLY UNUSED)
	*game - handle to the game we're looking to render for
*/
void fortitude_gameRender(fortitude_Game *game);

/*
	fortitude_gameUpdate() -- update function (CURRENTLY UNUSED)
	*game - handle to the game we want to update
*/
void fortitude_gameUpdate(fortitude_Game *game);

/*
	fortitude_createGame() -- fortitude_Game factory
	*window - window instance currently being rendered
	*renderer - renderer to perform render operations
*/
fortitude_Game *fortitude_createGame(SDL_Window *window, SDL_Renderer *renderer);

/*
	fortitude_destroyGame() -- fortitude_Game destructor
	*game - pointer to game for destruction
*/
void fortitude_destroyGame(fortitude_Game *game);

/*
	fortitude_loadMaterials() -- initializes a game's material array
	*game - pointer to game that needs material initialization
*/
int fortitude_loadMaterials(fortitude_Game* game);

#endif