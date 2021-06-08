#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//문제5
void solution();

int main()
{
	solution();

	return 0;
}

void solution()
{

	int ary[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int new_ary[3][3];
	int sum_x = 0, sum_y = 0;
	int sum[6] = {0,};
	int x=0, y=0;
	
	//ary배열을 더해서 새로운 배열의 값을 구하는 식
	
	for (y = 0; y < 3; y++)
	{
		sum[0] += ary[0][y];
		sum[1] += ary[1][y];
		sum[2] += ary[2][y];
		sum[3] += ary[y][0];
		sum[4] += ary[y][1];
		sum[5] += ary[y][2];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			new_ary[i][j] = sum[i] + sum[3+j]-ary[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
		printf("new_ary[%d][%d] : %d \t",i,j,new_ary[i][j]);
		}
		printf("\n");
	}
}




