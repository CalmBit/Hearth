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

#include "window.h"

#include <SDL2/SDL_image.h>

#include "error.h"
#include "stddefs.h"

void createAndInitializeWindow(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_Surface *surface = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) hearth_throwError("SDL_Init Failed!", BAD_SDL_INIT);

	*window = SDL_CreateWindow("Hearth: Return of Bra'kaa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEARTH_WINDOW_COLUMNS*8, HEARTH_WINDOW_ROWS*12, SDL_WINDOW_RESIZABLE);
	if (*window == NULL) hearth_throwError("Window wasn't able to be initialized!", BAD_WINDOW_INIT);

	surface = IMG_Load("assets/logo/icon1.ico");
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	if (surface == NULL) hearth_throwError("Window Icon unable to be located!", ESSENTIAL_ASSET_MISSING);
	SDL_SetWindowIcon(*window, surface);
	SDL_FreeSurface(surface);

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (*renderer == NULL) hearth_throwError("Renderer wasn't able to be initialized!", BAD_RENDERER_INIT);
}

void destroyWindow(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}