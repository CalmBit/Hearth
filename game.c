/*
	This file is part of Hearth.

	Hearth is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Hearth is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Hearth.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "game.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "error.h"
#include "image.h"
#include "font.h"
#include "window.h"
#include "item.h"

extern hearth_Item itemList[HEARTH_ITEM_NUM];

hearth_Game *hearth_createGame(SDL_Window *window, SDL_Renderer *renderer)
{
	hearth_Game *game = (hearth_Game *)malloc(sizeof(hearth_Game));
	game->window = window;
	game->renderer = renderer;
	game->turnTimer = 0;

	if (!hearth_loadTiles(game) || game->tiles[0][0] == NULL) 
		hearth_throwError("Tile array wasn't initialized properly!", ESSENTIAL_ASSET_MISSING);
	return game;
}

void hearth_destroyGame(hearth_Game *game)
{
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	free(game);
}

void hearth_startGame(hearth_Game *game)
{
	uint32_t ticks = SDL_GetTicks();
	int32_t delayTicks = 0;
	uint32_t frameCount = 0;
	uint32_t lastFrameCount = 0;
	time_t lastTime = time(NULL);
	wchar_t fpString[8];
	swprintf(fpString, 8, L"FPS:%d", lastFrameCount);
	if (game->window == NULL || game->renderer == NULL) 
		hearth_throwError("Game object was uninitialized!", PASSED_NULL_CONTEXT);
	bool quit = false;
	SDL_Event e;
	hearth_Font *font = hearth_createFont(game->renderer,"assets/img/curses_640x300.png", 8, 12);
	uint32_t foreground = 0, background = 0;
	srand((uint32_t)time(NULL));
	game->player = hearth_createPlayer(L"Phobeos", 10, 10);
	wchar_t stringBuffer[16];
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
		const uint8_t *state = SDL_GetKeyboardState(NULL);
		if (game->turnTimer == 0)
		{
			if (state[SDL_SCANCODE_W] && game->player->posY > 1)
			{
				game->player->posY--;
				game->turnTimer = HEARTH_STANDARD_TURN_TIMER;
			}
			else if (state[SDL_SCANCODE_S] && game->player->posY < HEARTH_WINDOW_ROWS-2)
			{
				game->player->posY++;
				game->turnTimer = HEARTH_STANDARD_TURN_TIMER;
			}
			else if (state[SDL_SCANCODE_A] && game->player->posX > 0)
			{
				game->player->posX--;
				game->turnTimer = HEARTH_STANDARD_TURN_TIMER;
			}
			else if (state[SDL_SCANCODE_D] && game->player->posX < HEARTH_WINDOW_COLUMNS-1)
			{
				game->player->posX++;
				game->turnTimer = HEARTH_STANDARD_TURN_TIMER;
			}
			else if (state[SDL_SCANCODE_E])
			{
				itemList[0].effect(game->player);
				game->turnTimer = HEARTH_STANDARD_TURN_TIMER;
			}
		}
		else game->turnTimer--;
		SDL_RenderClear(game->renderer);

		if (lastTime != time(NULL))
		{
			lastFrameCount = frameCount;
			frameCount = 0;
			lastTime = time(NULL);
			fpString[0] = '\0';
			swprintf(fpString, 8,  L"FPS:%d", lastFrameCount);
		}
		else frameCount++;

		for (uint32_t i = 0; i < HEARTH_WINDOW_COLUMNS; i++)
		{
			for (uint32_t j = 0; j < HEARTH_WINDOW_ROWS; j++)
			{
				if(j < HEARTH_WINDOW_ROWS-4)
				{
					//if (game->tiles[i][j]->visible)hearth_renderCharacterInFont(game->renderer, font, L'█', i, j, 0x666666, 0x000000);
				}
				else
				{
					hearth_renderCharacterInFont(game->renderer, font, L'█', i, j, ((j <= HEARTH_WINDOW_ROWS - 4) ? 0x888888 : 0x000000), 0x000000);
				}
				
			}
		}
		hearth_renderCharacterInFont(game->renderer, font, '@', game->player->posX, game->player->posY, 0x00FFFF, 0x000000);
		hearth_renderStringInFont(game->renderer, font, game->player->name, 0, HEARTH_WINDOW_ROWS - 3, 0x888888, 0x000000);
		hearth_renderStringInFont(game->renderer, font, L"Health: [", 0, HEARTH_WINDOW_ROWS - 2, 0x888888, 0x000000);
		for (uint32_t i = 0; i < game->player->maxHealth; i += 2)
		{
			if (game->player->health >= i + 2)
			{
				hearth_renderCharacterInFont(game->renderer, font, L'█', 9 + (i / 2), HEARTH_WINDOW_ROWS - 2, 0x880000, 0x000000);
			}
			else if (game->player->health >= i + 1)
			{
				hearth_renderCharacterInFont(game->renderer, font, L'▒', 9 + (i / 2), HEARTH_WINDOW_ROWS - 2, 0x880000, 0x000000);
			}
		}
		swprintf(stringBuffer, 16, L"%d/%d", game->player->health, game->player->maxHealth);
		hearth_renderCharacterInFont(game->renderer, font, L']', 9 + (game->player->maxHealth/2), HEARTH_WINDOW_ROWS - 2, 0x888888, 0x000000);
		hearth_renderStringInFont(game->renderer, font, stringBuffer, 11 + (game->player->maxHealth / 2), HEARTH_WINDOW_ROWS - 2, 0x888888, 0x000000);
		hearth_renderStringInFont(game->renderer, font, L"Mana: ", 0, HEARTH_WINDOW_ROWS - 1, 0x888888, 0x000000);
		hearth_renderCharacterInFont(game->renderer, font, L'[', 8, HEARTH_WINDOW_ROWS - 1, 0x888888, 0x000000);
		for (uint32_t j = 0; j < game->player->maxMana; j += 10)
		{
			if (game->player->mana >= j + 10)
			{
				hearth_renderCharacterInFont(game->renderer, font, L'█', 9 + (j / 10), HEARTH_WINDOW_ROWS - 1, 0x000088, 0x000000);
			}
			else if (game->player->mana >= j + 5)
			{
				hearth_renderCharacterInFont(game->renderer, font, L'▒', 9 + (j / 10), HEARTH_WINDOW_ROWS - 1, 0x000088, 0x000000);
			}
		}
		swprintf(stringBuffer, 16, L"%d/%d", game->player->mana, game->player->maxMana);
		hearth_renderCharacterInFont(game->renderer, font, L']', 9 + (game->player->maxMana / 10), HEARTH_WINDOW_ROWS - 1, 0x888888, 0x000000);
		hearth_renderStringInFont(game->renderer, font, stringBuffer, 11 + (game->player->maxMana / 10), HEARTH_WINDOW_ROWS - 1, 0x888888, 0x000000);

		hearth_renderStringInFont(game->renderer, font, fpString, 71, 0, 0x00FFFF, 0x008080);
		hearth_gameUpdate(game);
		hearth_gameRender(game);
		SDL_RenderPresent(game->renderer);

		delayTicks = (10 - (SDL_GetTicks() - ticks));
		if (delayTicks > 0) SDL_Delay(delayTicks);
		else SDL_Delay(1);
		ticks = SDL_GetTicks();

	}
	hearth_destroyFont(font);
	hearth_destroyGame(game);
}

void hearth_gameRender(hearth_Game *game)
{

}

void hearth_gameUpdate(hearth_Game *game)
{

}

uint32_t hearth_loadTiles(hearth_Game *game)
{
	for (uint32_t x = 0; x < HEARTH_WINDOW_COLUMNS; x++)
	{
		for (uint32_t y = 0; y < HEARTH_WINDOW_ROWS; y++)
		{
			game->tiles[x][y] = hearth_createTile(WALL, 100);
			if (game->tiles[x][y] == NULL) 
				return 0;
		}
	}
	return 1;
}