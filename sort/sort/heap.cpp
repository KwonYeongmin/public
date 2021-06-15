#include"main.h"


void h_sort(int arr[], int size)
{
	int max = 0;
	int i;
	for (i = 1; i < size; i++) if (arr[i] > arr[max]) max = i;

	swap(int, arr[max], arr[size - 1]);
}

int heap(int arr[], char mark[], int size)
{
	int cnt = 1;
	int cur = 0;
	int s = size;

	while (1)
	{
		h_sort(arr, s);
		s--;

		for (int k = 0; k < pow(2, cnt - 1); k++)
		{
			if (cur > size - 1) break;
			int left = 2 * cur + 1;
			int right = 2 * cur + 2;

			if (left < s) { if (arr[left] > arr[cur]) swap(int, arr[left], arr[cur]); }
			if (right < s) { if (arr[right] > arr[cur]) swap(int, arr[right], arr[cur]); }

		}
		cur++;
		cnt++;

		if (cur > size - 1) break;
	}

	Print(arr, size);
	return 1;
}
