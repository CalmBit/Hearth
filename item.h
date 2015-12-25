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

#ifndef HEARTH_ITEM_H
#define HEARTH_ITEM_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	ITEM_POTION,
	ITEM_ARMOUR_HELM,
	ITEM_ARMOUR_CHEST,
	ITEM_ARMOUR_LEGS,
	ITEM_ARMOUR_BOOTS,
	ITEM_ARMOUR_BRACES,
	ITEM_WEAPON_SWORD
} hearth_ItemType;

typedef struct hearth_Item
{
	const char *name;
	const char *description;
	wchar_t symbol;
	uint32_t foreground;
	uint32_t background;
	hearth_ItemType itemType;
	void(*effect)(void *player);
} hearth_Item;

void hearth_ItemEffect_MinorPotionHeal();
void hearth_ItemEffect_RegularPotionHeal();
void hearth_ItemEffect_GreaterPotionHeal();

#endif