#ifndef _FORT_IMAGE_H
#define _FORT_IMAGE_H

#include <SDL2/SDL.h>

typedef struct Image
{
	SDL_Texture *texture;
} fortitude_Image;

typedef struct SpriteSheet
{
	SDL_Texture *texture;
	int spriteHeight;
	int spriteWidth;
	int spriteRows;
	int spriteColumns;
} fortitude_SpriteSheet;

fortitude_Image *fortitude_createImage(SDL_Renderer *renderer, const char *path);

fortitude_SpriteSheet *fortitude_createSpriteSheet(SDL_Renderer *renderer, const char *path, int spriteHeight, int spriteWidth, int spriteRows, int spriteColumns);

void fortitude_renderSpriteSheetClip(SDL_Renderer *renderer, fortitude_SpriteSheet *spriteSheet, int x, int y, int sX, int sY);
#endif
