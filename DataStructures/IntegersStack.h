/*
 * IntegersStack.h
 *
 *  Created on: Dec 19, 2019
 *      Author: Omar Zayed
 */

#ifndef DATASTRUCTURES_INTEGERSSTACK_H_
#define DATASTRUCTURES_INTEGERSSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ST_stackInfo
{
	int* data;
	int TopElement;
	int size;

}ST_stackInfo;

void createStack(ST_stackInfo *info, int size);
void push(ST_stackInfo *info, int data);
void pop(ST_stackInfo *info, int* data);


#endif /* DATASTRUCTURES_INTEGERSSTACK_H_ */
