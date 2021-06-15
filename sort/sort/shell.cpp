#include "main.h"


void shell(int arr[], char mark[], int size)
{
	int i, j, k, m;
	int count = 0; int count_swap = 0;
	int ck = 0;
	for (m = size / 2; m > 0; m /= 2) // 4 ,2 ,1
	{
		cout << m << "-정렬" << endl;
		for (i = m; i < size; i++)
		{
			for (j = 0; j <= i - m; j++)
			{
				for (k = 0; k < size; k++) mark[k] = ' ';
				if (arr[j] > arr[i])
				{
					swap(int, arr[i], arr[j]);
					mark[i] = '*'; mark[j] = '+';
					count_swap++;
				}
				else { mark[i] = '*'; mark[j] = '-'; }
				count++;
			}
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);

		}
		cout << "-----------------------" << endl;
	}
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}

void shell_1(int arr[], char mark[], int size)
{
	int i, j, k, m;
	int count = 0; int count_swap = 0;
	int ck = 0;
	for (m = size / 2; m > 0; m /= 2) // 4 ,2 ,1
	{
		cout << m << "-정렬" << endl;
		for (i = m; i < size; i++)
		{
			for (k = 0; k < size; k++) mark[k] = ' ';

			int tmp = arr[i]; mark[i] = '*';
			for (j = i - m; j >= 0 && arr[j] > tmp; j -= m)
			{
				arr[j + m] = arr[j]; ck = 1;
			}
			if (ck == 1) { mark[j + m] = '+'; ck = 0; }
			//else { mark[j + m] = '-'; }
			arr[j + m] = tmp;
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);

		}
		cout << "-----------------------" << endl;
	}
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}
