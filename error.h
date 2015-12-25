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

#ifndef HEARTH_ERROR_H
#define HEARTH_ERROR_H

/* 
	enum hearth_ErrorCode -- list of possible error conditions and their codes
*/
typedef enum
{
	//100-199 are reserved for fatal conditions
	BAD_SDL_INIT = 100,
	BAD_WINDOW_INIT = 101,
	BAD_RENDERER_INIT = 102,
	ESSENTIAL_ASSET_MISSING = 103,
	TEXTURE_CREATION_FAILURE = 104,
	PASSED_NULL_CONTEXT = 105,
	ARGUMENT_OOB = 106,
	PLATFORM_INCOMP = 107,
	//200-299 are reserved for non-fatal errors, such as missing files.
	ASSET_LOAD_FAILURE = 200,
	NONESSENTIAL_NULL_CONTEXT = 203,
	//300-399 are reserved for file IO/syntatic errors
} hearth_ErrorCode;

/*
	 throwError() -- throw fatal error and exit with code.
	 message - string to use as error message.
	 code - uint32_teger to use as exit code
 */
void hearth_throwError(const char *message, hearth_ErrorCode code);

#endif