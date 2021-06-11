#include"main.h"


void h_sort(int arr[], int size)
{
	int max=0;
	int i;
	for (i = 1; i < size; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i; 
		}
	}
	swap(int, arr[max], arr[size - 1]);
}

int heap(int arr[], char mark[], int size)
{
	
	int cnt = 1;
	int cur=0;
	int s = size;
	
	while (1)
	{
		h_sort(arr, s);
		s--;

		for (int k = 0; k < pow(2, cnt - 1); k++)
		{
			if (cur > size - 1) break;
			int left = 2 * cur +1;
			int right = 2 * cur +2;

			if (left < s) { if (arr[left] > arr[cur]) swap(int, arr[left], arr[cur]); }
			if (right < s) { if (arr[right] > arr[cur]) swap(int, arr[right], arr[cur]); }	
			
		}cur++;

		cnt++;

		if (cur > size-1) break;
	}
	
	Print(arr, size);
	return 1;
}
	//cout << cnt << "," << cur << endl;
	//cnt = 1; cur = 0;
	//cout << cnt;
	/*
	while (1)
	{
		cout << " //" << cnt << " //" << endl;

		for (int k = 0; k < pow(2, cnt - 1); k++)
		{
			if (cur > size - 1) break;
			int left = 2 * cur + 1;
			int right = 2 * cur + 2;
			
			if (arr[left] > arr[cur]) swap(int, arr[left], arr[cur]);
			if (arr[right] > arr[cur]) swap(int, arr[right], arr[cur]);
			if (arr[right] > arr[left]) swap(int, arr[right], arr[left]);
			
			//출력
			cout << "cur: " << arr[cur] << endl;
			if (left < size) { cout << "left: " << arr[left] << endl; }
			if (right < size) { cout << "right: " << arr[right] << endl; }
			cout << endl;

			cur++;
		}
		cnt++;
		if (cur > size - 1) break;
	}*/





	/*
	int cur = 0;

	
	for (cur = 0; cur < size; cur++)
	{
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		cout <<"cur: "<< arr[cur] << endl;
		cout << "left: "<<arr[left] << endl;
		cout << "right: " << arr[right] << endl;
		cout << endl;
	}
	

	/*
	for (int i = 0; i < size; i++)
	{
		cout << " // " << i << " //" << endl;
		for (int j = 0; j < i * 2 + 1; j++)
		{
			cout << arr[i + j] << endl;
			cout << arr[i * 2 + 1] << endl;
			cout << arr[i * 2 + 2] << endl;
			cout << endl;
		}
		cout << endl;*/
		//for (int j=i;j<pow(2,i);j++)
		//{
			//cout << j;

			//int p = arr[i]; int c1 = arr[i + 2], c2 = arr[i + 3];
			//if (j == 1)
			//{
			//{
			//	int c1 = arr[j + 1]; int c2 = arr[j + 2];
			//}
			//cout << "부모: " << p << " ,자식: " << c1 << " , " << c2 << endl;
		//}
		//cout << endl;

	//}
	/*
	int i = 0;
	int j = 0;
	int cnt = 1;
	int max = 0;
	int k;*/
	/*
	for (k = 0; k < size - 1; k++)
	{
		if (arr[k] > arr[max]) { max = k; break; }
	}

	while (1)
	{
		cout << arr[i] << " , " << arr[i * 2 + 1] << " , " << arr[i * 2 + 2];
		cout << endl;
		i++;
		if (i > size - 1) break;
	}*/



/*
void TopDown(int * arr, int size, bool(*compare)(const int &, const int &), int start)
{
	int cur = start;

	while (cur < size)
	{
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		int target = cur;

		if (left < size && compare(arr[left], arr[cur]))
			target = left;

		if (right < size && compare(arr[right], arr[target]))
			target = right;

		if (target != cur)
		{
			swap(int,arr[cur], arr[target]);
			cur = target;
		}
		else break;
	}
}

void HeapSort(int * arr, int size, bool(*compare)(const int &, const int &), bool showProcess)
{
	for (int i = size - 1; i >= 0; --i)
		TopDown(arr, size, compare, i);

	int tmpSize = size;

	for (int i = 0; i < size; ++i)
	{
		swap(int,arr[0], arr[tmpSize - 1]);
		TopDown(arr, --tmpSize, compare, 0);
	}

	if (showProcess) Print(arr, size);
}*/


/*
10,9,5,8,3,2,4,6,7,1
*//*

	/*
	while (1)
	{
		cout << " // " << cnt << " //" << endl;

		for (int k=0;k<pow(2,cnt-1);k++)
		{
			if (i > size-1) break;
			j = i* 2;
			cout << arr[i] << endl;
			if (j + 1 < size) { cout << arr[j + 1] << endl; }
			if (j + 2 < size) { cout << arr[j + 2] << endl;}
			i++;
		}
		cnt++;
		if (i > size - 1) break;
	}*/

		/*
		//1//
		arr[0] arr[1]arr[2]

		//2//
		arr[1] arr[3]arr[4]
		arr[2] arr[5] arr[6]

		//3//
		arr[4] arr[7] arr[8]
		arr[5] arr[9]
		arr[6]
		arr[7]
		
		//4//
		arr[8]
		arr[9]
		
		*/
	



/*
while (1)
{
	cout << " //" << cnt << " //" << endl;

	for (int k=0;k<pow(2,cnt-1);k++)
	{
		if (i > size-1) break;
		j = i* 2;
		cout << arr[i] << endl;
		if (j + 1 < size) { cout << arr[j + 1] << endl; }
		if (j + 2 < size) { cout << arr[j + 2] << endl;}
		i++;
	}
	cnt++;
	if (i > size - 1) break;
}*/