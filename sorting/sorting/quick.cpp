#include "main.h"
//재귀함수
void quick(int arr[], char mark[], int size,int *count)
{
	int i, j, k;
	//int count = 0; int count_swap=0;
	//초기 피벗 설정
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
			//출력
			for (k = 0; k < size; k++) cout << mark[k] << " ";
			cout << endl;
			Print(arr, size);
		}
		
	//	cout << "px: " << px << endl;
	*count++;
	//	cout << "-----------------------" << endl;
	Print(arr, size);
	//cout << "비교를 " << *count << "회 수행했습니다." << endl;
	//cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}	



