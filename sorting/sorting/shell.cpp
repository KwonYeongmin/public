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
	cout << "�񱳸� " << count << "ȸ �����߽��ϴ�." << endl;
	cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}