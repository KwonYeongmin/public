#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>
//달팽이 수열
/*
int main()
{
	int x = 0, y = 0;
	int dir = 1;
	int size=1,k = 1;
	int arr[10][10];
	scanf("%d",&size);
	int val = 1;
	int i, k;

	for (i = 0; i < size; i++)
	{
		arr[0][x] = val;
		x += k;
	}
	//size--;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d",arr[i][j]);
		}
	}
	return 0;
}
*/

//달팽이 수열 변형






//void Quiz2();
//void MaxAndMin(int **maxPtr, int **minPtr, int arr[5]);
/*
void make_rand();
void input_res(int randomArr[3], int inputNumArr[3]);
void print_res(int strike, int ball);
*/
//p422
//void swap_ptr(char **ppa, char **ppb);
//p425
//void swap_ptr(char **pps,int count);

//int main()
//{
	//make_rand();

	/*p417
	
	int a = 10;
	int *pi;
	int **ppi;

	pi = &a;
	ppi = &pi;

	printf("--------------------------------------------------------\n");
	printf("변수	변수값	   &연산   *연산	**연산\n");
	printf("--------------------------------------------------------\n");
	printf("a  %10d%10u\n", a, &a);
	printf("pi %10u%10u%10d\n", pi, &pi, *pi);
	printf("ppi%10u%10u%10u%10d\n", ppi, &ppi, *ppi, **ppi);
	printf("--------------------------------------------------------\n");
	*/

	/*p422

	char *pa = "SSS";
	char *pb = "FFF";

	printf("pa -> %s, %p,%p \n", pa, *pa, &pa);
	printf("pb -> %s, %p,%p \n", pb, *pb, &pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, %p,%p \n", pa, *pa, &pa);
	printf("pb -> %s, %p,%p \n", pb, *pb, &pb);*/
	//p425
	/*
	char *ptr_ary[] = { "E","T","L" ,"S" };
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	*/
	//p427
	/*
	int ary[5];
	printf("ary의 값 : %u\t", ary);
	printf("ary의 주소 : %u\n", &ary);
	printf("ary+1 : %u\t", ary + 1);
	printf("&ary+1 : %u\n",&ary+1);
	*/
	/*
	int ary[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	printf("ary+1: %d \t %d \n", ary + 1, ary + (1 * sizeof(ary[0])));
	printf("*(ary+1): %d \n", *(ary + 1));
	printf("*(ary+1)+2: %d \n", *(ary + 1) + 2);
	printf("*(*(ary+1)+2): %d \n", *(*(ary + 1) + 2));
	*/
	//Quiz2();

	//return 0;
//}
/*
void swap_ptr(char **pps, int count) 
{
	int i;
	for(i=0;i<count;i++)
	{
		printf("%s\n",pps[i]);
	}
}*/
	//문제1
/*
	컴퓨터에게서 3자리의 숫자를 임의로 정하게 한 뒤
	사용자가 3자리의 숫자를 입력해서 결과를 확인한다.
		사용되는 숫자는 1~9까지 서로 다른 숫자이다.
		숫자가 있지만 그 위치가 틀렸을 때는 볼을 출력
		숫자와 위치가 맞으면 스트라이크 출력
		숫자와 위치가 전부 틀리면 아웃 출력
		무엇이 볼이고 스트라이크인지는 출력하지 않는다.
		
		컴퓨터 2 1 6
		1		8 3 5		/	out
		2		6 3 9		/	0 스트라이크 1볼
		3		2 6 4		/	1 스트라이크 2볼
		4		2 1 6		/	정답
*/


