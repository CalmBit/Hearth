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

#ifndef HEARTH_TILE_H
#define HEARTH_TILE_H

#include <stdbool.h>
#include <stdint.h>

/*
	enum hearth_TileForm -- enum for tile form in game
*/
typedef enum TileForm 
{
	WALL,
	FLOOR,
	UP_STAIR,
	DOWN_STAIR,
	UPDOWN_STAIR,
	PILLAR
} hearth_TileForm;


/*
	struct hearth_Tile -- tile object for representing blocks
	tileForm -- form which tile will take in game
	temperature -- temperature of the tile
	visible -- visibility of tile in uint32_terface
*/
typedef struct hearth_Tile
{
	hearth_TileForm tileForm;
	uint32_t temperature;
	bool visible;
} hearth_Tile;

/*
	hearth_createTile() -- hearth_Tile factory
	tileForm -- form for tile to take on init
	temperature -- starting temperature for tile
*/
hearth_Tile *hearth_createTile(hearth_TileForm tileForm, uint32_t temperature);

#endif