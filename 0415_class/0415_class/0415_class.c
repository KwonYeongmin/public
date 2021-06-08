// 0415_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
		//p101
	/*
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b);
	printf("a = %d, b=%d \n", a, b);
	printf("a / b 의 결과 : %.1f \n", res);

	a = (int)res;
	printf("(int)%.1lf의 결과 : %d \n", res, a);
	*/
	
		//sizeof 연산자
	/*
	int a = 10;
	double b = 3.4;

	printf("int형 변수의 크기 : %d \n", sizeof(a));
	printf("double형 변수의 크기 : %d \n", sizeof(b));
	printf("정수형 상수의 크기 : %d \n", sizeof(10));
	printf("수식의 결괏값의 크기 : %d \n", sizeof(1.5 + 3.4));
	printf("char 자료형의 크기 : %d \n", sizeof(char));
	*/

	//복합대입연산자
	
	/*
	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res *= b + 10;

	printf("a=%d,b=%d \n", a, b);
	printf("res=%d \n", res);
	*/

	//콤마연산자
	/*
	int a = 10, b = 20;
	int res;
	res = (++a, ++b);
	printf("a:%d,b:%d \n", a, b);
	printf("res : %d \n", res);
	*/
	
	//조건연산자
	/*
	int a, b, c,res;
	printf("첫번째 정수를 입력하시오  ");
	scanf("%d", &a);
	printf("두번째 정수를 입력하시오  ");
	scanf( "%d", &b );
	res = (a > b) ? a : b;
	printf("세번째 정수를 입력하시오  ");
	scanf("%d", &c);
	res = (res > c) ? res : c;
	printf("%d", res);
	*/
	
	//비트연산자
	/*
	int a = 13; //1101
	int b = 5;  //0101
	printf("a&b : %d \n", a & b); //0101
	printf("a^b : %d \n", a ^ b); // 1000
	printf("a|b : %d \n", a | b); //1101
	printf("~a : %d \n", ~a); // 11110010
	printf("a << 1 %d \n", a << 1); // 
	printf("a >> 2 %d \n", a >> 2); // 
	*/
	
	//문제1 p118
	/*
	int res;

	res = sizeof(short) > sizeof(long);
	printf("%d \n", res);
	res = sizeof(short) > sizeof(long) ? sizeof(short) : sizeof(long);
	printf("%d \n", res);
	*/
	
	
	/*
	//문제2
	int seats = 70, audience = 64;
	double rate;
	rate = ((double)audience) / ((double)seats) * 100;
	printf("%lf \n", rate);
	*/
	
	/*
	int a = 20;
	int b = 0;

	if(a>10)
	{
		b = a;
	}
	printf("a : %d, b : %d \n", a, b);
	*/
	/*
		int a = 0, b = 0;
		if(a>0)
		{
		b = 1;
		}
		else if(a==0)
		{
		b = 2;
		}
		else
		{
		b = 3;
		}

		printf("b : %d \n", b);
	*/

		//문제1 p135
/*
int a;

	if(a < 0)
	{
		a = -a;
	}

	if(a % 2 ==0)
	{
		a = 2;
	}
	else
	{
		a = 1;
	}
*/
	
	
		//문제2
/*
int chest = 95;
	char size;

	if( chest <= 90)
	{
		size = 'S';
	}
	else if((chest > 90)&&(chest <= 100))
	{
		size = 'M';
	}
	else
	{
		size = 'L';
	}
*/
	/*
	int a = 1;
	while (a < 10)
	{
		a = a * 2;
	}

	printf("a : %d", a);
	*/
	
	//문제1~3 p165

/*
int i, j;

	for(i =0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("*");
		}
		printf("\n");
	}
*/

//p171
/*
for (int i = 2; i <= 9; i++)
{
	for (int j = 1; j <= 9; j++)
	{
		printf("%d X %d = %d \n" , i,j ,i * j);
	}
}

*/


	//Quiz();

	return 0;
	
}
int Quiz()
{
	//문제1
	/*
	double weight, height;
	double BMI_rate;

	printf("몸무게를 입력하시오. ");
	scanf("%lf", &weight);
	printf("키(cm)를 입력하시오. ");
	scanf("%lf", &height);

	BMI_rate = weight / (height *0.01 * height*0.01);
	printf("%lf", BMI_rate);
	(BMI_rate >= 20.0 && BMI_rate < 25.0) ? printf("표준입니다.") : printf("체중관리가 필요합니다.");
	*/

	//문제2
/*
int a, b;

printf("if~else이용 \n");
printf("두 개의 정수를 입력하시오 \n");
scanf("%d %d", &a, &b);
if(a <= b)
{
	printf("%d \n",b - a);
}
else
{
	printf("%d \n",a - b);
}
printf("조건 연산자 \n");
printf("두 개의 정수를 입력하시오 \n");
scanf("%d %d", &a, &b);
a > b ? printf("%d",a-b) : printf("%d",b - a);

*/

//문제3
/*
int score;
double avg;
int kor, eng, mat;

printf("국어점수를 입력하시오.  ");
scanf("%d", &kor);
printf("영어점수를 입력하시오.  ");
scanf("%d", &eng);
printf("수학점수를 입력하시오.  ");
scanf("%d", &mat);

avg = ((double)kor + (double)eng + (double)mat) / 3;

if(avg>=90.0)
{
	printf("평균점수 : %0.2lf   학점: A", avg);
}
else if (avg >= 80.0)
{
	printf("평균점수 : %0.2lf   학점: B", avg);
}
else if(avg >= 70.0)
{
	printf("평균점수 : %0.2lf   학점: C", avg);
}
else if (avg >= 60.0)
{
	printf("평균점수 : %0.2lf   학점: D", avg);
}
else
{
	printf("평균점수 : %0.2lf   학점: F", avg);
}
*/

//문제3
/*
int a, b;
char cal;

printf("정수 사칙연산을 입력하시오 ");
scanf("%d%c%d",&a, &cal, &b );

if(cal == '+')
{
	printf("%d + %d = %d \n" , a, b, a + b);
}
else if(cal == '-')
{
	printf("%d - %d = %d \n", a, b, a - b);
}
else if(cal == '*')
{
	printf("%d x %d = %d \n", a, b, a * b);
}
else if(cal == '/')
{
	printf("%d / %d = %lf \n", a, b, (double)a / (double)b);
}
*/


//문제4
/*팩토리얼  while, for문으로 */
/*
int a;
	int res;

	scanf("%d",&a);

	for (a ; a < 2; i--)
	{
		a = a * (a + 1);
	}
*/
	

	//문제5
	/*두 수 사이에 존재하는 정수의 합을 구하여 출력 -> while,for 
	int n1, n2;
	int minus;
	int res;
	scanf("%d", &n1);
	scanf("%d", &n2);

	if (n2 > n1) 
	{ 
		minus = n2 - n1;
		for (int i = 1; i < (minus + 1); i++)
		{
			n1 = n1 + i ;
		}

		printf("%d", n1);
			
	}
	else if(n1 > n2)
	{
		minus = n1 - n2;
		for (int i = 1; i < (minus + 1); i++)
		{
			n2 = n2 + i;
		}
		printf("%d", n2);
	}
	else
	{
		res = n1 * 2;
		printf("%d", res);
	}*/
	
	//문제6
/*
int res;
	while(res < 100)
	{
		for (int i = 1; i <20; i++)
		{
			res = 7 * i;
		}

	}
	printf("%d", res);
	int res;

for (int i = 1; i < 20; i++)
{
	printf("%d", 7 * i);
}

while (res < 100)
{

}*/






}
