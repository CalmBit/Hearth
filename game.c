#include "game.h"

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "error.h"
#include "image.h"

fortitude_Game *fortitude_createGame(SDL_Window *window, SDL_Renderer *renderer)
{
	fortitude_Game *game = (fortitude_Game *)malloc(sizeof(fortitude_Game));
	game->window = window;
	game->renderer = renderer;

	return game;
}

void fortitude_destroyGame(fortitude_Game *game)
{
	game->renderer = NULL;
	game->window = NULL;
}

void fortitude_startGame(fortitude_Game *game)
{
	if (game->window == NULL || game->renderer == NULL) fortitude_throwError("Game object was uninitialized!", PASSED_NULL_CONTEXT);
	bool quit = false;
	SDL_Event e;
	fortitude_SpriteSheet *sheet = fortitude_createSpriteSheet(game->renderer, "assets/img/curses_640x300.png", 8, 12, 16, 16);
	srand(time(NULL));
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_RenderClear(game->renderer);
		for (int i = 0; i < 1920; i++)
		{
			SDL_SetTextureColorMod(sheet->texture, rand() % 256, rand() % 256, rand() % 256);
			fortitude_renderSpriteSheetClip(game->renderer, sheet,(i % 80 * 8),(int)floor(i/80)*12, i%16, (int)floor(i/16)%16);
		}
		fortitude_gameUpdate(game);
		fortitude_gameRender(game);
		SDL_RenderPresent(game->renderer);
	}
}

void fortitude_gameRender(fortitude_Game *game)
{

}

void fortitude_gameUpdate(fortitude_Game *game)
{

}