//난수 생성
/*
void make_rand() 
{
	srand((unsigned int)time(NULL));
	int random;
	int randomArr[3];
	int inputNumArr[3];
	
	for (int i = 0; i < 3; )
	{
		random = rand() % 9 + 1;
		randomArr[i] = random; 

		for(int j=i+1; i<3;j++)
		{
			if (randomArr[j] == randomArr[i])
			{
				random = rand() % 9 + 1;
			}
			else
			{
				i++;
			}
		}
		printf("%d \t", randomArr[i]);
	}
	
	//input_res(randomArr, inputNumArr);
}
*/
/*
//숫자 입력
void input_res(int randomArr[3], int inputNumArr[3])
{
	int strike = 0, ball = 0;

	printf("숫자를 세 개를 입력하세요: ");
	
	int count = 1;
	while (1)
	{
		printf("%d번째 숫자를 입력하세요 : ",count++);

	}
	//while(count)
	for (int i = 0; i < 3;)
	{
		scanf("%d", &inputNumArr[i]);
		//printf("정답 : %d", randomArr[i]);		
		for (int k = 0; k < 2; k++)
		{
			if (inputNumArr[k+1] == inputNumArr[i]) 
			{
				while (1)
				{
					printf("중복되지 않는 숫자를 입력하세요");
					scanf("%d", &inputNumArr[i]);
					if (inputNumArr[k] != inputNumArr[i]) break;
				}
			}
		}
		printf("정답 : %d", randomArr[i]);
	}


	for (int i = 0; i < 3; i++)
	{
		if (randomArr[i] == inputNumArr[i])
		{
			strike++;
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				if (randomArr[j] == inputNumArr[i]) { ball++; }
			}
		}
	}	
	print_res(strike, ball);
}
*/
/*
//정답 출력
void print_res(int strike,int ball)
{
	if (strike == 2)
	{
		printf("정답 \n");
	}
	else
	{
		printf("strike : %d   ball:%d \n", strike, ball);
		if ((ball == 0) && (strike == 0))
		{
			printf("out \n");
		}
	}
}
*/

//문제2 
/*두 개의 ont형 포인터 변수와 길이가 5인 int형 배열을 
다음과 같이 선언한다
int *maxPtr;
int *minPtr;
int arr[5];
MaxAndMin이란 함수를 정의하고 이를 호출하여 위 배열과 두 포인터를
변수로 전달한다. 이 함수의 호출이 완료되면, 포인터 변수 maxPtr에는 
배열 요소의 주소값이,minPtr에는 가장 작은 배열 요소의 주소값이
저장되어야 한다.
결과 출력
arr주소값과 최대,최소의 주소값, 그 주소에 저장된 값을 출력하라.
*/

//void MaxAndMin(int **maxPtr, int **minPtr, int arr[5]);
/*
int main() 
{
int arr[5] = {21,39,5,10,1};
int *maxPtr = &arr[0];
int *minPtr = &arr[0];

MaxAndMin(&maxPtr,&minPtr,arr);

//printf("arr의 주솟값 : %u \n", &arr);
//printf("최소의 주솟값 : %u, 최솟값: %d \n", minPtr, *minPtr);
//printf("최대의 주솟값 : %u, 최댓값: %d \n", maxPtr, *maxPtr);

	
return 0;
}*/
/*
void MaxAndMin(int **maxPtr, int **minPtr, int arr[5])
{
	for (int i = 0; i < 5; i++)
	{
		**maxPtr = **maxPtr > arr[i] ? **maxPtr : arr[i];
		**minPtr = **minPtr < arr[i] ? **minPtr : arr[i];

		//printf("최소의 주솟값 : %u, 최솟값: %d \n", &minPtr, **minPtr);
		printf("최대의 주솟값 : %u, 최댓값: %d \n", &maxPtr, **maxPtr);

	}

	//printf("최소의 주솟값 : %u, 최솟값: %d \n", &minPtr, **minPtr);
	//printf("최대의 주솟값 : %u, 최댓값: %d \n", &maxPtr, **maxPtr);
}*/
/*
int sum(int, int);
int Minus(int, int);
int Multiply(int, int);
int divide(int, int);

int main()
{
	int(*fp)(int, int);
	int res;
	fp = sum;
	res = fp(10, 20);
	printf("result:%d \n", res);
	fp = Minus;
	res = fp(10, 20);
	printf("result:%d \n", res);
	fp = Multiply;
	res = fp(10, 20);
	printf("result:%d \n", res);
	fp = divide;
	res = fp(10, 20);
	printf("result:%lf \n",res);

	return 0;
}

int sum(int a, int b) 
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

int divide(int a, int b)
{
	return ((double)a / (double) b);
}
*/
/*
int main()
{
	int a = 10;
	double b = 3.5;
	void *vp;

	vp = &a;
	printf("a:%d\n",*(int*)vp);
	vp = &b;
	printf("b:%0.1lf\n", *(double*)vp);
	
}*/

