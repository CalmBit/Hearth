#ifndef _FORT_ERROR_H
#define _FORT_ERROR_H

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
	//200-299 are reserved for non-fatal errors, such as missing files.
	ASSET_LOAD_FAILURE = 200,
} fortitude_ErrorCode;

/*
	 throwError() -- throw fatal error and exit with code.
	 message - string to use as error message.
	 code - integer to use as exit code
 */
void fortitude_throwError(const char *message, fortitude_ErrorCode code);

#endif