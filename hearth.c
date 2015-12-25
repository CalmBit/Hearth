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

#include <stdio.h>

#include <SDL2/SDL.h>

#include "error.h"
#include "window.h"
#include "game.h"


int main(int argc, char* argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	hearth_Game *game = NULL;

	createAndInitializeWindow(&window, &renderer);
	game = hearth_createGame(window, renderer);
	hearth_startGame(game);
	destroyWindow(window, renderer);
	return 0;
}