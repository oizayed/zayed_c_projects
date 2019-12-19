/*
 * alternatingCharacters.c
 *
 *  Created on: Oct 7, 2019
 *      Author: OZ
 */
#include "usedLibs.h"

int alternatingCharacters(char* s) {

	int del = 0;
	for (int x = 1; s[x] != '\0'; x++)
	{
		if(s[x] == s[x - 1])
		{
			del++;
		}
	}
		return del;
}


void alternatingCharactersMain(void)
{
	char input[] = "AAABBB";
	printf("%d", alternatingCharacters(input));
}
