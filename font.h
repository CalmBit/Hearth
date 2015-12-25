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

#ifndef HEARTH_FONT_H
#define HEARTH_FONT_H

#include <math.h>

#include "image.h"

/*
	struct hearth_Font -- font object with which to render characters
	*spriteSheet -- spritesheet containing character glyphs
*/
typedef struct hearth_Font
{
	hearth_SpriteSheet *spriteSheet;
} hearth_Font;

/*
	hearth_createFont() -- hearth_Font factory
	*renderer - render to perform render operations
	*path - path to font image file
	charSizeX - width of characters
	charSizeY - height of characters
*/
hearth_Font *hearth_createFont(SDL_Renderer *renderer, const char *path, uint32_t charSizeX, uint32_t charSizeY);

/*
	hearth_renderStringInFont() -- renders a string in the provided font
	*renderer - render to perform render operations
	*string - wchar_t string to render to the screen
	x - x character position for string
	y - y character position for string
	foreground - foreground colour for string in RGB hex format
	background - background colour for string in RGB hex format
*/
void hearth_renderStringInFont(SDL_Renderer *renderer, hearth_Font *font, const wchar_t *string, uint32_t x, uint32_t y, uint32_t foreground, uint32_t background);

/*
	hearth_renderCharacterInFont() -- renders a character in the provided font
	*renderer - render to perform render operations
	*character - wchar_t to render to the screen
	x - x character position
	y - y character position
	foreground - foreground colour for string in RGB hex format
	background - background colour for string in RGB hex format
*/
void hearth_renderCharacterInFont(SDL_Renderer *renderer, hearth_Font *font, wchar_t character, uint32_t x, uint32_t y, uint32_t foreground, uint32_t background);

/*
	hearth_getFontPositionFromCharacter() -- gets position uint32_teger for character on glyph sheet for later decomposition
	character - character for position finding
*/
uint32_t hearth_getFontPositionFromCharacter(wchar_t character);

void hearth_destroyFont(hearth_Font *font);

#endif