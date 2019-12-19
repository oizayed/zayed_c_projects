/*
 * IntegersQueue.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#include "IntegersQueue.h"

void createQueue(ST_queueInfo* info, int maxSize)
{
	info->data = (int*) malloc(maxSize * sizeof(int));

	if(info->data == NULL)
	{
		printf("No Enough Memory! \n");
	}
	else
	{
		info->size = maxSize;
		info->FrontElement = 0;
		info->BackElement = -1;
	}
}


void enqueue(ST_queueInfo *info, int data)
{
	if(info->BackElement == (info->size - 1))
	{
		printf("Queue is full! \n");
	}
	else
	{
		info->BackElement++;
		info->data[info->BackElement] = data;
	}
}


void dequeue(ST_queueInfo *info, int* data)
{
	if(info->BackElement < info->FrontElement)
	{
		printf("Queue is empty! \n");
	}
	else
	{
		*data = info->data[info->FrontElement];
		info->FrontElement++;
	}
}

