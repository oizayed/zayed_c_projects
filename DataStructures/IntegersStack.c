/*
 * IntegersStack.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */


#include "IntegersStack.h"



void createStack(ST_stackInfo *info, int size)
{
	info->data = (int*) malloc(size * sizeof(int));

	if(info->data == NULL)
	{
		printf("No Enough Memory! \n");
	}
	else
	{
		info->size = size;
		info->TopElement = -1;
	}

}



void push(ST_stackInfo *info, int data)
{
	if(info->TopElement == (info->size - 1))
	{
		printf("Stack is full! \n");
	}
	else
	{
		info->TopElement++;
		info->data[info->TopElement] = data;
	}

}



void pop(ST_stackInfo *info, int* data)
{
	if(info->TopElement == -1)
	{
		printf("Stack is empty! \n");
	}
	else
	{
		*data = info->data[info->TopElement];
		info->TopElement--;
	}

}


