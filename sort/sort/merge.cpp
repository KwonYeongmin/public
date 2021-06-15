#include "main.h"

void merge_0(int a[], int b[], int na, int nb, char mark[])
{
	int pc = 0, pb = 0, pa = 0;
	int size = na + nb;
	int *c = new int[size];

	while (pc < size)
	{
		if (a[pa] > b[pb])
		{
			c[pc] = b[pb]; pb++;
		}
		else if (a[pa] < b[pb])
		{
			c[pc] = a[pa]; pa++;
		}
		else
		{
			c[pc] = a[pa]; pc++;
			c[pc] = a[pb]; pa++; pb++;
		}

		if (pa > na)
		{
			for (int h = pc; h < size; h++)
			{
				for (int m = pb; m < nb; m++) c[h] = b[m];
				break;
			}
		}
		else if (pb > nb)
		{
			for (int h = pc; h < size; h++)
			{
				for (int m = pa; m < na; m++) c[h] = a[m];
				break;
			}
		}
		pc++;
	}

	Print(c, size);
}


//int arr_[10] = { 1,18,5,20,9,10,17,14,8,2 };
void merge_1(int arr[], char mark[], int size, int left, int right)
{

	/*
	int na, nb;
	int i, j, k;
	//분리하기
	for (int nu = 0; nu < size - 1; nu++)
	{
		if (arr[nu] > arr[nu + 1]) { na = nu; }
	}
	na++;
	nb = size - na;
	cout << "nb: " << nb << endl;
	cout << "na: " << na << endl;
	int nc = size;

	int *a = new int[na];
	for (int nu = 0; nu < na; nu++)
	{
		a[nu] = arr[nu];
	}

	int *b = new int[nb];
	for (int nu = na; nu < size; nu++)
	{
		b[nu] = arr[nu];
	}

	int *c = new int[size];
	Print(a, na);
	Print(b, nb);
	/*
	int pc = 0, pb = 0, pa = 0;


	while (pc < size)
	{
		if (a[pa] > b[pb])
		{
			c[pc] = b[pb]; pb++;
		}
		else if (a[pa] < b[pb])
		{
			c[pc] = a[pa]; pa++;
		}
		else
		{
			c[pc] = a[pa]; pc++;
			c[pc] = a[pb]; pa++; pb++;
		}

		if (pa > na)
		{
			for (int h = pc; h < size; h++)
			{
				for (int m = pb; m < nb; m++) c[h] = b[m];
				break;
			}
		}
		else if (pb > nb)
		{
			for (int h = pc; h < size; h++)
			{
				for (int m = pa; m < na; m++) c[h] = a[m];
				break;
			}
		}
		pc++;
	}
	*/

	int i, j, k;
	int x = (right + left) / 2;

	for (i = 0; i < x; i++)
	{

	}

	Print(arr, size);
}