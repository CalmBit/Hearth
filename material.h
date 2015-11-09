#ifndef _FORT_MATERIAL_H
#define _FORT_MATERIAL_H

#include <wchar.h>

enum MaterialFilePosition
{
	MATERIAL_POSITION_NULL = 0,
	MATERIAL_TOKEN_HEADER = 1,
	MATERIAL_TOKEN_ARGUMENT_ONE = 2,
	MATERIAL_TOKEN_ARGUMENT_TWO = 3
};

enum MaterialFileTokenType
{
	TOKEN_NULL,
	TOKEN_MAT,
	TOKEN_MATERIAL_HARDNESS,
	TOKEN_MATERIAL_BGC,
	TOKEN_MATERIAL_FGC,
	TOKEN_MATERIAL_CHAR,
	TOKEN_MATERIAL_NAME
};
typedef enum MaterialType
{
	MINERAL,
	GEMSTONE,
	METAL,
	PLANT,
	LIQUID
} fortitude_MaterialType;

typedef struct Material
{
	char handle[255];
	unsigned int hardness;
	fortitude_MaterialType type;
	unsigned int foreground_colour;
	unsigned int background_colour;
	wchar_t character;
	char singular[255];
	char plural[255];
	
} fortitude_Material;


/*
	fortitude_loadMaterial() - loads a material from a material file
	*path - string designating the path to load the material from
	returns - pointer to material if successful, NULL on error
*/
fortitude_Material *fortitude_loadMaterial(const char* path);

#endif