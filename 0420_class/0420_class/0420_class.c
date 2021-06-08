

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

void swap(double *pa, double *pb);
void line_up(double *maxp, double *midp, double *minp);
int main()
{
	/*
	int ary[5];

	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	scanf("%d", &ary[3]);
	
	printf("%d \n", ary[2]);
	printf("%d \n", ary[3]);
	printf("%d \n", ary[4]);
	*/

		//배열의 개수
	// int ary[5];
	// int count = sizeof(ary) / sizeof(ary[0]);

	//p219
	/*
	int A[3] = { 1,2,3 };
	int B[10];

	for(int i =0; i < 10; i++)
	{
		//B[i] = A[i % 3];
		
		if (i % 3 == 0) { B[i] = A[0]; }
		else if(i % 3 == 1) { B[i] = A[1]; }
		else  { B[i] = A[2]; }
		
		
	}
	for (int j = 0; j < 10; j++)
	{
		printf("B[%d] = %d \n",j, B[j]);
	}
	*/

	/*
	char str[80] = "applejam";
	printf("최초 문자열 : %s \n", str);
	printf("문자열 입력: ");
	scanf("%s", str);
	printf("입력 후 문자열 문자열 : %s \n", str);

	*/
		
	/*
	for  (int i = 0;  i < 3;  i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == i) { printf("*"); }
			else
			{
				printf(" ");
			}

		}
		printf("\n");
	}
	*/
	/*char str[80]; 
	printf("문자열 입력 : ");
	gets(str);
	printf("입력된 문자열 : ");
	puts(str);
*/
	/*
	char str[5];
	str[0] = '0';
	str[1] = 'k';
	str[2] = '\0';
	printf("%s\n ",str);
	*/
	
	//p241
	/*
	int a = 10, b = 15, tot;
	double avg;
	int *pa, *pb;
	int *pt = &tot;
	double *pg = &avg;

	pa = &a;
	pb = &b;

	*pt = *pa + *pb;
	*pg = *pt /2.0;

	printf("두 정수의 값: %d, %d \n",*pa, *pb);
	printf("두 정수의 합: %d \n", *pt);
	printf("두 정수의 평균: %.1lf \n",*pg);
	*/
	
	//p244
	/*
	int a = 10, b = 20;
	const int *pa = &a; //침조만 하고 원본은 변형시키고 싶지 ㅇ낳을떄
	int* const pb = &a; //뒤에 주소를바꾸지 못하게 하겟다

	printf("변수 a값: %d\n", *pa);
	pa = &b;
	printf("변수 b값: %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a값: %d\n",*pa);
	*/

	//p251
/*
int in;
char ch;
double db;

char *pc = &ch;
int *pi = &in;
double *pd = &db;

printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

printf("char* 포인터의 크기 : %d\n", sizeof(pc));
printf("int* 포인터의 크기 : %d\n", sizeof(pi));
printf("double* 포인터의 크기 : %d\n", sizeof(pd));

printf("char* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
printf("int* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
printf("double* 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));
*/



	//Quiz();

	//p261 미니 정렬 프로그램

double max, mid, min;

printf("실수값 3개 입력 : ");
scanf("%lf%lf%lf", &max, &mid, &min);

line_up(&max, &mid, &min);

printf("정렬된 값 출력: %.1lf, %.1lf, %.1lf \n " ,max, mid, min);

	return 0;
}

