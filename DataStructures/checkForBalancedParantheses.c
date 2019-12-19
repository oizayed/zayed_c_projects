/*
 * checkForBalancedParantheses.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#include "checkForBalancedParantheses.h"


unsigned char checkForBalancedParantheses(char* expression)
{
	int expSize = strlen(expression);
	int Top;
	unsigned char Out = 'Y';
	ST_stackInfo Stack;
	createStack(&Stack, expSize);
	for(int x = 0; x < expSize; x++)
	{
		if((expression[x] == '{') || (expression[x] == '(') || (expression[x] == '['))
		{
			push(&Stack, expression[x]);
		}
		else
		{
			pop(&Stack, &Top);
			if(!(((expression[x] == '}') && (Top == '{')) || ((expression[x] == ')') && (Top == '(')) || ((expression[x] == ']') && (Top == '['))))
			{
				Out = 'N';
				break;
			}
		}
	}
	if(Stack.TopElement != -1)
	{
		Out = 'N';
	}

	free(Stack.data);
	return Out;
}
