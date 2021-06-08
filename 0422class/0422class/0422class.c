#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

//순서 문자열 많은 것 부터
//p353 단어 정렬 프로그램

//cnp는 대소문자에서 문제 생긴다.
/*
void auto_func(); //static
void static_func(); //
int main()
{
	int i;
	printf("일반지역변수(auto)를 사용한 함수 ...\n");
	for (i = 0; i < 3; i++) 
	{
		auto_func();
	}
	printf("정적지역변수(static)를 사용한 함수 ...\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}
void auto_func() 
{
	auto int a = 0;
	a++;
	printf("%d \n", a);
}
void static_func()
{
	static int a = 0;
	a++;
	printf("%d \n", a);
}
*/

/*
p375 주소 반환
int  *sum(int a, int b);

int main() 
{
	int *resp;
	resp = sum(10, 20); //주소값
	printf("두정수의 합 :%d \n", *resp); //주소값의 참조연산자니까 값 출력
	return 0;
	//quiz1();
}

int *sum(int a, int b) 
{
	static int res;
	res = a + b;
	return &res;
}
*/

//p384
/*
int main()
{
	int score[3][4];
	int tot;
	double avg;
	int i, j;

	for (int i = 0; i < 3; i++) 
	{
		printf("네 과목의 점수 입력 :");
		for (int j = 0; j < 4; j++) 
		{
			scanf("%d",&score[i][j]);
		}	
	}

	for (int i = 0; i < 3; i++)
	{
		tot = 0;
		for (int j = 0; j < 4; j++)
		{
			tot += score[i][j];
		}
		avg = tot / 4.0;
		printf("총점 : %d, 평균 : %0.2lf \n", tot, avg);
	}
}
*/
/*
int main() 
{
	
	int ary1[4] = { 1,2,3,4 };
	int ary2[4] = { 11,12,13,14 };
	int ary3[4] = { 21,22,23,24 };
	int *pary[3] = { ary1,ary2,ary3 };

	int i, j;

	for(i=0;i<3;i++)
	{
		for (j = 0; j < 4; j++) 
		{
			printf("%5d ",pary[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/

//int main()
//{
	//quiz4();
//}

int main()
{
	int size = 0;
	int value = 1;
	int row = 0,col=-1;
	int dir = 1;
	
	int arr[10][10] = {0,};
	printf("크기를 구하시오  ");
	scanf("%d",&size);
	while(size>0)
	{
		for (int i = 0; i < size; i++)
		{
			col += dir;
			arr[row][col] = value;
			value++;
		}
		size--;
		if (size < 0) { break; }
		for (int i = 0; i < size; i++)
		{
			row += dir;
			arr[row][col] = value;
			value++;
		}
		dir *= -1;
	}
	/*
	
	int size = 0;
	int arr[10][10] = { 0, };

	printf("배열의 크기를 입력하시오 : ");
	scanf("%d", &size);

	int k = 1, row = 0, col = -1; //배열의 값,행과 열을 나타내는 인덱스
	int indexDir = 1; //인덱스의 증감량을 나타냄 
	int i, j;

	while (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			col += indexDir;
			arr[row][col] = k;
			k++;
		}
		size--;
		if (size == 0) break;
		for (j = 0; j < size; j++)
		{
			row += indexDir;
			arr[row][col] = k;
			k++;
		}
		indexDir *= -1;
	}


	//방법2 : 
	//방법3 : ㄱ,ㄴ

	//함수 출력
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
/*
void spiral_arr()
{
	//방법1 :
	//변수 초기화
	int size =0 ;
	int arr[10][10] = { 0, };
	
	printf("배열의 크기를 입력하시오 : ");
	scanf("%d", &size);
	
	int k = 1,row = 0, col = -1; //배열의 값,행과 열을 나타내는 인덱스
	int indexDir = 1; //인덱스의 증감량을 나타냄 
	int i, j;

	while (size > 0)
	{
		for (i = 0; i < size; i++) 
		{
			col += indexDir;
			arr[row][col] = k;
			k++;
		}
		size--; 
		if (size == 0) break;
		for (j = 0; j < size; j++) 
		{
			row += indexDir;
			arr[row][col] = k;
			k++;
		}
		indexDir *= -1;
	}


	//방법2 : 
	//방법3 : ㄱ,ㄴ

	//함수 출력
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}
*/


// 달팽이 배열을 채울때 ㄱ ㄴ 이런 모양으로 한번에 채우기
//https://m.blog.naver.com/PostView.nhn?blogId=bsu1313&logNo=221348596995&proxyReferer=https:%2F%2Fwww.google.com%2F





void swap(char *pdata, void *pa, void *pb);

int main()
{
	int age1;
	int age2;
	double height1;
	double height2;
	char data[80];
	printf("첫번째 사람의 나이와 키 입력: ");
	scanf("%d %0.2lf", &age1, &height1);
	printf("두번째 사람의 나이와 키 입력: ");
	scanf("%d %0.2lf", &age2, &height2);

	swap("int", &age1, &age2);
	swap("double", &height1, &height2);
	printf("첫번째 사람의 나이와 키 입력: ", &age1, &height1);
	printf("첫번째 사람의 나이와 키 입력: ", &age2, &height2);
}

void swap(char *pdata, void *pa, void *pb)
{

	if (*pdata == "int")
	{
		int temp;
		temp = *pa;
		*pa = *pb;
		*pb = temp;
	}
	else if (*pdata == "double")
	{
		double temp;
		temp = *pa;
		*pa = *pb;
		*pb = temp;
	}
}