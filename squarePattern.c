/*
 * squarePattern.c
 *
 *  Created on: Nov 17, 2019
 *      Author: Omar Zayed
 */

#include "usedLibs.h"


void spuarePattern(int a)
{
	int x = 0;
	int y = 0;
	int c = 0;
	int d;
	int f = 0;
	while(x >= 0)
	{
		d = 0;
		while(y >= 0)
		{
			f = x < y? x : y;
			printf("%d   ", a - f);
			if(y == a)
			{
				d = 1;
			}
			if(d == 0)
			{
				y++;
			}
			if(d == 1)
			{
				y--;
			}
		}
		printf("\n");
		if(x == a)
		{
			c = 1;
		}
		if(c == 1)
		{
			x--;
		}
		if(c == 0)
		{
			x++;
		}
		y = 0;
	}


}


void squarePatternMain(void)
{
	spuarePattern(50);
}



