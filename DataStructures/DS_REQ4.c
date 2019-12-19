/*
 * DS_REQ4.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */


#include "ExpressionEvaluation.h"

void DS_REQ4(void)
{
	char str[] = "()(5+49/2)*(521*2-1)()";
	printf("%lld", evaluate(str));
}

