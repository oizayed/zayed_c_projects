/*
 * ExpressionEvaluation.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */



#include "ExpressionEvaluation.h"
#include "checkForBalancedParantheses.h"

long long evaluate(char* expression)
{
	int expSize = strlen(expression);
	int y = 0;
	int Out = 0;
	int Num = 0;
	int Oper;
	ST_queueInfo Queue;
	createQueue(&Queue, expSize);
	char* parantheses = (char *) malloc(expSize * sizeof(char));

	if(parantheses == NULL)
	{
		printf("No Enough Memory! \n");
	}
	else
	{
		for(int x = 0; x < expSize; x++)
		{
			if((expression[x] == '{') || (expression[x] == '(') || (expression[x] == '[') || (expression[x] == ']') || (expression[x] == '}') || (expression[x] == ')'))
			{
				parantheses[y] = expression[x];
				y++;
			}
		}

		if(checkForBalancedParantheses(parantheses) == 'n')
		{
			printf("Expression not balanced! \n");
			free(parantheses);
		}
		else
		{
			for(int x = 0; x < expSize; x++)
			{
				if((expression[x] < 58) && (expression[x] > 47))
				{
					Num = (Num * 10) + (expression[x] - '0');
				}
				else if((expression[x] == '+') || (expression[x] == '-') || (expression[x] == '*') || (expression[x] == '/'))
				{
					enqueue(&Queue, Num);
					Num = 0;
					enqueue(&Queue, expression[x]);
				}

				if(x == (expSize - 1))
				{
					enqueue(&Queue, Num);
					Num = 0;
				}
			}

			dequeue(&Queue, &Out);

			while(Queue.BackElement >= Queue.FrontElement)
			{
				dequeue(&Queue, &Oper);
				dequeue(&Queue, &Num);
				if(Oper == '+')
				{
					Out += Num;
				}
				if(Oper == '-')
				{
					Out -= Num;
				}
				if(Oper == '*')
				{
					Out *= Num;
				}
				if(Oper == '/')
				{
					Out /= Num;
				}
			}
		}
	}
	return Out;
}

