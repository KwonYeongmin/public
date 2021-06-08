#include "main.h"
//bubble_0
void bubble_0(int *arr, char *mark, int size)
{
	int i, j,k;
	int count= 0;
	int count_swap = 0;

	for (i = 0; i < size - 1; i++) 
	{
		cout << "패스 " << i + 1 << "회" << endl;
		for (j = size-1; j > i; j--) 
		{
			for (k = 0; k < size; k++) mark[k] = ' ';
			if (arr[j] < arr[j - 1]) 
			{
				swap(int, arr[j], arr[j - 1]);
				count_swap++;
				mark[j] = '*'; mark[j-1] = '+';
			}
			else { mark[j] = '*'; mark[j - 1] = '-'; }
			count++;
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr,size);
		}
		cout << "-----------------" << endl;
	}
	Print(arr, size);
	cout << endl;
	cout << "비교 " << count << "회 수행하였습니다." << endl;
	cout << "교환 " << count_swap << "회 수행하였습니다." << endl;
}
	
void bubble_1(int *arr, char * mark, int size) 
{
	int i, j, k;
	int count = 0; int count_swap = 0;
	for (i = 0; i < size - 1; i++) 
	{
		int ck = 0;
		cout << "패스 " << i + 1<<"회" << endl;
		for (j = size - 1; j > i; j--) 
		{
			for (k = 0; k < size; k++) mark[k] =' ';
			if (arr[j] < arr[j - 1]) 
			{
				swap(int, arr[j], arr[j - 1]);
				count_swap++;
				ck++;
				mark[j] = '*'; mark[j - 1] = '+';
			}
			else { mark[j] = '*'; mark[j-1] = '-';}
			for (k = 0; k < size; k++)cout<<mark[k]<<" ";
			cout << endl;
			count++;
			Print(arr, size);
		}
		if (ck == 0)break;
		cout << "-----------------" << endl;
	}
	cout << "-----------------" << endl;
	Print(arr, size);
	cout << endl;
	cout << "비교 " << count << "회 수행하였습니다." << endl;
	cout << "교환 " << count_swap << "회 수행하였습니다." << endl;
}
void bubble_2(int *arr, char * mark, int size)
{
	int i=0, k;
	int pass = 0;
	int count = 0, count_swap = 0;
	while (i < size - 1) 
	{
		cout << "패스 " << pass+1<< "회" << endl;
		int last=size-1;
		int j;
		for (j = size - 1; j > i; j--) 
			{
				for (k = 0; k < size; k++) mark[k] =' ';
				if (arr[j] < arr[j - 1]) 
				{
					swap(int, arr[j], arr[j - 1]);
					last = j;
					count_swap++;
					mark[j] = '*'; mark[j-1] = '+';
				}
				else { mark[j] = '*'; mark[j - 1] = '-'; }
				for (k = 0; k < size; k++) cout << mark[k] << " ";
				count++;
				cout << endl;
				Print(arr, size);
			}
			i = last;
			pass++;
			cout << "-------------------------" << endl;
		}
	cout << "비교를 " << count<<"회 수행했습니다." << endl;
	cout << "교환을 "<<count_swap<<"회 수행했습니다." << endl;
}
//칵테일 정렬