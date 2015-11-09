#ifndef _FORT_IMAGE_H
#define _FORT_IMAGE_H

#include <SDL2/SDL.h>

/*
	struct fortitude_Image -- container for image to be displayed
	*texture - pointer to image's texture
*/
typedef struct Image
{
	SDL_Texture *texture;
} fortitude_Image;

/*
	struct fortitude_SpriteSheet -- container for sprite atlas
	*texture - pointer to image's texture
	spriteHeight - height of individual sprite;
	spriteWidth - width of individual sprite;
	spriteRows - number of sprites per column
	spriteColumns - number of sprites per row
*/
typedef struct SpriteSheet
{
	SDL_Texture *texture;
	int spriteWidth;
	int spriteHeight;
	int spriteColumns;
	int spriteRows;
} fortitude_SpriteSheet;

/*
	fortitude_createImage() -- fortitude_Image factory
	*renderer - renderer to perform render operations
	*path - path to image file
*/
fortitude_Image *fortitude_createImage(SDL_Renderer *renderer, const char *path);

/*
	fortitude_createSpriteSheet -- fortitude_SpriteSheet factory
	*renderer - renderer to perform render operations
	*path - path to image file
	spriteHeight - height of individual sprite;
	spriteWidth - width of individual sprite;
	spriteRows - number of sprites per column
	spriteColumns - number of sprites per row
*/
fortitude_SpriteSheet *fortitude_createSpriteSheet(SDL_Renderer *renderer, const char *path, int spriteHeight, int spriteWidth, int spriteRows, int spriteColumns);

void fortitude_renderSpriteSheetClip(SDL_Renderer *renderer, fortitude_SpriteSheet *spriteSheet, int x, int y, int sX, int sY);
#endif
