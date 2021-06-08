#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void prime_num();
void n_to_ten();
void prime_num_v2();
void swap_(char str[80], int cnt);
int isLeapYear(int year);
void scanning();

int main() 
{

	scanning();
	return 0;
	int year;
	scanf("%d", &year);
	printf(isLeapYear(year));

	return 0;
	
	n_to_ten();
	//prime_num();
	//prime_num_v2();
	return 0;
}

void scanning() 
{
	int index_x[7] ;
	for (int i = 0; i < 7;i++) 
	{
		index_x[i] = i;
	} 
	for (int i = 0; i < 7; i++)
	{
		printf("%d", index_x[i]);
	}
		/*
	int ary[6][7];
	for (int i = 0; i < 7;i++) 
	{
		if (i%2!=0) 
		{
			for (int k = 0; k < 7; k++) 
			{
			if(k==1) ary[i][k] = 6;
			}
			
			ary[i][1] = 4;
			ary[i][2] = 3;
			ary[i][3] = 2;
			ary[i][4] = 1;
			ary[i][5] = 9;
			ary[i][6] = 8;
		}
		else 
		{
			for (int k=0;k<7;k++) 
			{
				ary[i][k] = NULL;
			}

	
		}
	}

	for (int m=0;m<6;m++) 
	{
		
		for (int n = 0; n < 7; n++) 
		{
			if (n == 0) printf(" %d |", ary[m][n]);
			else printf(" %d ", ary[m][n]);
			
		}
		if (m == 0) { printf("--------------------------------------------"); }
		printf("\n");
	}*/
}


/*
4로 나누어져야함
100의 배수X
그 중에서 400 배수 포함
*/
//윤년 계산식
int isLeapYear(int year) 
{
	if (year % 4 == 0) 
	{
		if ((year % 100 != 0) || (year % 400 == 0)) { return 1; }
	}
}

/*그냥 짠거*/
void prime_num() 
{
	int i, j;
	int num;
	int ck = 0;
	printf("숫자 입력 : ");
	scanf("%d", &num);
	for (i = 2; i < num; i++) 
	{
		for (j = 2; j < num; j++) 
		{
			  if (i%j == 0) { break; } 
		}
		ck++;
		if (i==j) printf("%d \n", i);
	}
	printf("ck:%d",ck);
}

/*속도 줄이기*/
void prime_num_v2()
{
	int i, j;
	int num;
	printf("숫자 입력 : ");
	scanf("%d", &num);
	int cnt = 1;
	int prime_numbers[80];
	prime_numbers[0] = 3;
	int ck=0;
	for (i = 2; i < num; i++)
	{
		if (i % 2 != 0) //짝수 제외
		{
			
			for (int k = 0; k < cnt; k++) // 이 전에 분류되었던 소수로 나누어지지 않는다면
			{
				if (i % prime_numbers[k] == 0) break; //ck++; 
			}
			for (j = 2; j < num; j++) if ((i%j == 0)) break;
			cnt++;
			prime_numbers[cnt] = i;		
		}
	}
	//printf("%d \n", ck);
	for (int i = 0; i < cnt; i++) { printf("%d \n", prime_numbers[i]); }
}

//뒤집어 주기
void swap_(char str[80], int cnt)
{
	char temp;
	int count;
	if (cnt % 2 == 0) { count = cnt / 2; }
	else { count = (cnt-1) / 2; }

	for (int i=0;i<count;i++) 
	{
		temp = str[i];
		str[i] = str[cnt - 1 - i];
		str[cnt - 1 - i] = temp;
	}
}

void n_to_ten()
{
	int systemNum = 16;
	char num[80] = "1FF";
	int cnt = 0;
	while (num[cnt] != 0)
	{
		cnt++;
	}

	for (int k = cnt; k > 0; k--) { printf("q"); }
	/*

	while(num[i]!=0)
	{
		//num[i]*
		if ((num[i] >= 65) && (num[i] <= 90)) number = num[i] - 55;
		else 
		{
			printf("%d, %d\n", num[i] - 48, cnt - i); 
			number = (num[i] - 48)*pow(16, cnt/2 - i);
			printf("%lf \n", pow(16, cnt - i));
		}
		number += number;
		
		i++;
	}

	*/
	//printf("%d", number);
	//printf("%d", cnt);
	//while (1) {}
	//A : 65 ,b66c67d68e69f70: Z : 90
}
