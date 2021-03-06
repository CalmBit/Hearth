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

#ifndef _FORT_WINDOW_H
#define _FORT_WINDOW_H

#include <SDL2/SDL.h>

/*
	 createAndInitializeWindow() -- inititalize SDL, SDL_Window, and SDL_Renderer for essential context creation.
	 *window - pouint32_ter to window to initalize.
	 *renderer - pouint32_ter to render to initialize
 */
void createAndInitializeWindow(SDL_Window **window, SDL_Renderer **renderer);

/*
	 destroyWindow() -- destroy SDL_Renderer and SDL_Window, and SDL_Quit.
	 *window - pouint32_ter to window to destroy.
	 *renderer - pouint32_ter to renderer to destroy.
 */
void destroyWindow(SDL_Window *window, SDL_Renderer *renderer);

#endif