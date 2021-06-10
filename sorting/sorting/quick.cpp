#include "main.h"
//재귀함수
void quick(int arr[], char mark[], int size,int px ,int pl,int pr)
{
	int i, j, k;
	int count = 0; int count_swap=0;
	int left=pl, right=pr, x=px;

	//cout << "px: "<< x <<" , arr[px] : " << arr[x] << endl;

	for (j = 0; j < size - 1; j++) 
	{
			//mark[pl] = ' '; mark[pr] = ' '; mark[px] = '*';
		if (arr[left] < arr[x]) left ++;
		if (arr[right] > arr[x]) right--;
		swap(int, arr[left], arr[right]);
	}
	left--; right++;
	cout << "px: " << x << " , arr[px] : " << arr[x] << endl;
	Print(arr, size);


	if (left < px)
	{	
		int r = left;
		int l = 0;
		//quick(arr, mark, r-l, (r-l)/2, l, r);
		//cout << "왼쪽" << endl;
		//for (i = 0; i < pl+1; i++) { cout << "arr[" << i << "] = " << arr[i] << " "; }
		//cout << endl;
		x = (r - l) / 2;
		int s = r- l;
		//cout << "pl: " << pl << " , pr: " << pr << " , px: " << px<<" , size: "<<size<<endl;
		for (j = 0; j < s- 1; j++) 
		{
			if (arr[l] < arr[x]) l++;
			if (arr[r] > arr[x]) r--;
			swap(int, arr[l], arr[r]);
		}
		//Print(arr, s);
	}
	if (right > px)
	{
		int r = size-1;
		int l = right-1;
		//quick(arr, mark, r - l+1, l + (r - l) / 2, l, r);
		
		//cout << "오른쪽" << endl;
		x = l+ (r - l) / 2;
		int s = r - l + 1;
		for (j = 0; j < s-1; j++)
		{
			if (arr[l] < arr[x]) l++;
			if (arr[r] > arr[x]) r--;
			swap(int, arr[l], arr[r]);
			/*
			for (i = l; i < r + 1; i++) cout << arr[i] << " ";
			cout << endl;*/
		}
		cout << endl;
	}

		
	cout << endl;
	cout << "-----------------------" << endl;
	Print(arr, size);
	cout << "-----------------------" << endl;
	//cout << "비교를 " << count << "회 수행했습니다." << endl;
	//cout << "교환을 " << count_swap << "회 수행했습니다." << endl;

}	



