#ifndef _FORT_FONT_H
#define _FORT_FONT_H

#include <math.h>

#include "image.h"

typedef struct Font
{
	fortitude_SpriteSheet *spriteSheet;
} fortitude_Font;

fortitude_Font *fortitude_createFont(SDL_Renderer *renderer, const char *path, int charSizeX, int charSizeY);
void fortitude_renderStringInFont(SDL_Renderer *renderer, fortitude_Font *font, const wchar_t* string, int x, int y, int foreground, int background);
void fortitude_renderCharacterInFont(SDL_Renderer *renderer, fortitude_Font *font, wchar_t character, int x, int y, int foreground, int background);
int fortitude_getFontPositionFromCharacter(wchar_t character);

#endif