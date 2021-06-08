#include <iostream>
#include"StopWatch.h"
using namespace std;
//int *solution(int *relation, int n);
void case1();
void case2();

int main() 
{
	/*
	int number,i,j;
	cout << "이용자 수(2명~100명이하)를 입력: ";
	cin >> number;
	int **data = new int*[number*(number-1)/2];
	for (i = 0; i < number*(number - 1) / 2;i++) data[i] = new int[2];
	for (i = 0; i < number*(number - 1) / 2; i++) { for (j = 0; j < 2; j++) { data[i][j] = -1; } }
	//유저의 인덱스에 대한 친구의 수를 담은 배열
	int *f_num = new int[number];
	//친구관계에 따른 유저의 배열
	//int **arr = new int*[number];
	//for (i = 0; i < number; i++) arr[i] = new int[2];
	int *temp = new int[number];
	int m,fr;
	int ck = 0;
	int index[2];
	int k=0;
	for (i = 0; i < number*(number - 1) / 2; i+=2) 
	{
		data[i][0] = i;
		data[i+1][0] = i;
	}
	for (i = 0; i < number; i++) 
	{
		cout << "유저" <<i<<"의 직접 연결된 친구 수 입력: "; //1이거나 2이거나
		cin >> m;
		f_num[i] = m;
		//친구 한명이면 양끝에 배치
		if (m == 1) 
		{
			if (ck == 0) { temp[0] = i; ck = 1; }
			else { temp[number - 1] = i; }
		}
		
		for (j = 0; j < m; j++) 
		{
			cout << "친구" << i << "입력: ";
			cin >> fr;
			data[k][1] = fr;
			if (m == 1) k += 2;
			else  k++;
		}

	}
	//배열확인
	for (i = 0; i < number*(number-1)/2; i++) 
	{
		cout << "(";
		for (j = 0; j < 2; j++) 
		{
			cout << data[i][j] ;
			cout << ",";
		}
		cout << ")"<<endl;
	}


	
	/*
	
	//친구 관계 체크
	for (int h = 0; h < number-2 ; h++) 
	{
		for (i = 0; i < number; i++)
		{
			for (j = 0; j < 2; j++){
				if(h<number/2-1)
				{
					{
						if (arr[h][0] == data[i][j])
						{
							arr[h + 1][0] = i;
							if (data[arr[h][0]][j] == arr[h + 1][0]) data[arr[h][0]][j] = -1;		//h= 0,1, // arr index 1,2,
							cout << "arr[" << h + 1 << "][0]:" << arr[h + 1][0] << endl;
						}
					}
					
				}
				else //4,5
				{
			
					if (arr[number - (h - 1)][0] == data[i][j]) //h=2,3 arr index 3,4 //3, 4 2,3
					{
						arr[number - (h)][0] = i;
						if (data[arr[number - (h)][0]][j] == arr[h + 1][0]) data[arr[number - (h)][0]][j] = -1;
						cout << "arr[" << number - (h) << "][0] :" << arr[number - (h)][0]<< endl;
					}
				}
			}
		}
	}*/
	
	/*
	for (i = 0; i < number; i++) cout << "유저 배열 : " << arr[i] << " ";
	
	for (i = 0; i < number; i++) 
	{
		if ((i == 0) || (i == number - 1)) arr[i][1] = 2;
		else if ((i == 1) || (i == number - 2)) arr[i][1] = 3;
		else arr[i][1] = 4;
	}

	for (i = 0; i < number; i++) 
	{
		cout << "유저" << i << "의 친구 수 : " << arr[i][1] << endl;
	}
	*/
case1();
//case2();
return 0;

/*
	delete[] temp;
	delete[] data; */

	return 0;
}
void case2() 
{
	int i, j;
	int size = 7;
	int arr[7] = {};
	char mark[7];
	for (i = 0; i < size; i++) mark[i] = ' ';

}

void case1()
{
	int i, j = 0;
	int arr[7] = { 6,4,8,3,1,9,7 };
	char mark[7];
	int size = 7;
	for (i = 0; i < size; i++) mark[i] = ' ';
	int min, temp;
	int cnt1 = 0;
	//case 1
	for (j = 0; j < size; j++)
	{
		min = arr[j];
		for (i = j; i < size; i++)
		{
			if (min > arr[i])
			{
				min = arr[i];
			}
		}
		for (i = j; i < size; i++)
		{
			if (arr[i] == min)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				cnt1++;
			}
		}
		for (int m = j; m < size; m++) mark[m] = '-';

		for (int k = 0; k < size; k++) cout << mark[k] << " ";

		for (int m = 0; m < size; m++) mark[m] = ' ';

		cout << endl;
		for (int k = 0; k < size; k++)
		{
			cout << arr[k] << " ";
		}
		cout << endl;
	}

	cout << "case1의 횟수: " << cnt1 << endl;

}

/*
int *solution(int *relation,int n) 
{
	int *rel_data = new int[n];
	//relationship 이용자 i와의 관계 //1,0
	//rel_data 이용자들의 친구 수
	int i,j = 0;
	for (i = 0; i < n; i++) 
	{
		relation[i] = j;
		j += 2;
	}


	return rel_data;
}*/