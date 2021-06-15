#include "main.h"

//내가 한거
void insertion(int *arr, char *mark, int size)
{
	int i, j, k;
	int count = 0; int count_swap = 0;
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			for (k = 0; k < size; k++) mark[k] = ' ';
			if ((arr[j] > arr[i]))
			{
				swap(int, arr[i], arr[j]);
				count_swap++; mark[j] = '*'; mark[i] = '+';
			}
			else { mark[j] = '*'; mark[i] = '-'; }
			count++;
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);
		}
		cout << "------------------------" << endl;
	}
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;

}

//교재
void insertion_1(int *arr, char * mark, int size)
{
	int i, j, k;
	int count = 0; int count_swap = 0;
	for (i = 1; i < size; i++)
	{
		int tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
			count_swap++;
		}
		arr[j] = tmp;
		count++;
		cout << endl;
		Print(arr, size);
	}
	cout << "-----------" << endl;
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}