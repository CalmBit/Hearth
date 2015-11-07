#include "game.h"

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "error.h"
#include "image.h"
#include "font.h"

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
	int ticks = SDL_GetTicks();
	int delayTicks = 0;
	if (game->window == NULL || game->renderer == NULL) fortitude_throwError("Game object was uninitialized!", PASSED_NULL_CONTEXT);
	bool quit = false;
	SDL_Event e;
	fortitude_Font *font = fortitude_createFont(game->renderer,"assets/img/curses_640x300.png", 8, 12);
	int foreground = 0, background = 0;
	srand((unsigned int)time(NULL));

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
		for (int i = 0; i < 80; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				if (i != 0 && i != 79 && j != 0 && j != 23)
				{
					fortitude_renderCharacterInFont(game->renderer, font, L'☺', i, j, 0x008080, 0x000000);
				}
				else
				{
					fortitude_renderCharacterInFont(game->renderer, font, L'█', i, j, 0x888888, 0x000000);
				}
				
			}
		}
		fortitude_renderStringInFont(game->renderer, font, L"  Dwarf Fortress  ", 31, 0, 0x000000, 0xc0c0c0);
		fortitude_gameUpdate(game);
		fortitude_gameRender(game);
		SDL_RenderPresent(game->renderer);

		delayTicks = (16 - (SDL_GetTicks() - ticks));
		if (delayTicks > 0) SDL_Delay(delayTicks);
		else SDL_Delay(1);
		ticks = SDL_GetTicks();

	}
}

void fortitude_gameRender(fortitude_Game *game)
{

}

void fortitude_gameUpdate(fortitude_Game *game)
{

}