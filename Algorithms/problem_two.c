/*********************************************************************************
 *
 *  problem_two.c
 *  Author: Ahmed Nofal, Instructor at Sprints LLC 
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Modify the Binary Search algorithm to find an element in a circularly sorted
 * array.
 * The array is sorted in an ascending order and rotated in clockwise
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * 				 target = 10
 * Sample Output: The number is found at index 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_two.h"
#include "problem_one.h"

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/
int circularArraySearch(int arr[], int arr_size, int element_to_be_found)
{
	int shift = findRotationCount(arr, arr_size);
	int indexA = 0;
	int indexB = arr_size - 1;
	int Mid;
	int MidCheck, indexACheck;
	while(indexA != indexB)
	{
		Mid = ((indexA + indexB) / 2);
		MidCheck = Mid + shift;
		if(MidCheck > arr_size - 1)
		{
			MidCheck -= arr_size;
		}
		if(arr[MidCheck] < element_to_be_found)
		{
			indexA = Mid + 1;
		} else
		{
			indexB = Mid;
		}
	}
	indexACheck = indexA + shift;
	if(indexACheck > arr_size - 1)
	{
		indexACheck -= arr_size;
	}
	if(arr[indexACheck] == element_to_be_found)
	{
		return indexACheck;
	}
	return -1;


}

/* circularArraySearch_test */
void circularArraySearch_test(void)
{
	int A[] = {5, 6, 8, 9, 10, 1, 2};
	int target = 5;
	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);
	if(index != -1){
		printf("Element found at index %d", index);
	}
	else{
		printf("Element not found in the array");
	}

}
