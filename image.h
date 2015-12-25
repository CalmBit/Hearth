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

#ifndef HEARTH_IMAGE_H
#define HEARTH_IMAGE_H

#include <SDL2/SDL.h>

/*
	struct hearth_Image -- container for image to be displayed
	*texture - pouint32_ter to image's texture
*/
typedef struct hearth_Image
{
	SDL_Texture *texture;
} hearth_Image;

/*
	struct hearth_SpriteSheet -- container for sprite atlas
	*texture - pouint32_ter to image's texture
	spriteHeight - height of individual sprite;
	spriteWidth - width of individual sprite;
	spriteRows - number of sprites per column
	spriteColumns - number of sprites per row
*/
typedef struct hearth_SpriteSheet
{
	SDL_Texture *texture;
	uint32_t spriteWidth;
	uint32_t spriteHeight;
	uint32_t spriteColumns;
	uint32_t spriteRows;
} hearth_SpriteSheet;

/*
	hearth_createImage() -- hearth_Image factory
	*renderer - renderer to perform render operations
	*path - path to image file
*/
hearth_Image *hearth_createImage(SDL_Renderer *renderer, const char *path);

/*
	hearth_createSpriteSheet -- hearth_SpriteSheet factory
	*renderer - renderer to perform render operations
	*path - path to image file
	spriteHeight - height of individual sprite;
	spriteWidth - width of individual sprite;
	spriteRows - number of sprites per column
	spriteColumns - number of sprites per row
*/
hearth_SpriteSheet *hearth_createSpriteSheet(SDL_Renderer *renderer, const char *path, uint32_t spriteHeight, uint32_t spriteWidth, uint32_t spriteRows, uint32_t spriteColumns);

void hearth_renderSpriteSheetClip(SDL_Renderer *renderer, hearth_SpriteSheet *spriteSheet, uint32_t x, uint32_t y, uint32_t sX, uint32_t sY);

void hearth_destroyImage(hearth_Image *image);

void hearth_destroySpriteSheet(hearth_SpriteSheet *spriteSheet);
#endif
