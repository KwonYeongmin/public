#include "main.h"

//���� �Ѱ�
void selection_0(int *arr, char *mark, int size)
{
	int i, j, k;
	int min;
	int count = 0; 	int count_swap = 0;

	//case 1
	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size; k++) cout << mark[k] << " "; cout << endl;
		Print(arr, size);
		for (k = 0; k < size; k++) mark[k] = ' ';
		min = arr[j];

		for (i = j; i < size; i++)
		{
			if (min > arr[i]) min = arr[i];
		}
		for (i = j; i < size; i++)
		{
			if ((arr[i] == min) && (arr[i] != arr[j]))
			{
				mark[j] = '*'; mark[i] = '+';
				count_swap++;
				swap(int, arr[i], arr[j]);
				break;
			}
		}
		count++;
	}
	cout << "--------------" << endl;
	Print(arr, size);
	cout << "�񱳸� " << count << "ȸ �����߽��ϴ�." << endl;
	cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}


void selection_1(int *arr, char *mark, int size)
{
	int i, j, k;
	int count = 0; int count_swap = 0;

	for (i = 1; i < size; i++)
	{
		int min = i;

		for (j = 0; j < i; j++)
		{
			for (k = 0; k < size; k++)mark[k] = ' ';
			if (arr[min] < arr[j]) {
				mark[min] = '*'; mark[j] = '+'; min = j; swap(int, arr[i], arr[j]);
				count_swap++;
			}
			else { mark[min] = '*'; mark[j] = '-'; }
			count++;
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);
		}
		cout << "--------------" << endl;
	}



	Print(arr, size);
	cout << "�񱳸� " << count << "ȸ �����߽��ϴ�." << endl;
	cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}