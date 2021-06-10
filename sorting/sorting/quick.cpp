#include "main.h"
//Àç±ÍÇÔ¼ö
void quick(int arr[], char mark[], int size,int px ,int pl,int pr)
{
	int i, j, k;
	int count = 0; int count_swap=0;
	int left=pl, right=pr, x=px;

	for (j = 0; j < size - 1; j++) 
	{
		if (arr[left] < arr[x]) left ++;
		if (arr[right] > arr[x]) right--;
		swap(int, arr[left], arr[right]);
	}
	left--; right++;
	//cout << "px: " << x << " , arr[px] : " << arr[x] << endl;
	//Print(arr, size);


	if (left < px)
	{	
		int r = left;
		int l = 0;
		x = (r - l) / 2;
		int s = r- l;
		for (j = 0; j < s- 1; j++) 
		{
			if (arr[l] < arr[x]) l++;
			if (arr[r] > arr[x]) r--;
			swap(int, arr[l], arr[r]);
		}
	}
	if (right > px)
	{
		int r = size-1;
		int l = right-1;
		x = l+ (r - l) / 2;
		int s = r - l + 1;
		for (j = 0; j < s-1; j++)
		{
			if (arr[l] < arr[x]) l++;
			if (arr[r] > arr[x]) r--;
			swap(int, arr[l], arr[r]);
		}
		cout << endl;
	}

		
	cout << endl;
	cout << "-----------------------" << endl;
	Print(arr, size);
	cout << "-----------------------" << endl;

}	



