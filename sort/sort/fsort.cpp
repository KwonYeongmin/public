#include "main.h"
//도수 분표 
void fsort(int arr[], char mark[],int size) 
{
	int i,j;
	int n=arr[0];
	for(i = 1; i < size; i++) if (n < arr[i]) n = arr[i];

	int *a = new int[n + 1];
	for (i = 0; i < n + 1; i++) a[i] = 0;
	for (i = 0; i < size; i++) a[arr[i]]++;

	//Print(a, n+1);
	
	int cnt = 0;
	for (i = 0; i < n + 1; i++) 
	{	
		if (a[i] > 0) 
		{
			
			for (j = 0; j < a[i]; j++ )
			{
				arr[cnt +j] = i;
				cout << "arr[" << cnt + j << "] : " << arr[cnt + j] << endl;	
				if (a[i] == 1)cnt++;
			}
			cnt++;
			//
			//Print(arr, size);
		}
	}
	Print(arr, size);
	delete[] a;
}