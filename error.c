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

#include "error.h"

#include <stdio.h>

#include <SDL2\SDL.h>

void hearth_throwError(const char *message, int code)
{
	if (code >= 100 && code < 200)
	{
		printf("[FATAL_ERROR] %s\n[SDL] %s", message, SDL_GetError());
		SDL_ClearError();
		char ch;
		scanf("%c", &ch);
		exit(code);
	}
	else if (code >= 200 && code < 300)
	{
		printf("[GENERAL_ERROR] %s\n", message);
		const char* sdl = SDL_GetError();
		if (*sdl) printf("[SDL] %s", sdl);
	}
	else if (code >= 300 && code < 400)
	{
		printf("[FILE_ERROR] %s\n", message);
	}
}

