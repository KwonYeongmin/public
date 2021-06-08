#include "main.h"
void shell(int arr[], char makr[], int size) 
{
	int i, j, k;
	int count=0; int count_swap = 0;
	for (i = size / 2; i > 0;)  // 4,2,1
	{
		for (j = 0; j < size / 2; j++) // 0,3 /1,4/2,5/3,7 // 0,2,4,6
		{
			if (arr[j] > arr[i+ j])
			{
				swap(int, arr[j], arr[i + j]);
				count_swap++;
			}
			count++;
			Print(arr, size);
		}
		i /= 2;
		cout << "---------------\n";
	}
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}