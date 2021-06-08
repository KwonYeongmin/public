#include "main.h"

/*
arr[0],arr[4] / arr[1],arr[5] / arr[2],arr[6] /arr[3],arr[7]
arr[0],arr[2],arr[4],arr[6] /  arr[1],arr[5],arr[3],arr[7]
arr[0],arr[1],arr[2],arr[3],arr[4], ,arr[5],arr[6],arr[7]
*/

void shell(int arr[], char mark[], int size) 
{
	int i, j, k,m;
	int count = 0; int count_swap = 0;

	for (m = size / 2; m >= 1; m /= 2) // 4 ,2 ,1
	{
		cout << m << "-정렬" << endl;
		for (i = 1; i < m; i++)  
		{
			for (j = 0; j < i; j++)
				{				
					if (arr[j+m] < arr[j])
					{
						cout <<  "j: " << j << ", j+m: "<<j+m << " i: " << i << endl;
						swap(int, arr[j+m], arr[j]);
					}
				}
			
			
			
		}
		Print(arr, size);
	}
//	for (i = 0; i < 5; i++) for (j = 0; j <= i; j++) { cout << "ck"; }cout << endl;

	//m=4 일 때
	/*
	그룹4개
	*/
	
	
	
	//m=2 일 때
	/*
	그룹2개
	arr[] 

	for (i = 1; i < size; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					swap(int, arr[i], arr[j]); count_swap++;
				}
				count++;
				Print(arr, size);
			}
		}
	*/



	//m=1 일 때
	/*
	그룹1개

	for (i = 1; i < size; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					swap(int, arr[i], arr[j]); count_swap++;
				}
				count++;
				Print(arr, size);
			}
		}


	*/
	
	/*
	for (int m = size/2; m >= 1; m /= 2) // 4 ,2 ,1
	{
		cout << m<<endl;
		//m=4
		//if(m==4)
		for (i = 1; i < size; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] < arr[j + size/2]) 
				{
					swap(int, arr[i], arr[j]); count_swap++;
				}
				count++;
				Print(arr, size);
			}
		}
		//m=2
		for (i = 1; i < size; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					swap(int, arr[i], arr[j]); count_swap++;
				}
				count++;
				Print(arr, size);
			}
		}

		//m=1
		
	}*/
	Print(arr, size);
	cout << "비교를 " << count << "회 수행했습니다." << endl;
	cout << "교환을 " << count_swap << "회 수행했습니다." << endl;
}