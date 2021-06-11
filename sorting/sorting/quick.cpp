#include "main.h"
//Àç±ÍÇÔ¼ö
void quick(int arr[], char mark[], int size, int px, int pl, int pr)
{
	int i, j, k;
	int count = 0; int count_swap = 0;
	int left = pl, right = pr;
	int x = (pl + pr) / 2;
	//cout << right - left << endl;
	for (j = 0; j < right - left; j++)
	{
		cout << j << endl;

		if (arr[left] < arr[x]) { left++; }
		if (arr[right] > arr[x]) {right--;}
		swap(int, arr[left], arr[right]);
		Print(arr, size);
	}
	//cout << "px: " << px << " ,right: " << right << " , left: " << left << endl;

	
	//cout << "px: " << px << " ,right: " << right << " , left: " << left << endl;
	//Print(arr, size);
	//cout << "px" << px << endl;
	/*
	left = px - 1;
	right = px + 1;
	
	if (size > 1) 
	{
		if (right > px)
		{
			int r = size - 1;
			int l = right - 1;
			x = (r + l) / 2;
			int s = r - l + 1;
			//cout << "r: " << r << " , l: " << l << " , x: " << x << " , s: " << s << endl;
			//cout << "arr[r]: " << arr[r] << " , arr[l]: " << arr[l] << " , arr[x]: " << arr[x] << " , s: " << s << endl;
			//quick(arr, mark, s, (r + l) / 2, l, r);
			/*
			cout << endl;
			for (j = 0; j < s - 1; j++)
			{
				if (arr[left] < arr[x]) left++;
				if (arr[right] > arr[x]) right--;
				swap(int, arr[left], arr[right]);
			}
			*/
		//}
		
		
	//	left = px - 1;
		//right = px + 1;
		/*
		if (left < px)
		{
			
			int r = left;
			int l = 0;
			x = (r + l) / 2;
			int s = r - l + 1;
			quick(arr, mark, s, (r + l) / 2, l, r);
			//cout << "left < px = " << left << " < " << px << endl;
			/*
			for (j = 0; j < s - 1; j++)
			{
				if (arr[left] < arr[x]) left++;
				if (arr[right] > arr[x]) right--;
				swap(int, arr[left], arr[right]);
			}
		}  */
	
	//}
	


	cout << endl;
	cout << "-----------------------" << endl;
	Print(arr, size);
	cout << "-----------------------" << endl;

}


