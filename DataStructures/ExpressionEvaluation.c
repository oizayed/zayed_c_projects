/*
 * ExpressionEvaluation.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */



#include "ExpressionEvaluation.h"

long long evaluate(char* expression)
{
	int expSize = strlen(expression);
	int y = 0;
	int Out = 0;
	char* parantheses = (char *) malloc(expSize * sizeof(char));

	if(parantheses == NULL)
	{
		printf("No Enough Memory! \n");
	}
	else
	{
		for(int x = 0; x < expSize; x++)
		{
			if((expression[x] > 57) || (expression[x] < 48))
			{
				parantheses[y] = expression[x];
				y++;
			}
		}

		if(checkForBalancedParantheses(parantheses) == 'n')
		{
			printf("Expression not balanced! \n");
		}
		else
		{

		}
	}







	return Out;
}

