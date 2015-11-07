#include "image.h"

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL_image.h>

#include "error.h"

fortitude_Image *fortitude_createImage(SDL_Renderer *renderer, const char *path)
{
	fortitude_Image *image = (fortitude_Image *)malloc(sizeof(fortitude_Image));
	SDL_Surface *surface = IMG_Load(path);
	char error[255];
	if (surface == NULL)
	{
		strcpy(error, "Image ");
		strcpy(error, path);
		strcpy(error," couldn't be loaded!");
		fortitude_throwError(error, ASSET_LOAD_FAILURE);
		surface = IMG_Load("assets/img/fallback.png");
		if (surface == NULL)
		{
			fortitude_throwError("Fallback image is missing!", ESSENTIAL_ASSET_MISSING);
		}
		error[0] = '\0';
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
	image->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (image->texture == NULL)
	{
		strcpy(error, "Texture failed to be created from image ");
		strcpy(error, path);
		strcpy(error, "!");
		fortitude_throwError(error, TEXTURE_CREATION_FAILURE);
	}
	SDL_FreeSurface(surface);
	return image;
}

fortitude_SpriteSheet *fortitude_createSpriteSheet(SDL_Renderer *renderer, const char *path, int spriteWidth, int spriteHeight, int spriteColumns, int spriteRows)
{
	fortitude_SpriteSheet *spriteSheet = (fortitude_SpriteSheet *)malloc(sizeof(fortitude_SpriteSheet));
	SDL_Surface *surface = IMG_Load(path);
	char error[255];
	if (surface == NULL)
	{
		strcpy(error, "Image ");
		strcpy(error, path);
		strcpy(error, " couldn't be loaded!");
		fortitude_throwError(error, ASSET_LOAD_FAILURE);
		surface = IMG_Load("assets/img/fallback.png");
		if (surface == NULL)
		{
			fortitude_throwError("Fallback image is missing!", ESSENTIAL_ASSET_MISSING);
		}
		error[0] = '\0';
	}
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
	spriteSheet->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (spriteSheet->texture == NULL)
	{
		strcpy(error, "Texture failed to be created from image ");
		strcpy(error, path);
		strcpy(error, "!");
		fortitude_throwError(error, TEXTURE_CREATION_FAILURE);
	}
	SDL_FreeSurface(surface);
	spriteSheet->spriteHeight = spriteHeight;
	spriteSheet->spriteWidth = spriteWidth;
	spriteSheet->spriteRows = spriteRows;
	spriteSheet->spriteColumns = spriteColumns;
	return spriteSheet;
}

void fortitude_renderSpriteSheetClip(SDL_Renderer *renderer, fortitude_SpriteSheet *spriteSheet, int x, int y, int sX, int sY)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	if (renderer == NULL) fortitude_throwError("Renderer was passed as NULL!", PASSED_NULL_CONTEXT);

	srcRect.w = spriteSheet->spriteWidth;
	srcRect.h = spriteSheet->spriteHeight;
	if (sX >= spriteSheet->spriteColumns) fortitude_throwError("SpriteSheet column was out of bounds!", ARGUMENT_OOB);
	srcRect.x = spriteSheet->spriteWidth*sX;
	if (sY >= spriteSheet->spriteRows) fortitude_throwError("SpriteSheet row was out of bounds!", ARGUMENT_OOB);
	srcRect.y = spriteSheet->spriteHeight*sY;

	dstRect.w = spriteSheet->spriteWidth;
	dstRect.h = spriteSheet->spriteHeight;
	dstRect.x = x;
	dstRect.y = y;
	SDL_RenderCopy(renderer, spriteSheet->texture, &srcRect, &dstRect);
}