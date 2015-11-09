#include "error.h"

#include <stdio.h>

#include <SDL2\SDL.h>

void fortitude_throwError(const char *message, int code)
{
	if (code >= 100 && code < 200)
	{
		printf("[FATAL] %s\n[SDL] %s", message, SDL_GetError());
		SDL_ClearError();
		char ch;
		scanf("%c", &ch);
		exit(code);
	}
	else if (code >= 200 && code < 300)
	{
		printf("[ERROR] %s\n", message);
		const char* sdl = SDL_GetError();
		if (*sdl) printf("[SDL] %s", sdl);
	}
	else if (code >= 300 && code < 400)
	{
		printf("[MATERIAL] %s\n", message);
	}
}

