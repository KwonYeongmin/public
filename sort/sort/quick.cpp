#include "main.h"
//Àç±ÍÇÔ¼ö

//10,4,5,2,3,8,9,20,14,17,1,7 

	//Ã¥
void quick(int arr[], char mark[], int left, int right) 
{
	int pl = left;
	int pr = right;
	int size = right - left + 1;
	int x = arr[(left + right) / 2];
	while (pl <= pr) 
	{
		while (arr[pl] < x) pl++;
		while (arr[pr] > x) pr--;
		if (pl <= pr) 
		{
			swap(int, arr[pl], arr[pr]);
			pl++; pr--;
		}
		if (left < pr)quick(arr, mark, left, pr);
		if (pl < right)quick(arr, mark, pl, right);
	}
}

