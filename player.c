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

#include "player.h"
#include "stddefs.h"
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdint.h>

const uint32_t levelXPRequirements[HEARTH_LEVEL_CAP] = { 0, 5, 10, 20, 40, 80, 160, 320, 640, 1280, 2560, 5120, 10240, 20480, 40960 };

hearth_Player *hearth_createPlayer(const wchar_t *name, uint32_t spawnX, uint32_t spawnY)
{
	hearth_Player *player = (hearth_Player *)malloc(sizeof(hearth_Player));
	player->maxHealth = player->health = HEARTH_DEFAULT_PLAYER_HEALTH;
	player->maxMana = player->mana = HEARTH_DEFAULT_PLAYER_MANA;
	player->name = (wchar_t *)malloc(sizeof(wchar_t)*(wcslen(name)+1));
	wcscpy_s(player->name, wcslen(name) + 1, name);
	player->posX = spawnX;
	player->posY = spawnY;
	return player;
}

void hearth_destroyPlayer(hearth_Player *player)
{
	free(player->name);
	free(player);
}

void hearth_damagePlayer(hearth_Player *player, uint32_t damage)
{
	if (player->health - damage < 0) player->health = 0;
	else if (player->health - damage > player->maxHealth) player->health = player->maxHealth;
	else player->health -= damage;
}