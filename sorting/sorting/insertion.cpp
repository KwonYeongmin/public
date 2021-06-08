#include "main.h"

//case2
void insertion(int *arr, char *mark, int size, int *cnt, int *cnt_swap)
{
	int i, j;
	int count_swap = 0;
	int count = 0;
	int ck = 0;
	for (i = 0; i < size; i++)
	{
		
		for (j = 0; j < i+1; j++)
		{
			for (int m = 0; m < size; m++) mark[m] = ' ';
			
			if (j != size - 1)mark[j + 1] = '+'; mark[i] = '*';
			if (arr[j] > arr[i])
			{
				//swap(&arr[i], &arr[j]); count_swap++;
				
			}
			else { break; }
		}
		for (int m = 0; m < size; m++) cout << mark[m] << " "; cout << endl;
		Print(arr, size);
		count++;
	}

	*cnt_swap = count_swap;
	*cnt = count;
}

