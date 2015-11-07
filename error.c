#include "error.h"

#include <stdio.h>

#include <SDL2\SDL.h>

void fortitude_throwError(const char *message, int code)
{
	if (code >= 100 && code < 200)
	{
		wprintf("[FATAL] %s\n[SDL] %s", message, SDL_GetError());
		SDL_ClearError();
		char ch;
		scanf("%c", &ch);
		exit(code);
	}
	else if (code >= 200 && code < 200)
	{
		wprintf("[ERROR] %s\n");
		const char* sdl = SDL_GetError();
		if (*sdl) wprintf("[SDL] %s", sdl);
	}
}

