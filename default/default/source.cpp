#include <iostream>
#include <string>
#include <new>
#include <time.h>
#include "GeometricObject.h"

using namespace std;
void swap(int *a, int *b);
int des(int *arr, char *mark, int size, int *a, int *b);
int main() 
{
	int i,j;
	int size=7;
	int cnt=0;
	cout << "개수 입력 :";
	cin >> size;
	int a = 0; int b = 0;
	//배열 생성
	int *arr = new int[size];
	for (i = 0; i < size; i++) cin >> arr[i];
	char *mark = new char[size ];
	for (i = 0; i < size ; i++) mark[i] = ' ';
	
	//검사
	while (1) 
	{
		cnt++;
		cout << "패스" << cnt << endl;
		if ( des(arr, mark, size,&a,&b) == -1) break;
	}
	cout << "비교를 "<< b <<"회 했습니다." << endl;
	cout << "교환을 " << a << "회 했습니다." << endl;
	

	return 0;
}
void swap(int *a,int *b) 
{
	int count_s;
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
int des(int *arr, char *mark, int size, int *a, int *b)
{
	int i, j;
	int count_cmp = 0;
	int count_s = 0;
	for (i = size - 1; i > 0; i--)
	{
		cout << endl;
		if (arr[i] < arr[i - 1])
		{
			mark[i - 1] = '+';
			for (j = 0; j < size; j++) { cout << arr[j] << mark[j]; }
			swap(arr[i], arr[i - 1]);
			count_s++;
		}
		else
		{
			mark[i - 1] = '-';
			for (j = 0; j < size; j++) { cout << arr[j] << mark[j]; }
		}
		count_cmp++;

		for (j = 0; j < size; j++) mark[j] = ' ';
	}
	cout << endl << "------------------" << endl;
	for (j = 0; j < size; j++) { cout << arr[j] << mark[j]; } cout << endl;
	*a += count_s;
	*b += count_cmp;
	if (count_s == 0) return -1;
	else  return 1;

}

/*
int des(int *arr, char *mark,int size,int *a, int *b) 
{
	int i, j;
	int count_cmp = 0;
	int count_s=0;
	for (i = size - 1; i > 0; i--)
	{
		cout << endl;
		if (arr[i] < arr[i - 1])
		{
			mark[i - 1] = '+';
			for (j = 0; j < size; j++) { cout << arr[j] << mark[j]; }
			swap(arr[i], arr[i - 1]);
			count_s++;
		}
		else
		{
			mark[i - 1] = '-';
			for (j = 0; j < size; j++){cout << arr[j] << mark[j];}
		}
		count_cmp++;
		
		for (j = 0; j < size; j++) mark[j] = ' ';
	}
	cout << endl <<"------------------"<<endl;
	for (j = 0; j < size; j++) { cout << arr[j] << mark[j]; } cout << endl;
	*a += count_s;
	*b += count_cmp;
	if (count_s == 0) return -1;
	else  return 1;

}*/