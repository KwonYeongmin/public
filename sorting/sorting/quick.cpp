#include "main.h"
//����Լ�
void quick(int arr[], char mark[], int size,int l,int r)
{
	int i, j, k;
	//int count = 0; int count_swap=0;
	//�ʱ� �ǹ� ����
	int px = size / 2;
	int pl = l, pr = r;

		for (i = 0; i < size; i++)
		{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
			
			if (arr[pl] < arr[px]) pl++;
			if (arr[pr] > arr[px]) pr--;
			swap(int, arr[pl], arr[pr]);

			if (pl < l) quick(arr, mark, i,pl,r);
			if (pr > r) quick(arr, mark, i, l, pr);
			Print(arr, size);
			/*
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
			}*/
			

			
			//count_swap++;
			//���
			//for (k = 0; k < size; k++) cout << mark[k] << " ";
			//cout << endl;
			
		}
		
	//	cout << "px: " << px << endl;
	//	cout << "-----------------------" << endl;
	Print(arr, size);
	//cout << "�񱳸� " << *count << "ȸ �����߽��ϴ�." << endl;
	//cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}	



