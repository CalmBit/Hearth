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

#ifndef HEARTH_STDDEFS_H
#define HEARTH_STDDEFS_H

//Window Dimensions
#define HEARTH_WINDOW_COLUMNS 80
#define HEARTH_WINDOW_ROWS 25

//Player Default Values
#define HEARTH_DEFAULT_PLAYER_HEALTH 20
#define HEARTH_DEFAULT_PLAYER_MANA 100

//Turn Frame Delay
#define HEARTH_STANDARD_TURN_TIMER 15

//Player Level Cap
#define HEARTH_LEVEL_CAP 15

//Max Item Count
#define HEARTH_ITEM_NUM 16

//Default Image Paths
#define HEARTH_DEFAULTIMG_PATH "assets/img/curses_640x300.png"
#define HEARTH_FALLBACKIMG_PATH "assets/img/fallback.png"

//Error Strings
#define HEARTH_ERRORSTR_NOLOADIMG "Image at path %s couldn't be loaded!"
#define HEARTH_ERRORSTR_FALLBACKMISSING "Fallback image is missing!"
#define HEARTH_ERRORSTR_TEXCREATEFAIL "Texture failed to created from image at path %s!"
#define HEARTH_ERRORSTR_RENDERNULL "Renderer was passed as NULL!"
#define HEARTH_ERRORSTR_SPRSHTCOL "SpriteSheet column was out of bounds!"
#define HEARTH_ERRORSTR_SPRSHTROW "SpriteSheet row was out of bounds!"
#define HEARTH_ERRORSTR_TILEARRBAD "Tile array wasn't initialized properly!"
#define HEARTH_ERRORSTR_GAMEOBJNULL "Game object was uninitialized!"

//Item Strings
//Item Names
#define HEARTH_ITEMNAME_MINPOTHEAL "Minor Potion of Healing"
#define HEARTH_ITEMNAME_REGPOTHEAL "Potion of Healing"
#define HEARTH_ITEMNAME_MAJPOTHEAL "Greater Potion of Healing"

//Item Descriptions
#define HEARTH_ITEMDESC_MINPOTHEAL "Heals for 2 Points."
#define HEARTH_ITEMDESC_REGPOTHEAL "Heals for 5 Points."
#define HEARTH_ITEMDESC_MAJPOTHEAL "Heals for 10 Points."


#endif