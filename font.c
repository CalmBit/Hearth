﻿#include "font.h"

int fortitude_getFontPositionFromCharacter(unsigned character)
{
	int rowX = 0;
	int rowY = 0;
	if (character >= 0x20 && character < 0x80)
	{
		rowX = character % 16;
		rowY = (int)floor((double)(character / 16));
	}
	else
	{
		switch (character)
		{
			case L'■':
				rowX = 14;
				rowY = 15;
				break;
			case L'²':
				rowX = 13;
				rowY = 15;
				break;
			case L'ⁿ':
				rowX = 12;
				rowY = 15;
				break;
			case L'√':
				rowX = 11;
				rowY = 15;
				break;
			case L'·':
				rowX = 10;
				rowY = 15;
				break;
			case L'°':
				rowX = 8;
				rowY = 15;
				break;
			case L'≈':
				rowX = 7;
				rowY = 15;
				break;
			case L'÷':
				rowX = 6;
				rowY = 15;
				break;
			case L'⌡':
				rowX = 5;
				rowY = 15;
				break;
			case L'⌠':
				rowX = 4;
				rowY = 15;
				break;
			case L'≥':
				rowX = 3;
				rowY = 15;
				break;
			case L'≤':
				rowX = 2;
				rowY = 15;
				break;
			case L'±':
				rowX = 1;
				rowY = 15;
				break;
			case L'≡':
				rowX = 0;
				rowY = 15;
				break;
			case L'∩':
				rowX = 15;
				rowY = 14;
				break;
			case L'ε':
				rowX = 14;
				rowY = 14;
				break;
			case L'φ':
				rowX = 13;
				rowY = 14;
				break;
			case L'∞':
				rowX = 12;
				rowY = 14;
				break;
			case L'δ':
				rowX = 11;
				rowY = 14;
				break;
			case L'Ω':
				rowX = 10;
				rowY = 14;
				break;
			case L'Θ':
				rowX = 9;
				rowY = 14;
				break;
			case L'Φ':
				rowX = 8;
				rowY = 14;
				break;
			case L'τ':
				rowX = 7;
				rowY = 14;
				break;
			case L'µ':
				rowX = 6;
				rowY = 14;
				break;
			case L'σ':
				rowX = 5;
				rowY = 14;
				break;
			case L'Σ':
				rowX = 4;
				rowY = 14;
				break;
			case L'π':
				rowX = 3;
				rowY = 14;
				break;
			case L'Γ':
				rowX = 2;
				rowY = 14;
				break;
			case L'ß':
				rowX = 1;
				rowY = 14;
				break;
			case L'α':
				rowX = 0;
				rowY = 14;
				break;
			case L'▀':
				rowX = 15;
				rowY = 13;
				break;
			case L'▐':
				rowX = 14;
				rowY = 13;
				break;
			case L'▌':
				rowX = 13;
				rowY = 13;
				break;
			case L'▄':
				rowX = 12;
				rowY = 13;
				break;
			case L'█':
				rowX = 11;
				rowY = 13;
				break;
			case L'┌':
				rowX = 10;
				rowY = 13;
				break;
			case L'┘':
				rowX = 9;
				rowY = 13;
				break;
			case L'╪':
				rowX = 8;
				rowY = 13;
				break;
			case L'╫':
				rowX = 7;
				rowY = 13;
				break;
			case L'╓':
				rowX = 6;
				rowY = 13;
				break;
			case L'╒':
				rowX = 5;
				rowY = 13;
				break;
			case L'╘':
				rowX = 4;
				rowY = 13;
				break;
			case L'╙':
				rowX = 3;
				rowY = 13;
				break;
			case L'╥':
				rowX = 2;
				rowY = 13;
				break;
			case L'╤':
				rowX = 1;
				rowY = 13;
				break;
			case L'╨':
				rowX = 0;
				rowY = 13;
				break;
			case L'╧':
				rowX = 15;
				rowY = 12;
				break;
			case L'╬':
				rowX = 14;
				rowY = 12;
				break;
			case L'═':
				rowX = 13;
				rowY = 12;
				break;
			case L'╠':
				rowX = 12;
				rowY = 12;
				break;
			case L'╦':
				rowX = 11;
				rowY = 12;
				break;
			case L'╩':
				rowX = 10;
				rowY = 12;
				break;
			case L'╔':
				rowX = 9;
				rowY = 12;
				break;
			case L'╚':
				rowX = 8;
				rowY = 12;
				break;
			case L'╟':
				rowX = 7;
				rowY = 12;
				break;
			case L'╞':
				rowX = 6;
				rowY = 12;
				break;
			case L'┼':
				rowX = 5;
				rowY = 12;
				break;
			case L'─':
				rowX = 4;
				rowY = 12;
				break;
			case L'├':
				rowX = 3;
				rowY = 12;
				break;
			case L'┬':
				rowX = 2;
				rowY = 12;
				break;
			case L'┴':
				rowX = 1;
				rowY = 12;
				break;
			case L'└':
				rowX = 0;
				rowY = 12;
				break;
			case L'┐':
				rowX = 15;
				rowY = 11;
				break;
			case L'╛':
				rowX = 14;
				rowY = 11;
				break;
			case L'╜':
				rowX = 13;
				rowY = 11;
				break;
			case L'╝':
				rowX = 12;
				rowY = 11;
				break;
			case L'╗':
				rowX = 11;
				rowY = 11;
				break;
			case L'║':
				rowX = 10;
				rowY = 11;
				break;
			case L'╣':
				rowX = 9;
				rowY = 11;
				break;
			case L'╕':
				rowX = 8;
				rowY = 11;
				break;
			case L'╖':
				rowX = 7;
				rowY = 11;
				break;
			case L'╢':
				rowX = 6;
				rowY = 11;
				break;
			case L'╡':
				rowX = 5;
				rowY = 11;
				break;
			case L'┤':
				rowX = 4;
				rowY = 11;
				break;
			case L'│':
				rowX = 3;
				rowY = 11;
				break;
			case L'▓':
				rowX = 2;
				rowY = 11;
				break;
			case L'▒':
				rowX = 1;
				rowY = 11;
				break;
			case L'░':
				rowX = 0;
				rowY = 11;
				break;
			case L'»':
				rowX = 15;
				rowY = 10;
				break;
			case L'«':
				rowX = 14;
				rowY = 10;
				break;
			case L'¡':
				rowX = 13;
				rowY = 10;
				break;
			case L'¼':
				rowX = 12;
				rowY = 10;
				break;
			case L'½':
				rowX = 11;
				rowY = 10;
				break;
			case L'¬':
				rowX = 10;
				rowY = 10;
				break;
			case L'⌐':
				rowX = 9;
				rowY = 10;
				break;
			case L'¿':
				rowX = 8;
				rowY = 10;
				break;
			case L'º':
				rowX = 7;
				rowY = 10;
				break;
			case L'ª':
				rowX = 6;
				rowY = 10;
				break;
			case L'Ñ':
				rowX = 5;
				rowY = 10;
				break;
			case L'ñ':
				rowX = 4;
				rowY = 10;
				break;
			case L'ú':
				rowX = 3;
				rowY = 10;
				break;
			case L'ó':
				rowX = 2;
				rowY = 10;
				break;
			case L'í':
				rowX = 1;
				rowY = 10;
				break;
			case L'á':
				rowX = 0;
				rowY = 10;
				break;
			case L'ƒ':
				rowX = 15;
				rowY = 9;
				break;
			case L'₧':
				rowX = 14;
				rowY = 9;
				break;
			case L'¥':
				rowX = 13;
				rowY = 9;
				break;
			case L'£':
				rowX = 12;
				rowY = 9;
				break;
			case L'¢':
				rowX = 11;
				rowY = 9;
				break;
			case L'Ü':
				rowX = 10;
				rowY = 9;
				break;
			case L'Ö':
				rowX = 9;
				rowY = 9;
				break;
			case L'ÿ':
				rowX = 8;
				rowY = 9;
				break;
			case L'ù':
				rowX = 7;
				rowY = 9;
				break;
			case L'û':
				rowX = 6;
				rowY = 9;
				break;
			case L'ò':
				rowX = 5;
				rowY = 9;
				break;
			case L'ö':
				rowX = 4;
				rowY = 9;
				break;
			case L'ô':
				rowX = 3;
				rowY = 9;
				break;
			case L'Æ':
				rowX = 2;
				rowY = 9;
				break;
			case L'æ':
				rowX = 1;
				rowY = 9;
				break;
			case L'É':
				rowX = 0;
				rowY = 9;
				break;
			case L'Å':
				rowX = 15;
				rowY = 8;
				break;
			case L'Ä':
				rowX = 14;
				rowY = 8;
				break;
			case L'ì':
				rowX = 13;
				rowY = 8;
				break;
			case L'î':
				rowX = 12;
				rowY = 8;
				break;
			case L'ï':
				rowX = 11;
				rowY = 8;
				break;
			case L'è':
				rowX = 10;
				rowY = 8;
				break;
			case L'ë':
				rowX = 9;
				rowY = 8;
				break;
			case L'ê':
				rowX = 8;
				rowY = 8;
				break;
			case L'ç':
				rowX = 7;
				rowY = 8;
				break;
			case L'å':
				rowX = 6;
				rowY = 8;
				break;
			case L'à':
				rowX = 5;
				rowY = 8;
				break;
			case L'ä':
				rowX = 4;
				rowY = 8;
				break;
			case L'â':
				rowX = 3;
				rowY = 8;
				break;
			case L'é':
				rowX = 2;
				rowY = 8;
				break;
			case L'ü':
				rowX = 1;
				rowY = 8;
				break;
			case L'Ç':
				rowX = 0;
				rowY = 8;
				break;
			case L'⌂':
				rowX = 15;
				rowY = 7;
				break;
			case L'▼':
				rowX = 15;
				rowY = 1;
				break;
			case L'▲':
				rowX = 14;
				rowY = 1;
				break;
			case L'↔':
				rowX = 13;
				rowY = 1;
				break;
			case L'∟':
				rowX = 12;
				rowY = 1;
				break;
			case L'←':
				rowX = 11;
				rowY = 1;
				break;
			case L'→':
				rowX = 10;
				rowY = 1;
				break;
			case L'↓':
				rowX = 9;
				rowY = 1;
				break;
			case L'↑':
				rowX = 8;
				rowY = 1;
				break;
			case L'↨':
				rowX = 7;
				rowY = 1;
				break;
			case L'▬':
				rowX = 6;
				rowY = 1;
				break;
			case L'§':
				rowX = 5;
				rowY = 1;
				break;
			case L'¶':
				rowX = 4;
				rowY = 1;
				break;
			case L'‼':
				rowX = 3;
				rowY = 1;
				break;
			case L'↕':
				rowX = 2;
				rowY = 1;
				break;
			case L'◄':
				rowX = 1;
				rowY = 1;
				break;
			case L'►':
				rowX = 0;
				rowY = 1;
				break;
			case L'☼':
				rowX = 15;
				break;
			case L'♫':
				rowX = 14;
				break;
			case L'♪':
				rowX = 13;
				break;
			case L'♀':
				rowX = 12;
				break;
			case L'♂':
				rowX = 11;
				break;
			case L'◙':
				rowX = 10;
				break;
			case L'○':
				rowX = 9;
				break;
			case L'◘':
				rowX = 8;
				break;
			case L'•':
				rowX = 7;
				break;
			case L'♠':
				rowX = 6;
				break;
			case L'♣':
				rowX = 5;
				break;
			case L'♦':
				rowX = 4;
				break;
			case L'♥':
				rowX = 3;
				break;
			case L'☻':
				rowX = 2;
				break;
			case L'☺':
				rowX = 1;
				break;
		}
	}
	return rowY * 16 + rowX;
}