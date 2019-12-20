/*
 * DS_REQ5.c
 *
 *  Created on: Dec 20, 2019
 *      Author: Omar Zayed
 */

#include "IntegersList.h"

void DS_REQ5(void);

void DS_REQ5(void)
{
	ST_list L1;
	ST_node N1;
	ST_node* ptr = &N1;
	createList(&L1);
	insertToList(L1.listHead, 0, 5);
	ptr = searchIntoList(L1.listHead, 5);
	printf("%d", ptr->data);


}


