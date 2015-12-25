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

#include "tile.h"

#include <stdlib.h>

hearth_Tile *hearth_createTile(hearth_TileForm tileForm, uint32_t temperature)
{
	hearth_Tile *tile = (hearth_Tile *)malloc(sizeof(hearth_Tile));
	tile->tileForm = tileForm;
	tile->temperature = temperature;
	tile->visible = rand() % 2;
	return tile;
}