#include "main.h"
//����Լ�
void quick(int arr[], char mark[], int size,int px ,int pl,int pr)
{
	int i, j, k;
	int count = 0; int count_swap=0;
	int pl = 0; int pr = size-1;
	//px = (pr - pl+1) / 2;
	cout << "px: "<< px <<" , arr[px] : " << arr[px] << endl;

	for (j = 0; j < size - 1; j++) 
	{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
		if (arr[pl] < arr[px]) pl++; 
		if (arr[pr] > arr[px]) pr--; 
		swap(int, arr[pl], arr[pr]);	
	}
	pl--; pr++;
	Print(arr, size);

	if (pl < px) 
	{
		quick(arr, mark, px - pl, (px - pl) / 2); 
	}
	if (pr > px)
	{
		quick(arr, mark, pr - px, px + ((pr - px) / 2));
	}
	

	
	/*

	if (pl < px)
	{
		//px = (px - pl) / 2;
		quick(arr, mark, px - pl, (px - pl) / 2);
	}
	if (pr > px)
	{
			//px = px + ( (pr - px) / 2 );
		quick(arr, mark, pr - px, px + ((pr - px) / 2));
	}
	*/
		
	
	/*
		if (pl < px)
		{
			px = (px - pl) / 2;
			cout << "arr[px] : " << arr[px] << endl;
			quick(arr, mark, px - pl,px);
		}
		if (pr > px)
		{
			px = (pr - px) / 2;
			cout << "arr[px] : " << arr[px] << endl;
			quick(arr, mark, pr-px,px);
		}*/
	cout << "-----------------------" << endl;
	Print(arr, size);
	cout << "-----------------------" << endl;
	//cout << "�񱳸� " << count << "ȸ �����߽��ϴ�." << endl;
	//cout << "��ȯ�� " << count_swap << "ȸ �����߽��ϴ�." << endl;
}	



