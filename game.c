#include "game.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifdef __WINDOWS__
#include <windows.h>
#endif

#include "error.h"
#include "image.h"
#include "font.h"
#include "window.h"


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

	free(game);
}

void fortitude_startGame(fortitude_Game *game)
{
	int ticks = SDL_GetTicks();
	int delayTicks = 0;
	int frameCount = 0;
	int lastFrameCount = 0;
	time_t lastTime = time(NULL);
	wchar_t fpString[8];
	swprintf(fpString, sizeof(fpString) / sizeof(*fpString), L"FPS:%d", lastFrameCount);
	if (game->window == NULL || game->renderer == NULL) fortitude_throwError("Game object was uninitialized!", PASSED_NULL_CONTEXT);
	bool quit = false;
	SDL_Event e;
	fortitude_Font *font = fortitude_createFont(game->renderer,"assets/img/curses_640x300.png", 8, 12);
	int foreground = 0, background = 0;
	srand((unsigned int)time(NULL));
	//Did the loadMaterials function return false? If not, is the game->materials array still unintialized? (Assume that first
	//element corruption implies full array corruption)
	if (!fortitude_loadMaterials(game) || game->materials[0] == NULL) fortitude_throwError("Material array wasn't initialized properly!", ESSENTIAL_ASSET_MISSING);
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

		if (lastTime != time(NULL))
		{
			lastFrameCount = frameCount;
			frameCount = 0;
			lastTime = time(NULL);
			fpString[0] = '\0';
			swprintf(fpString, sizeof(fpString) / sizeof(*fpString), L"FPS:%d", lastFrameCount);
		}
		else frameCount++;

		for (int i = 0; i < FORTITUDE_WINDOW_COLUMNS; i++)
		{
			for (int j = 0; j < FORTITUDE_WINDOW_ROWS; j++)
			{
				if (i != 0 && i != FORTITUDE_WINDOW_COLUMNS-1 && j != 0 && j != FORTITUDE_WINDOW_ROWS-1)
				{
					int count = rand() % game->materialCount;
					fortitude_renderCharacterInFont(game->renderer, font, game->materials[count]->character, i, j, game->materials[count]->foreground_colour, game->materials[count]->background_colour);
				}
				else
				{
					fortitude_renderCharacterInFont(game->renderer, font, L'█', i, j, 0x888888, 0x000000);
				}
				
			}
		}
		fortitude_renderStringInFont(game->renderer, font, L"  Fortitude  ", 34, 0, 0x000000, 0xc0c0c0);
		fortitude_renderStringInFont(game->renderer, font, fpString, 71, 0, 0x00FFFF, 0x008080);
		fortitude_gameUpdate(game);
		fortitude_gameRender(game);
		SDL_RenderPresent(game->renderer);

		delayTicks = (10 - (SDL_GetTicks() - ticks));
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

int fortitude_loadMaterials(fortitude_Game *game)
{
	if (game == NULL)
	{
		fortitude_throwError("Game pointer was null!", NONESSENTIAL_NULL_CONTEXT);
		return 0;
	}
#ifdef __WINDOWS__
	WIN32_FIND_DATA fileData;
	HANDLE hFind;
	int arrayElementCount = 0;
	int currentCount = 0;
	char fileNameBuffer[512];


	hFind = FindFirstFile("assets\\mat\\*.txt", &fileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		char messageBuffer[512];
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), messageBuffer, 512, NULL);
		fortitude_throwError(messageBuffer, MATERIAL_NOT_FOUND);
		return 0;
	}

	arrayElementCount = FORTITUDE_MATERIAL_COUNT;
	strcpy(fileNameBuffer, "assets/mat/");
	strcat(fileNameBuffer, fileData.cFileName);
	game->materials[currentCount] = fortitude_loadMaterial(fileNameBuffer);
	currentCount++;

	while (FindNextFile(hFind, &fileData))
	{
		strcpy(fileNameBuffer, "assets/mat/");
		strcat(fileNameBuffer, fileData.cFileName);
		game->materials[currentCount] = fortitude_loadMaterial(fileNameBuffer);
		currentCount++;
		if (currentCount >= arrayElementCount)
		{
			fortitude_throwError("Too many materials! Array unable to cope.", ARGUMENT_OOB);
			return 0;
		}
	}
	//Pad out the rest - no nasty leftovers in my arrays!
	for(int i = arrayElementCount-1;i > currentCount-1;i--)
	{
		game->materials[i] = NULL;
	}
	game->materialCount = currentCount;
#else
	fortitude_throwError("__WINDOWS__ not defined, and fallback functions not yet implemented!");
	return false;
#endif

	return 1;
}