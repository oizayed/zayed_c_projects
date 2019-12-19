/*
 * DS_REQ2.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#include "checkForBalancedParantheses.h"

void DS_REQ2(void)
{
	char str[] = "(){{()[()(())]}}";
	printf("%c", checkForBalancedParantheses(str));
}

