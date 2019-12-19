#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void minimumBribes(int q_count, int* q) {
	int flag = 0;
	int number = 0;
	for(int i = 0; i < q_count; i++)
	{
		for(int j = 0; j < q_count; j++)
		{
			if(q[j] == (i + 1))
			{
				if((i - j) > 2)
				{
					flag = 1;
				}
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	if(flag)
	{
		printf("Too chaotic");
		return;
	}

	for(int i = 0; i < q_count - 1; i++)
	{
		if(q[i] > q[i + 1])
		{
			flag = q[i];
			q[i] = q[i + 1];
			q[i + 1] = flag;
			number++;
			i = -1;
		}
	}
	printf("%d", number);


}

void minimumBribesMain(void)
{
	int a[] = {2, 1, 5, 3, 4};
	int a_count = 5;
	minimumBribes(a_count,a);
}