void swap(double *pa, double *pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//10 30 20
void line_up(double *maxp, double *midp, double *minp)
{
	//printf("%lf %lf %lf\n", *maxp, *midp, *minp);
	if (*maxp <= *midp) //10<30
	{
		swap(&maxp, &midp);  //30 10 20			
		
		//printf("%lf %lf %lf\n", *maxp, *midp, *minp);
	}

	if (*maxp <= *minp) //30 < 20
	{
		swap(&maxp, &minp);  //30 10 20
		
		//printf("%lf %lf %lf\n", *maxp, *midp, *minp);

	}
	if (*midp <= *minp)
	{
		swap(&minp, &midp);
		
		//printf("%lf %lf %lf\n", *maxp, *midp, *minp);
	}

	//printf("%lf %lf %lf\n", *maxp, *midp, *minp);





//p265
/*
int ary[3];
int i;

*(ary + 0) = 10;
*(ary + 1) = *(ary + 0) + 10;

printf("세번째 배열 요소에 키보드 입력 : ");
scanf("%d",ary + 2);

for(i = 0; i<3; i++)
{
	printf("%5d",*(ary+i));
}
*/
/*
int a[3] = {10,20,30};
	int *pa = &a;
	for (int i= 0; i < 3; i++)
	{
		printf("(*pa )++ : %d \n", (*pa)++);
		printf("++(*pa ) : %d \n", ++(*pa));

		printf("a[%d] : %d \n", i,a[i]);

	}
*/
	//p276
/*
int ary[5] = { 10,20,30,40,50 };
	int *pa = ary;
	int *pb = pa + 3;

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;
	printf("pb-pa = %u\n", pb - pa);
	printf("앞에 있는 배열 요소의 값 출력: ");
	if (pa < pb) { printf("%d\n", *pa); }
	else { printf("%d\n", *pb); }

*/
	
//return 0;
	
}
	

int Quiz()
{
	/*문제1 길이가 5인 int형 배열을 선언하고,
	사용자로부터 5개의 정수를 입력받아 다음의 내용을 출력하라

	1.입력된 정수 중 최댓값
	2.입력된 정수 중 최솟값
	3.입력된 정수의 총 값
	*/
	//변수 초기화 --> 0으로 초기화
	/*

	int max = 0, min = 0, tot = 0;

	int num[5] = { 0, };
	scanf("%d%d%d%d%d", for(int i = 0; i < 5; i++) { &num[i]; });
	max = num[0], min = num[0], tot = 0;

	for (int i = 0; i < 5; i++)
	{
		max = num[i] > max ? num[i] : max;
		min = num[i] > min ? min : num[i];
		tot += num[i];
	}

	printf("입력된 정수 중 최대값 : %d \n", max);
	printf("입력된 정수 중 최솟값 : %d \n", min);
	printf("입력된 정수 총합 : %d \n", tot);

	*/


	/*
	count = sizeof(str) /sizeof(str[0])
	while(count>=0){}
	*/


	//p232
	/*대소문자 변환 프로그램*/
	/*
	char str[80];
	int count = 0;
	printf("문장 입력 :");
	gets(str);

	for(int i = 0; i<80; i++)
	{
		if (((int)str[i] <= 90) && ((int)str[i] >= 65))
		{
			str[i] = str[i] + 32; //왜인지 이해가 안됨
			count++;
		}
	}

	printf("바뀐 문장 :");
	puts(str);
	printf("바뀐 문자 수 : %d", count);
	*/


	//문제2
/* 문자열을 입력받아서 문자열을 광고판에 출력되듯이 한칸이
옆으로 이동하면서 출력되도록 프로그램을 작성
Hello~
ello~ H
llo~ He


//cls -> 화면 지우기
시간제어 -> for문 돌리기
키보드 입력 확인하는 함수
*/

//나머지
//문자열 전체 카피
/*	
	
	char str[80];
	int strCount = 0;
	int count = 0;
	int keyNum;
	printf("문장 입력 :");
	gets(str);
	system("cls");

	//문자길이 카운팅
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		strCount++;
	}
	 strCount = strCount + 1;

	printf("%d \n", strCount);

	
	
		//마지막글자부터 나타날 때
		for (int j = 0; j < strCount; j++)
		{			
			system("cls");
			count++;
			for (int k = count; k > 0; k--)
			{
				printf("%c", str[strCount - k]);
			}
			printf(" ");

			for (int m = 0; m < (strCount - count); m++)
			{
				printf("%c", str[m]);
			}
			printf("\n");
			Sleep(700);
		}
	
	
	//첫번째 글자부터 나타날 때 <--
	
	for (int j = 0; j < strCount; j++)
		{
			system("cls");
			count++;

			for (int k = count; k < strCount - 1; k++)
			{
				printf("%c", str[k]);
			}
			printf(" ");

			for (int m = 0; m < (count+1); m++)
			{
				printf("%c", str[m]);
			}
			printf("\n");
			Sleep(700);
		}
	*/
		

	//문제3 
	/* int형 변수 num1,num2를 선언과 동시에 각각  10과20으로 
	초기화하고 int형 포인터 변수 ptr1과 ptr2를 선언하여 
	각각 num1과 num2를 가리키게 하자 

	이 상태에서 포인터 변수 ptr1과 ptr2를 이용해서 
	num1의 값을 10증가, num2의 값을 10 감소시키자

	그리고 나서, 두 포인터 변수 ptr1과 ptr2가 가리키는 대상을 
	서로 바꾸자
	(ptr1 ->num2  ptr2 -> num1)
	마지막으로 ptr1과 ptr2가 가리키는 변수에 저장된 값을 출력하라.
	*/

/*
int num1 = 10, num2 = 20;

int *ptr1, *ptr2;

ptr1 = &num1;
ptr2 = &num2;

num1 = *ptr1 + 10;
num2 = *ptr2 - 10;

ptr1 = &num2;
ptr2 = &num1;

printf("*ptr1 : %d , ptr2 : %d \n", *ptr1, *ptr2);
*/



}
	
		
			






















	
	





