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

#include "item.h"
#include "stddefs.h"
#include "player.h"
#include <stdio.h>

hearth_Item itemList[HEARTH_ITEM_NUM] =
{
	{
		"Minor Potion of Healing",
		"Heals for 2 Health.",
		L'i',
		0x00FF88,
		0x000000,
		ITEM_POTION,
		&hearth_ItemEffect_MinorPotionHeal
	},
	{
		"Potion of Healing",
		"Heals for 4 health.",
		L'i',
		0x00FFFF,
		0x000000,
		ITEM_POTION,
		&hearth_ItemEffect_RegularPotionHeal
	}
};

void hearth_ItemEffect_MinorPotionHeal(void *player)
{
	printf("MinorPotionTest");
	hearth_damagePlayer((hearth_Player *)player, -2);
}

void hearth_ItemEffect_RegularPotionHeal(void *player)
{
	printf("RegularPotionTest");
	hearth_damagePlayer((hearth_Player *)player, -4);
}