void swap (char *pdata, void *pa, void *pb);

/*
int main()
{
	int *pi;
	int size = 5;
	int count = 0;

	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int));
	while(1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d",&num);
		if(num<=0) break;
		if (count == size) 
		{
			size += 5;
			pi = (int*)realloc(pi,size*sizeof(int));
		}
		pi[count++] = num;
	}
	for(i=0;i<count;i++)
	{
		printf("%5d",pi[i]);
	}
	free(pi);
	return 0;
	
	*/

	/*
	int *pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));

	if (pi == NULL)
	{
		printf("#메모리가 부족합니다 \n");
		exit(10);
	}
	printf("다섯명의 나이를 입력하시오");

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]);
		sum += pi[i];
	}
	printf("다섯명의 평균 나이 : %0.1lf \n",(sum/5.0));
	free(pi);
	return 0;

	*/

	/*
	int *pi;
	double *pd;

	pi = (int*)malloc(sizeof(int));
	if(pi==NULL)
	{
		printf("#메모리가 부족합니다 \n");
		exit(10);
	}
	pd = (double*)malloc(sizeof(double));

	*pi = 10;
	*pd = 3.4;

	printf("정수형으로 사용 : %d \n", *pi);
	printf("정수형으로 사용 : %.1lf \n", *pd);

	free(pi);
	free(pd);

	return 0;



	int age1;
	int age2;
	double height1;
	double height2;
	char data[80];

	printf("첫번째 사람의 나이와 키 입력: ");
	scanf("%d%lf",&age1, &height1);
	printf("두번째 사람의 나이와 키 입력: ");
	scanf("%d%lf", &age2, &height2);

	printf("\n");

	swap("int", &age1, &age2);
	swap("double",&height1, &height2);

	printf("첫번째 사람의 나이와 키 : %d  %0.2lf \n", age1, height1);
	printf("첫번째 사람의 나이와 키 : %d  %0.2lf \n", age2, height2);

	return 0;*/
//}

void swap (char *pdata, void *pa, void *pb) 
{
	
	if ((strcmp(pdata ,"int"))==0)
	{
		int temp ;
		temp = *(int*)pa;
		*(int*)pa = *(int*)pb;
		*(int*)pb = temp;
	}
	else if((strcmp(pdata, "double")) == 0 )
	{
		double temp ;		
		temp = *(double*)pa;
		*(double*)pa = *(double*)pb;
		*(double*)pb = temp;
	}
}
//문제3
/*
사용자로부터 문자열을 입력받아서 출력하는 프로그램 작성

1. 문자열을 입력받기전에 사용자로부터 문자열의 최대 길이에 대한 정보를
먼저 입력받고, 그 길이 만큼 메모리 공간을 동적으로
할당해 문자열을 입력받아 출력하도록 한다.
특정문자가 입력될까지 반복하도록 한다.
("Quit ->프로그램 종료")
2.해제
3.출력할때 다음과 같이 단어 단위로 문자열을 뒤집어 주도록 한다.
 i am happy
 happy am i
*/

int main() 
{
	int length;	
	int *pi;
	
	printf("문자열의 최대 길이를 입력하시오: ");
	scanf("%d",&length );
	pi = (char*)malloc(length * sizeof(char));
	
	if (pi == NULL) 
	{
		printf("메모리가 부족합니다 \n");
		exit(1);
	}

	printf("문자열을 입력하시오 : ");

	int i = 0;

	while (1)
	{
		scanf("%s", pi[i]);
		//if ((strcmp(pi[i], "Quit") == 0) ) { break; }
		if (strcmp(pi[i], "Quit") != 0) 
		{
//			pi = strcat(pi[i], pi[i+1]);
			i++;

			scanf("%s", pi);
		}

	}
	free(pi);
	int count = 0;
	while (1) 
	{
		
		if (strcmp(pi, " ") == 0) 
		{
		//뒤집어 
		}
		if (strcmp(pi, "\0") == 0) { break; }
		
	}

	return 0;
}