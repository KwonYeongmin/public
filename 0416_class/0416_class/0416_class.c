// 0416_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
		//p177
	/*
	int k;
	int primeNum;

	printf("2이상의 정수를 입력하시오 : ");
	scanf("%d", &k);

	for (int j = 1; j < primeNum; j+=4)
	{
		for (int i = 2; i < primeNum; i++)
		{
			if ((primeNum % i) ==! 0)
			{
				//p_i = primeNum;
				//printf("%d \n", p_i);
			}
		}
	}
	*/
	
	
	
		//문제1	
	/*

	*
	**
	***
	**
	*
	  *
	 **
	***
	 **
	  *

	*/
	// i=0 j=0 j< 3 
	//int starNum = 3;
	/*
	for (int i = 0; i < starNum; i++)
	{
		//for (int j = 0; j < i; j++) { printf("*"); }
		for (int k = starNum-i; k > 0; k--) { printf("%d \n",k); } 		
	}
	*/
	
	
	/*
	int num;
	int a = 1;

	scanf("%d", &num);
	printf("\n");

	for (int i = 1; i <= ((num * 2) - 1); i++ )
	{
		if (i <= num)
		{
			//빈칸
			for (int in = (num - i); in > 0 ; in--)
			{
				printf(" ");
			}
			//별
			for (int j = 0; j < i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		else
		{
			//빈칸
			for (int in = 0; in < (i-num); in++)
			{
				printf(" ");
			}
			//별
			for (int k = (num - a); k > 0; k--)
			{
				printf("*");
			}
			printf("\n");
			a++;
		}
	}
	*/
		

	
	//문제2  p176
	//가로 세로 인덱스가 같을때
	/*
	int n =1;

	scanf("%d", &n);

	for (int i= 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (i==j)
			{
				printf("*");
			}

			else if(i==(n-j-1))
			{
				printf("*");
			}


			else
			{
				printf("o");
			}

		}
		printf("\n");
	}

	*/
		
	
/*
int n, m;

	for (m = 0; m <= 9; m++)
	{
		n = 9 - m;
		printf("n: %d  m: %d \n",n,m);
	}

	return 0;
*/




	//문제3	
//int abs_ = abs();
//printf("%d \n", abs_);

	//문제4
/*
int monthNum =1, yearNum=1;
scanf("%d", &yearNum);
monthNum = yearNum * 12;
int sum = DPE(monthNum);
printf("%d", sum);
*/

	//문제p206
//int sum = rec_func(2);
//printf("%d \n", sum);
int choiceNum;
int num1;
int num2;

choiceNum = choice();


if (choiceNum >= 1)
{
	printf("두 수를 입력하시오:  ");
	scanf("%d %d", &num1, &num2);

	switch (choiceNum)
	{
	case 1:
		printf("\n %d + %d = %d", num1, num2, Add(num1, num2));
		break;
	case 2:
		printf("\n %d - %d = %d", num1, num2, Minus(num1, num2));
		break;
	case 3:
		printf("\n %d X %d = %d", num1, num2, Multiply(num1, num2));
		break;
	case 4:
		printf("\n %d / %d = %0.2lf", num1, num2, Division((double)num1, (double)num2));
		break;
	}	
}

return 0;
}

	//문제3
/*함수 abs 구현하시오. 입력받은 값의 절대값을 구하는 함수이다.
다음과 같은 결가를 내도록 프로그램을 작성
결과: 
정수 입력 : -34
절대값은 : 34입니다.
종료하려면 0을 입력하세요. */

/*
int abs()
{
	int x;
	int num;
	printf("정수 입력 : ");
	scanf("%d", &num);


	if (num < 0)
	{
		return num * (-1);
		//printf("절대값은: %d 입니다", -1 * num);
	}
	else if(num > 0)
	{
		//printf("절대값은 : %d 입니다.", num);
		return num ;
	}
	else
	{
		//printf("절대값은 : 0 입니다.");
	}

	printf("종료하려면 0을 입력하세요");
	/*
	scanf("%d", &x);
	//abs(m);
	if(x == 0) return 0;

	//return x;

//}
*/





//문제 p206
/*
int rec_func(int n)
{
	if (n <=0) return 0;
	return (n + rec_func(n - 1)) ; 
}*/
/*
int rec_func(int n)
{
	if (n == 1) return n;
	int n_1 = rec_func(n - 1);
	return(n + n_1);
}
*/


//문제4. 달팽이 문제
/*
int DPE(n)
{
	int adults =0, kids = 1;
	//어른과 아이 값 출력 어떻게?

	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n >= 3) return DPE(n - 1) + DPE(n - 2) ;
}
*/

	//문제6. 
/*사칙연산을 계산하는 프로그램 작성
1.메뉴 선택 함수 입력
	1. 덧셈 
	2. 뺄셈 
	3. 곱셈 
	4. 나눗셈
	5.종료
2. 값 입력
3. 결과 출력

!!기능단위의 함수로 만들어 놓기!!
*/

int choice()
{
	int num;
	printf(" \n 메뉴를 선택하시오(번호 입력). \n\n");
	printf(" 1.덧셈 \n 2.뺄셈 \n 3.곱셈 \n 4.나눗셈 \n 5.종료 \n\n 메뉴선택 >>");
	scanf("%d", &num);

	if ((num >= 1)&&(num <= 4) ) return num; 
	if(num ==5)	return 0;
	
	
	/*
	if (num == 1) { return 1; }
	if (num == 2) { return 2; }
	if (num == 3) { return 3; }
	if (num == 4) { return 4; }
	if (num == 5) { return 0; }
	*/
	
}
//기능 단위 함수로 만들어 놓기
int Add(int a, int b)
{
	return (a + b);
}
int Minus(int a, int b)
{
	return (a - b);
}
int Multiply(int a, int b)
{
	return (a * b);
}
int Division(double a, double b)
{
	return (a / b);
}