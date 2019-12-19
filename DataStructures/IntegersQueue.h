/*
 * IntegersQueue.h
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#ifndef DATASTRUCTURES_INTEGERSQUEUE_H_
#define DATASTRUCTURES_INTEGERSQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ST_queueInfo
{
	int* data;
	int FrontElement;
	int BackElement;
	int size;

}ST_queueInfo;

void createQueue(ST_queueInfo* info, int maxSize);
void enqueue(ST_queueInfo *info, int data);
void dequeue(ST_queueInfo *info, int* data);

#endif /* DATASTRUCTURES_INTEGERSQUEUE_H_ */
