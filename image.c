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

#include "image.h"

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL_image.h>

#include "error.h"
#include "stddefs.h"

hearth_Image *hearth_createImage(SDL_Renderer *renderer, const char *path)
{
	hearth_Image *image = (hearth_Image *)malloc(sizeof(hearth_Image));
	SDL_Surface *surface = IMG_Load(path);
	char error[255];
	if (surface == NULL)
	{
		sprintf(error, HEARTH_ERRORSTR_NOLOADIMG, path);
		hearth_throwError(error, ASSET_LOAD_FAILURE);
		surface = IMG_Load(HEARTH_FALLBACKIMG_PATH);
		if (surface == NULL)
		{
			hearth_throwError(HEARTH_ERRORSTR_FALLBACKMISSING, ESSENTIAL_ASSET_MISSING);
		}
		error[0] = '\0';
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
	image->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (image->texture == NULL)
	{
		sprintf(error, HEARTH_ERRORSTR_TEXCREATEFAIL, path);
		hearth_throwError(error, TEXTURE_CREATION_FAILURE);
	}
	SDL_FreeSurface(surface);
	return image;
}

hearth_SpriteSheet *hearth_createSpriteSheet(SDL_Renderer *renderer, const char *path, uint32_t spriteWidth, uint32_t spriteHeight, uint32_t spriteColumns, uint32_t spriteRows)
{
	hearth_SpriteSheet *spriteSheet = (hearth_SpriteSheet *)malloc(sizeof(hearth_SpriteSheet));
	SDL_Surface *surface = IMG_Load(path);
	char error[255];
	if (surface == NULL)
	{
		sprintf(error, HEARTH_ERRORSTR_NOLOADIMG, path);
		hearth_throwError(error, ASSET_LOAD_FAILURE);
		surface = IMG_Load(HEARTH_FALLBACKIMG_PATH);
		if (surface == NULL)
		{
			hearth_throwError(HEARTH_ERRORSTR_FALLBACKMISSING, ESSENTIAL_ASSET_MISSING);
		}
		error[0] = '\0';
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
	spriteSheet->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (spriteSheet->texture == NULL)
	{
		sprintf(error, HEARTH_ERRORSTR_TEXCREATEFAIL, path);
		hearth_throwError(error, TEXTURE_CREATION_FAILURE);
	}
	SDL_FreeSurface(surface);
	spriteSheet->spriteHeight = spriteHeight;
	spriteSheet->spriteWidth = spriteWidth;
	spriteSheet->spriteRows = spriteRows;
	spriteSheet->spriteColumns = spriteColumns;
	return spriteSheet;
}

void hearth_renderSpriteSheetClip(SDL_Renderer *renderer, hearth_SpriteSheet *spriteSheet, uint32_t x, uint32_t y, uint32_t sX, uint32_t sY)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	if (renderer == NULL) hearth_throwError(HEARTH_ERRORSTR_RENDERNULL, PASSED_NULL_CONTEXT);

	srcRect.w = spriteSheet->spriteWidth;
	srcRect.h = spriteSheet->spriteHeight;
	if (sX >= spriteSheet->spriteColumns) hearth_throwError(HEARTH_ERRORSTR_SPRSHTCOL, ARGUMENT_OOB);
	srcRect.x = spriteSheet->spriteWidth*sX;
	if (sY >= spriteSheet->spriteRows) hearth_throwError(HEARTH_ERRORSTR_SPRSHTROW, ARGUMENT_OOB);
	srcRect.y = spriteSheet->spriteHeight*sY;

	dstRect.w = spriteSheet->spriteWidth;
	dstRect.h = spriteSheet->spriteHeight;
	dstRect.x = x;
	dstRect.y = y;
	SDL_RenderCopy(renderer, spriteSheet->texture, &srcRect, &dstRect);
}

void hearth_destroyImage(hearth_Image *image)
{
	SDL_DestroyTexture(image->texture);
	free(image);
}

void hearth_destroySpriteSheet(hearth_SpriteSheet *spriteSheet)
{
	SDL_DestroyTexture(spriteSheet->texture);
	free(spriteSheet);
}