#include "main.h"
//����Լ�
void quick(int arr[], char mark[], int size,int *count)
{
	int i, j, k;
	//int count = 0; int count_swap=0;
	//�ʱ� �ǹ� ����
	int px = size / 2;
	int pl = 0, pr = size - 1;

		for (i = 0; i < size; i++)
		{
			mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
			if (px < i) 
			{
				if (arr[pl] >= arr[px]) { mark[pl] = '-'; }
				else { pl++; mark[pl] = '+'; }

				if (arr[pr] <= arr[px]) { mark[pr] = '-'; }
				else { pr--; mark[pr] = '+'; }

				quick(arr, mark, i,count);
			}
			else 
			{
				if (arr[pl] >= arr[px]) { mark[pl] = '-'; }
				else { pl++; mark[pl] = '+'; }

				if (arr[pr] <= arr[px]) { mark[pr] = '-'; }
				else { pr--; mark[pr] = '+'; }

				quick(arr, mark, i, count);
			}
			

			swap(int, arr[pl], arr[pr]);
			//count_swap++;
			//���
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);
		}
		
	//	cout << "px: " << px << endl;
	*count++;
	//	cout << "-----------------------" << endl;
	Print(arr, size);
	//cout << "�񱳸� " << *count << "ȸ �����߽��ϴ�." << endl;
	//cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}	



