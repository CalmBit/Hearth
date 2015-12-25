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

const hearth_Item itemList[HEARTH_ITEM_NUM] =
{
	{
		HEARTH_ITEMNAME_MINPOTHEAL,
		HEARTH_ITEMDESC_MINPOTHEAL,
		L'i',
		0x00FF88,
		0x000000,
		ITEM_POTION,
		&hearth_ItemEffect_MinorPotionHeal
	},
	{
		HEARTH_ITEMNAME_REGPOTHEAL,
		HEARTH_ITEMDESC_REGPOTHEAL,
		L'i',
		0x00FFFF,
		0x000000,
		ITEM_POTION,
		&hearth_ItemEffect_RegularPotionHeal
	},
	{
		HEARTH_ITEMNAME_MAJPOTHEAL,
		HEARTH_ITEMDESC_MAJPOTHEAL,
		L'i',
		0x88FFFF,
		0x000000,
		ITEM_POTION,
		&hearth_ItemEffect_GreaterPotionHeal
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
	hearth_damagePlayer((hearth_Player *)player, -5);
}

void hearth_ItemEffect_GreaterPotionHeal(void *player)
{
	printf("GreaterPotionTest");
	hearth_damagePlayer((hearth_Player *)player, -10);
}