#include "main.h"
void quick(int arr[],char mark[],int size) 
{
	int i, j, k;
	int count = 0; int count_swap=0;
	//�ʱ� �ǹ� ����
	int px = size/2;
	int pl = 0, pr = size - 1;

	//for (j = 0; j < ) 
	//{
		for (i = 0; i < size; i++)
		{
			mark[pl] = ' '; mark[pr] = ' ';
			if (arr[pl] >= arr[px]) { mark[pl] = '+'; }
			else { pl++; mark[pl] = '-'; }

			if (arr[pr] <= arr[px]) { mark[pr] = '+'; }
			else { pr--; mark[pr] = '-'; }

			swap(int, arr[pl], arr[pr]);
			count_swap++;
			//���
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);
		}

		count++;
		cout << "-----------------------" << endl;
	//}
	Print(arr, size);
	cout << "�񱳸� " << count << "ȸ �����߽��ϴ�." << endl;
	cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}	

