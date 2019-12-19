/*
 * DS_REQ1.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */


#include "IntegersStack.h"

void DS_REQ1(void);


void DS_REQ1(void)
{
	ST_stackInfo Stack1;
	int var;
	createStack(&Stack1, 5);
	push(&Stack1, 5);
	push(&Stack1, 4);
	push(&Stack1, 3);
	push(&Stack1, 2);
	push(&Stack1, 1);
	push(&Stack1, 0);
	pop(&Stack1, &var);
	printf("%d \n", var);
	pop(&Stack1, &var);
	printf("%d \n", var);
	pop(&Stack1, &var);
	printf("%d \n", var);
	pop(&Stack1, &var);
	printf("%d \n", var);
	free(Stack1.data);
	pop(&Stack1, &var);
	printf("%d \n", var);


}
