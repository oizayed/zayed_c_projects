/* *****************************************************************
 *  Algorithm_3.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

#include <stdio.h>

/*********************************************************************************
*	Given a number, print floor of 5’th root of the number.
*	
*	Input  : n = 32
*	Output : 2
*	2 raise to power 5 is 32
*
*	Input  : n = 250
*	Output : 3
*	Fifth square root of 250 is between 3 and 4
*	So floor value is 3.
********************************************************************************/ 
 
int Linear_floorRoot5(int n)
{
	int i;
	for(i = 0; ((i*i*i*i*i) <= n); i++)
	{

	}
	i--;
	return i;
}


void Algorithm_3Main(void)
{
	printf("%d", Linear_floorRoot5(3125));
}


