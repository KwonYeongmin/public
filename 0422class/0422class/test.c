#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

//0421
//과제1
//과제2 1~6 역으로 나오게
//과제3 로또
//과제4 문자열 개수 
//과제5 girl boy로 바꾸기

//순서 문자열 많은 것 부터
//p353 단어 정렬 프로그램
//cnp는 대소문자에서 문제 생긴다.
/*

int quiz1() {

	//strncpy로 하고, \0붙여주기

	char str1[80];
	char str2[80];
	char str3[80];

	char temp[80];
	char temp_[80];

	printf("세 단어의 입력 : ");
	scanf("%s %s %s", str1, str2, str3);
	int count1 = strlen(str1);
	int count2 = strlen(str2);
	int count3 = strlen(str3);


	for (int i = 0; i < count1; i++)
	{
		if (count1> count2)
		{
			swap(str1, str2);
		}
		printf("%s %s %s", str1, str2, str3);
	}
}
void swap(int *pa, int *pb)
{
	int temp = 0;
	temp = *pa;
	strcpy(pa,pb);
	*pb = temp;

}


/*
		if (count1 < count2)
		{
			strcpy(temp, str1);	 // temp <= str1
			strcpy(str1, str2);  // str1 <= str2
			if (count1 < count3)
			{
				strcpy(temp_, str1);	 // temp_ <= str1(str2)
				strcpy(str1, str3);	 // str1 <= str3
				strcpy(str2, temp_);	 // temp_ <= str1(str2)
				strcpy(str3, temp);
			}
			else
			{
				strcpy(str2, str1);
			}
		} // bbn bb n
		else if (count1 > count2) // count3> count1 > count2
		{
			if (count1 < count3) //count3> count1>
			{
				strcpy(temp, str1);
				strcpy(str1, str3);
				strcpy(temp_, str2);
				strcpy(str2, temp);
				strcpy(str3, temp_);
			}
			else // count1>count3 count1>count2
			{
				if (count2 < count3)  //count1 > count3 > count2
				{
					strcpy(temp, str2);
					strcpy(str2, str3);
					strcpy(str3, temp);
				}
			}
		}
		strcpy(temp_, str1); // temp_ <= str1
		strcpy(str1, str3);  // str1 <= str3

	}
		*/


//p402
quiz2() 
{
	
	char mark[5][5] = { 0 };
	int j, i;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j) mark[i][j] = 'X';
			else
			{
				mark[i][j] = ' ';
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%c", mark[i][j]);
		}
		printf("\n");
	}
	
	
	char mark2[5][5] = { 0 };
	int m, n;
	for (n = 0; n < 5; n++)
	{
		for (m = 0; m < 5; m++)
		{
			if ((n == m)|| (n == 4 - m)) mark2[n][m] = 'X';
			else mark2[i][j]=' ';
		}
	}
	for (n = 0; n < 5; n++)
	{
		for (m = 0; m < 5; m++)
		{
			printf("%c", mark2[n][m]);
		}
		printf("\n");
	}
	
}

//문제3
/*다음과 같은 A배열이 주어질때
	2x4 배열
a배열 1 2 3 4
	  5 6 7 8
다음과 같은 B배열과 같은 형태가 되도록 
프로그램 하고 출력하시오.
	4x2 배열
B배열 5 1 
	  6 2
	  7 3 
	  8 2
*/

quiz3() 
{
	int i, j;

	int A[2][4] = { 1,2,3,4, 5,6,7,8 };
	int B[4][2];
	
	int m = 2;
	int n = 4;
	
	for(i=0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{ 
			 B[j][i] = A[m-i-1][j]; 				
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
}

/* n x n인 2차원 배열에 숫자가 시계 방향으로 달팽이 모양으로
채워지도록 프로그램을 작성하라

1 2
4 3

1 2 3
8 9 4
7 6 5
 
1  2  3  4
12 13 14 5
11 16 15 6
10  9  8 7

*/

//문2. 과제17

//#define row 3
//#define col 3

quiz4()
{
	/*
 int num, cnt = 0, x = 0, y = -1, f = 1,n;
	int ar[50][50] = { 0, };
	scanf("%d", &num);

	n = num;
	while(n >0)
	{
		for (int i = 0; i < n; i++)
		{
			y += f;
			ar[x][y] = ++cnt;
		}
		n--;
		for (int i = 0; i < n; i++)
		{
			x += f;
			ar[x][y] = ++cnt;
		}
		f *= -1;
	}
	for(int i=0; i<num; i++)
	{
		for(int j=0;j<num;j++)
		{
			printf("%4d", ar[i][j]);
		}
		printf("\n");
	}
 */
	
	

	/*
	int a[15][15] = { 0, };
	int num = 1, x = 0, y = 0;
	int i, k, j;
	int size, sign = 1;

	printf("크기를 입력해주세요(MAX 14) : ");
	scanf("%d", &size);
	for (k = 0; k < size; ++k) {
		a[y][x] = num++;
		x += sign;
	}
	x -= 1;
	for (i = size - 1; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			y += sign;
			a[y][x] = num++;
		}
		sign *= -1;
		for (k = 0; k < i; ++k) {
			x += sign;
			a[y][x] = num++;
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			printf("%3d ", a[i][j]);
		}
		printf("\n\n");
	}

	*/
	
	return 0;

}




/*문3. 배열의 순자가 다음과 같이 채워지도록 프로그램을 
작성하시오.
배열은 n x n 크기를 갖는다. //30분~3시간
	1 2 6
	3 5 7
	4 8 9	
	*/
	quiz5()
	{
	
	}
