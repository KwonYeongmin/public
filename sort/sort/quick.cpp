#include "main.h"
//����Լ�

// { 10, 4, 5, 2, 3, 8, 9, 20, 14, 17, 1, 7 };
// 7 4 5 2 3 8 1 9 14 17 20 10
// 1 2 5 4 3 8 7
// 1
void q_sort(int arr[],int left,int right) 
{
	int i = 0;
	int s = right - left + 1;
	int px = arr[s / 2];
	while (i < s / 2)
	{
		while (arr[left] < px) left++;
		while (arr[right] > px) right--;
		swap(int, arr[left], arr[right]);
		i++;
	}
}

void quick(int arr[], char mark[], int size, int left, int right)
{
	int px = arr[size / 2];
	

	q_sort(arr,left,right);
	Print(arr, size);
	cout << "left : " << left << " , right : " << right << endl;
	q_sort(arr, 0, left-1);
	q_sort(arr, left, size-1);
	Print(arr, size);
	//cout << "arr[" << l << "] :" << arr[l] << " , arr[ px] : " << px << " , arr[" << r << "] : " << arr[r] << endl;

	/*
	left = 0;
	right = l - 1;

	s = right - left + 1;
	px = s / 2;
	*/
	/*
	if (size > 1)
	{
		//�����϶�
		quick(arr, mark, s, 0, l-1);
		//�������϶� 
		quick(arr, mark, s, r, s-1);
	}*/
	Print(arr, size);
	/*
	/*
	if (s > 1)
	{
		//����
		cout << "r: " << r << " , l: " << l << endl;
		if (l > left)
		{
			int l_ = 0; int r_ = l - 1;
			cout << arr[l_] << " ~ " << arr[r_] << endl;
			int s_ = r_ - l_ + 1;
			px = arr[s_ / 2];
			cout << px << endl;
			quick(arr, mark, s_, l_, r_);
		}
		Print(arr, size);
		//������
		r = 7; l = 7;
		cout << "r: " << r << " , l: " << l << endl;
		if (r < right)
		{
			int l_ = r; int r_ = s - 1;
			int s_ = r_ - l_ + 1;
			px = arr[s_ / 2];
			quick(arr, mark, s_, l_, r_);
		}
		Print(arr, size);
		cout << "--------------------------" << endl;
		Print(arr, size);
	}*/

}




	/*
	int r = left - 1;
	int l = 0;
	s = r- l + 1;
	px= arr[size / 2];
	while (1)
	{
		while (arr[l] < px) l++;
		while (arr[r] > px) r--;
		swap(int, arr[l], arr[r]);
		i++;
		if (i > s / 2) break;
	}
	cout << "--------------------------" << endl;
	Print(arr, size);

	r = size - 1;
	l = right;
	s = r - l + 1;
	px = arr[size / 2];
	while (1)
	{
		while (arr[l] < px) l++;
		while (arr[r] > px) r--;
		swap(int, arr[l], arr[r]);
		i++;
		if (i > s / 2) break;
	}
	cout << "--------------------------" << endl;
	Print(arr, size);

	int r_ = left - 1;
	int l_ = 0;
	s = r - l + 1;
	px = arr[size / 2];
	while (1)
	{
		while (arr[l] < px) l++;
		while (arr[r] > px) r--;
		swap(int, arr[l], arr[r]);
		i++;
		if (i > s / 2) break;
	}
	cout << "--------------------------" << endl;
	Print(arr, size);

	r_ = size - 1;
	l_ = right;
	s = r - l + 1;
	px = arr[size / 2];
	while (1)
	{
		while (arr[l] < px) l++;
		while (arr[r] > px) r--;
		swap(int, arr[l], arr[r]);
		i++;
		if (i > s / 2) break;
	}
	cout << "--------------------------" << endl;
	Print(arr, size);

	*/



/*
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


		/*
			cout << endl;
			cout << "-----------------------" << endl;
			Print(arr, size);
			cout << "-----------------------" << endl;

		}*/


