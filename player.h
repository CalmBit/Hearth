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

#ifndef HEARTH_PLAYER_H
#define HEARTH_PLAYER_H

#include <wchar.h>
#include <stdint.h>
#include "stddefs.h"

extern const uint32_t levelXPRequirements[HEARTH_LEVEL_CAP];

/*
	struct hearth_Player -- player data
	health - player's current health
	maxHealth - player's maximum health
	mana - player's current mana
	maxMana - player's maximum mana
	*name - player's name string
*/
typedef struct hearth_Player
{
	uint32_t health;
	uint32_t maxHealth;
	uint32_t mana;
	uint32_t maxMana;
	wchar_t *name;
	uint32_t posX, posY;
	uint32_t level;
	uint32_t xp;
} hearth_Player;

hearth_Player *hearth_createPlayer(const wchar_t* name, uint32_t spawnX, uint32_t spawnY);

void hearth_destroyPlayer(hearth_Player *player);

void hearth_damagePlayer(hearth_Player *player, uint32_t damage);


#endif