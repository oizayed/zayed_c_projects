/* *****************************************************************
 *  Algorithm_2.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/
#include <stdio.h>

/*********************************************************************************
 *	Given a number n, write a program to print a diamond shape with 2n rows.
 *
 *	Input: 5
 *	Output:
 *				*
 *			   * *
 *			  * * *
 *			 * * * *
 *			* * * * *
 *			* * * * *
 *			 * * * *
 *			  * * *
 *			   * *
 *				*
 ********************************************************************************/

void PrintDiamond(int n)
{
	int i, j;
	int x = (n + 1) % 2; // To find if even or odd
	for(i = 0; i < n ; i++)
	{
		for(j = 0; j < (n + i); j++)
		{
			if((i + j) < (n - 1))
			{
				printf(" "); // we leave the right no of spaces before printing
			}
			else if (((i + j) % 2) == x)
			{
				printf("*"); // we print when i + j is even when n is odd and vice versa
			} else
			{
				printf(" ");
			}

		}
		printf("\n");
	}

	i--;
	for(; i >= 0 ; i--)
	{
		for(j = 0; j < (n + i); j++)
		{
			if((i + j) < (n - 1))
			{
				printf(" ");
			}
			else if (((i + j) % 2) == x)
			{
				printf("*");
			} else
			{
				printf(" ");
			}

		}
		printf("\n");

	}
}

void Algorithm_2Main(void)
{
	int x = 5;
	PrintDiamond(x);
}


