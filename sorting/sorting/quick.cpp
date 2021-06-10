#include "main.h"
//재귀함수
void quick(int arr[], char mark[], int size,int px ,int pl,int pr)
{
	int i, j, k;
	int count = 0; int count_swap=0;
	//int pl = 0; int pr = size-1;
	//px = (right - left) / 2
	cout << "px: "<< px <<" , arr[px] : " << arr[px] << endl;

	for (j = 0; j < size - 1; j++) 
	{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
		if (arr[pl] < arr[px]) pl++; 
		if (arr[pr] > arr[px]) pr--; 
		swap(int, arr[pl], arr[pr]);	
		Print(arr, size);
	}
	pl--; pr++;
	cout << "px: " << px << " , arr[px] : " << arr[px] << endl;
	Print(arr, size);
	if (pl < px)
	{
		int right = pl;
		int left = 0;
		cout << "왼쪽" << endl;
		//for (i = 0; i < pl+1; i++) { cout << "arr[" << i << "] = " << arr[i] << " "; }
		//cout << endl;
		px = (right - left) / 2;
		int s = right - left +1;
		//cout << "pl: " << pl << " , pr: " << pr << " , px: " << px<<" , size: "<<size<<endl;
		for (j = 0; j < size - 1; j++) 
		{
			if (arr[left] < arr[px]) left++;
			if (arr[right] > arr[px]) right--;
			swap(int, arr[left], arr[right]);
		}
		Print(arr, s);
	}
	if (pr > px)
	{
		int right = size-1;
		int left = pr-1;
		for (i = pr-1; i < size; i++) { cout << "arr[" << i << "] = " << arr[i] << " "; }
		cout << endl;
		cout << "오른쪽" << endl;
		px = (right - left) / 2;
		int s = right - left + 1;

		for (j = 0; j < size - 1; j++)
		{
			if (arr[left] < arr[px]) left++;
			if (arr[right] > arr[px]) right--;
			swap(int, arr[left], arr[right]);
		}
		//Print(arr, s);
	}
	/*
		//cout<<"pl: " << pl<<endl;
		//quick(arr, mark, px - pl, ((px - pl) / 2),0,pl); 
		size = px - pl;
		px = ((px - pl) / 2);
		pl = 0;
		pr = pl;
		//cout << "px: " << px << " , arr[px] : " << arr[px] << endl;
		for (j = 0; j < size - 1; j++)
		{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
			if (arr[pl] < arr[px]) pl++;
			if (arr[pr] > arr[px]) pr--;
			swap(int, arr[pl], arr[pr]);
		}
		pl--; pr++;
		Print(arr, size);
	//*/
	
	//else if (pr > px)
	//{
	//	cout<<"pr: " << pr << endl;
		//quick(arr, mark, pr - px, px + ((pr - px) / 2),pr,size-1);
	/*
		size = pr - px;
		px = px + ((pr - px) / 2);
		pl = pr;
		pr = size - 1;
	//	cout << "px: " << px << " , arr[px] : " << arr[px] << endl;

		for (j = 0; j < size - 1; j++)
		{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
			if (arr[pl] < arr[px]) pl++;
			if (arr[pr] > arr[px]) pr--;
			swap(int, arr[pl], arr[pr]);
		}
		pl--; pr++;
		//Print(arr, size);*/
//	}
	

	
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
		
		cout << endl;
	cout << "-----------------------" << endl;
	Print(arr, size);
	cout << "-----------------------" << endl;
	//cout << "비교를 " << count << "회 수행했습니다." << endl;
	//cout << "교환을 " << count_swap << "회 수행했습니다." << endl;

}	



