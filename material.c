#include "material.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"

fortitude_Material *fortitude_loadMaterial(const char *path)
{
	fortitude_Material *material = (fortitude_Material *)malloc(sizeof(fortitude_Material));

	FILE *materialFile = fopen(path, "r");
	if (materialFile == NULL)
	{
		fortitude_throwError("Material not found!", MATERIAL_NOT_FOUND);
		return NULL;
	}

	char buffer[1024];
	while (!feof(materialFile))
	{
		//Read a line
		fscanf(materialFile, "%s", buffer);
		//Check the line has proper formatting
		if (buffer[0] != '{' || buffer[strlen(buffer) - 1] != '}')
		{
			fortitude_throwError("Curly braces not surrounding file!", MATERIAL_SYNTAX_ERROR);
			fclose(materialFile);
			return NULL;
		}
		//Start token parsing
		char *token = strtok(buffer, ":");
		int tokenCount = 0;
		enum MaterialFileTokenType type = TOKEN_NULL;
		//Still got tokens?
		while (token)
		{
			//If a token isn't a syntactic element, keep parsing
			if (strcmp(token, "{") != 0 && strcmp(token, "}") != 0)
			{
				tokenCount++;
				if (tokenCount == MATERIAL_TOKEN_HEADER)
				{
					if (strcmp(token, "MAT") == 0) type = TOKEN_MAT;
					else if (strcmp(token, "MATERIAL_NAME") == 0) type = TOKEN_MATERIAL_NAME;
					else if (strcmp(token, "MATERIAL_HARDNESS") == 0) type = TOKEN_MATERIAL_HARDNESS;
					else if (strcmp(token, "MATERIAL_BGC") == 0) type = TOKEN_MATERIAL_BGC;
					else if (strcmp(token, "MATERIAL_FGC") == 0) type = TOKEN_MATERIAL_FGC;
					else if (strcmp(token, "MATERIAL_CHAR") == 0) type = TOKEN_MATERIAL_CHAR;
					else
					{
						fortitude_throwError("Material token unable to be parsed!", MATERIAL_TOKEN_INVALID);
						continue;
					}
				}
				//First argument parsing round
				if (tokenCount == MATERIAL_TOKEN_ARGUMENT_ONE)
				{
					switch (type)
					{
					case TOKEN_MAT:
						strcpy(material->handle, token);
						break;
					case TOKEN_MATERIAL_HARDNESS:
						material->hardness = (unsigned int)strtol(token,NULL,10);
						break;
					case TOKEN_MATERIAL_BGC:
						material->background_colour = (unsigned int)strtol(token, NULL, 16);
						break;
					case TOKEN_MATERIAL_FGC:
						material->foreground_colour = (unsigned int)strtol(token, NULL, 16);
						break;
					case TOKEN_MATERIAL_CHAR:
						material->character = (unsigned int)strtol(token, NULL, 16);
						break;
					case TOKEN_MATERIAL_NAME:
						strcpy(material->singular, token);
					}
				}
				//Second argument parsing round
				if (tokenCount == MATERIAL_TOKEN_ARGUMENT_TWO)
				{
					switch (type)
					{
					case TOKEN_MAT:
						if (strcmp(token, "MINERAL") == 0) material->type = MINERAL;
						else if (strcmp(token, "GEMSTONE") == 0) material->type = GEMSTONE;
						else if (strcmp(token, "METAL") == 0) material->type = METAL;
						else if (strcmp(token, "PLANT") == 0) material->type = PLANT;
						else if (strcmp(token, "LIQUID") == 0) material->type = LIQUID;
						else
						{
							fortitude_throwError("Material token invalid!", MATERIAL_TYPE_INVALID);
							return NULL;
						}
						break;
					case TOKEN_MATERIAL_NAME:
						if (strcmp(token, "NA") == 0) strcpy(material->plural, material->singular);
						else strcpy(material->plural, token);
						break;
					}
				}
			}
			token = strtok(NULL, ":");
		}
	}
	fclose(materialFile);
	material->type = MINERAL;
	return material;
}