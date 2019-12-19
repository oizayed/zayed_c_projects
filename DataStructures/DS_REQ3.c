/*
 * DS_REQ3.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#include "IntegersQueue.h"

void DS_REQ3(void);


void DS_REQ3(void)
{
	ST_queueInfo Queue1;
	int var;
	createQueue(&Queue1, 5);
	enqueue(&Queue1, 5);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 4);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 3);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 2);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 1);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 0);
	dequeue(&Queue1, &var);
	enqueue(&Queue1, 0);
	dequeue(&Queue1, &var);
	printf("%d \n", var);
	free(Queue1.data);
	printf("OUT %d \n", var);


}
