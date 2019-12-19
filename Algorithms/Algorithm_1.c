/* *****************************************************************
 *  Algorithm_1.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

/******************************************************************
 * Given an array of integers, return indices of
 * the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 ***********
 * example *
 ***********
 * 		input: [10,2,23,4,5], target = 6
 * 		output: [1,3]
 *
 * *****************************************************************/
#include "Algorithm_1.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i, j;
	for(i = 0; i < numsSize - 1; i++)
	{
		for(j = i + 1; j < numsSize; j++)
		{
			if((nums[i] + nums[j]) == target)
			{
				break;
			}
		}
		if((nums[i] + nums[j]) == target)
		{
			break;
		}
	}

	returnSize[0] = i;
	returnSize[1] = j;
	return returnSize;

}

void Algorithm_1Main(void)
{
	int a[] = {10,2,23,4,5};
	int a_count = 5;
	int target = 27;
	int output[2];
	twoSum( a, a_count, target, output);
	printf("%d %d", output[0], output[1]);
}


