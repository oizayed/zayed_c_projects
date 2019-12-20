/*
 * IntegersList.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Omar Zayed
 */


#include "IntegersList.h"

char createList(ST_list *list)
{
	list->listHead = NULL;
	return 0;
}



void insertToList(ST_node *listHead, unsigned char position, int data)
{
	ST_node* N = (ST_node*) malloc(sizeof(ST_node));
	ST_node* ptr = (ST_node*) malloc(sizeof(ST_node));
	unsigned char posOut = 0;

	if((N == NULL) || (ptr == NULL))
 	{
		printf("No Enough Memory! \n");
	}
	else
	{
		ptr = listHead;
		N->data = data;
		if((ptr == NULL) && (position != 0))
		{
			printf("Position Invalid! \n");
		}
		else if(position == 0)
		{
			N->next = NULL;
			listHead = N;
		}
		else
		{
			for(int x = 0; x != (position - 1); x++)
			{
				if(ptr->next == NULL)
				{
					printf("Position Invalid! \n");
					posOut = 1;
					break;
				}
				else
				{
					ptr = ptr->next;
				}
			}

			if(posOut == 0)
			{
				N->next = ptr->next;
				ptr->next = N;
			}
		}


	}

}



void deleteFromList(ST_node *listHead, unsigned char position, int* data)
{

}



ST_node* searchIntoList(ST_node *listHead, int data)
{
	return listHead;
}



void sortList(ST_node *listHead)
{

}



void reverseList(ST_node *listHead)
{

}

