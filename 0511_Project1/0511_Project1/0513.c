#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int numeralSystem(int num, int systemNum);
int swap(int cnt, int number[]);
char alpabet_swap(int number);

int numeralSystem(int num, int systemNum);
/*
int main() 
{

	int num1, num2;
	printf("� ��?(10����)");
	scanf("%d",&num1);
	printf("�� ����?(36����)");
	scanf("%d", &num2);
	//printf("10���� %d�� %d���� ", num1, num2);
	numeralSystem(num1, num2);
	alpabet_swap(num1);
	return 0;
}*/

//���� ��ȯ ���α׷�
//2~36���� ��ȯ
/*
10���� �Է� : 59
������� �Է� : 8
10���� 59�� 8���� 37�Դϴ�.

*/
int numeralSystem(int num, int systemNum)
{
	

	int i = 0;
	int number[120];
	char str_number[120];

	while(1)
	{
		number[i] = num % systemNum; 
		if ((num / systemNum) < 1)  break;
		num = num / systemNum; 
		i++;
	}	
	swap(i+1, number);
	
}

int swap(int cnt, int number[])
{
	int temp;
	int count;

	if (cnt % 2 == 0) { count = cnt / 2; }
	else {count = (cnt - 1) / 2; }

	for (int j = 0; j < count; j++)
	{
		
		temp = number[j];
		number[j] = number[cnt-1-j];
		number[cnt-j-1] = temp;
	}

	for (int k=0;k<cnt;k++) 
	{
		if(number[k]<10) printf("%d", number[k]);
		else printf("%c",alpabet_swap(number[k]));
	}
	printf(" �Դϴ�.");
	
	}

char alpabet_swap(int number) 
{
	 char askii;

	 if (number >= 10)
	 {
		 askii = number + 55;	 
	 }
	 return askii;
}