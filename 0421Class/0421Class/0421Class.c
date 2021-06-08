#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

// 과제 11 : 과제 10을 포인터로 바꾸기 
//안되는데?
/*
int main()
{
	char str[80];
	int *pstr = str;

	printf("문장 입력 : ");
	gets(str);
	system("cls");
	int strCount = 0, count = 0;
	//입력된 글자 수 카운팅
	for (int i = 0; *pstr != 0; i++)
	{
		strCount++;
	}
	strCount = strCount + 1;

	//진행방향 <--
	for (int j = 0; j < strCount; j++)
	{
		system("cls");
		count++;
		for (int k = count; k < strCount - 1; k++)
		{
			printf("%c", str[k]);
		}
		printf(" ");
		for (int m = 0; m < count; m++)
		{
			printf("%c", str[m]);
		}
		printf("\n");
		Sleep(1500);
	}
}
*/

//문제2, 과제12
/*길이가 6인 int형 배열을 arr을 선언하고 이를 1,2,3,4,5,6으로 
초기화 한 다음, 배열에 저장된 값의 순서가 6,5,4,3,2,1이 
되도록 변경하는 프로그램을 작성하자
단 배열의 앞과 뒤를 가리키는 포인터 변수 두개를 선언해서 
이를 활용하여 저장된 값의 순서를 뒤바꿔야 한다.
*/
//주소는 첫번째 주소
//포인터는 값


/*
int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
//포인터 간의 연산을 통해서 바꿔주기
	int *pf = arr;
	int *pb = arr + 5;
	int temp;
	for (int m = 0; m < 3; m++)
	{
		temp = *(pf + m);

		//상수 =상수니까 변수 = 상수
		(pf + m) = *(pb - m);

		(pb - m) = temp;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("arr[%d] : %d \n",i, *(pb +  i));
	}

	}
	*/

//배열arry전체출력 코드 추가
//p284
/*
void input_ary(double *pa, int size);
void ouput_ary(double *pa, int size);
void find_max(double *pa, int size);
int main()
{
	double ary[5];
}
*/


//p292
//문제, 과제 13
/*
void input_nums(int *lotto_nums, int size);
void print_nums(int *lotto_nums, int size);
int main()
{
	int lotto_nums[6];
	input_nums(lotto_nums,6);
	print_nums(lotto_nums,6);
}

void input_nums(int *lotto_nums, int size) 
{
	int count = 0;
	int i = 0;

	while (count < size) 
	{
		printf("번호 입력 : ");
		scanf("%d", lotto_nums);

		if (i >= 1)
		{
			for (int j = 0; j <  j< size; j++)//(i+1)
			{
				
				//if문 사용하면서 입력한 번호와 그 전에 번호 비교하여서
				//같은 거 있으면 break
				
				if (*(lotto_nums + i) == *(lotto_nums + j))
				{
					printf("같은 번호가 있습니다! \n");
					printf("%d \n", *(lotto_nums + i));
					break;
				}
				else 
				{
					//count++;
					printf("실행되었을때 %d \n", count);
				}
			}
			
		}
		i++;
	
	}
}
	
void print_nums(int *lotto_nums, int size)
{
	for(int i =0; i<size; i++)
	{
		printf("로또 번호");
	}
	
}
*/
	//p300
/*
int main()
{
	int ch;
	ch = getchar();

	printf("입력한 문자 : ");

	putchar(ch);
	putchar('\n');
}
*/
/*p311 : 입력버퍼지우기
int main()
{
	int num, grade;

	printf("학번 입력 : ");
	scanf("%d",&num);
	getchar();   //개행문자제거
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c \n", num, grade);

	return 0;
}
*/

	
	


