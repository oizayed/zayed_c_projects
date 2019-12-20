/*
 * IntegersList.h
 *
 *  Created on: Dec 20, 2019
 *      Author: Omar Zayed
 */

#ifndef ZAYED_C_PROJECTS_DATASTRUCTURES_INTEGERSLIST_H_
#define ZAYED_C_PROJECTS_DATASTRUCTURES_INTEGERSLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ST_node
{
	int data;
	struct ST_node* next;
}ST_node;

typedef struct ST_list
{
	ST_node* listHead;

}ST_list;

char createList(ST_list *list);
void insertToList(ST_node *listHead, unsigned char position, int data);
void deleteFromList(ST_node *listHead, unsigned char position, int* data);
ST_node* searchIntoList(ST_node *listHead, int data);
void sortList(ST_node *listHead);	//Bonus
void reverseList(ST_node *listHead);	//Bonus


#endif /* ZAYED_C_PROJECTS_DATASTRUCTURES_INTEGERSLIST_H_ */
