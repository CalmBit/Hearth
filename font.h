#ifndef _FORT_FONT_H
#define _FORT_FONT_H

#include <math.h>

#include "image.h"

/*
	struct fortitude_Font -- font object with which to render characters
	*spriteSheet -- spritesheet containing character glyphs
*/
typedef struct Font
{
	fortitude_SpriteSheet *spriteSheet;
} fortitude_Font;

/*
	fortitude_createFont() -- fortitude_Font factory
	*renderer - render to perform render operations
	*path - path to font image file
	charSizeX - width of characters
	charSizeY - height of characters
*/
fortitude_Font *fortitude_createFont(SDL_Renderer *renderer, const char *path, int charSizeX, int charSizeY);

/*
	fortitude_renderStringInFont() -- renders a string in the provided font
	*renderer - render to perform render operations
	*string - wchar_t string to render to the screen
	x - x character position for string
	y - y character position for string
	foreground - foreground colour for string in RGB hex format
	background - background colour for string in RGB hex format
*/
void fortitude_renderStringInFont(SDL_Renderer *renderer, fortitude_Font *font, const wchar_t *string, int x, int y, int foreground, int background);

/*
	fortitude_renderCharacterInFont() -- renders a character in the provided font
	*renderer - render to perform render operations
	*character - wchar_t to render to the screen
	x - x character position
	y - y character position
	foreground - foreground colour for string in RGB hex format
	background - background colour for string in RGB hex format
*/
void fortitude_renderCharacterInFont(SDL_Renderer *renderer, fortitude_Font *font, wchar_t character, int x, int y, int foreground, int background);

/*
	fortitude_getFontPositionFromCharacter() -- gets position integer for character on glyph sheet for later decomposition
	character - character for position finding
*/
int fortitude_getFontPositionFromCharacter(wchar_t character);

#endif