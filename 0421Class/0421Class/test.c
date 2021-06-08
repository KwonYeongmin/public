#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

	//문제
	//과제 11 : 과제 10을 포인터로 바꾸기 
	/*
int main()
{
	char str[100];
	gets(str);
	system("cls");

	while (1)
	{
		printf("%s\n", str);

		char firstChar = str[0];    //char *pc = str;
		int i = 0;					//char firstChar = *pc;

		while (str[i] != '\0')		// *pc != '\0'
		{
			if (str[i + 1] != '\0') // (*(pc+1)) != '\0'
				str[i] = str[i + 1]; // *pc != *(pc+1);
			else
				str[i] = firstChar;  //*pc = firstChar

			++i;					//++pc
		}

		Sleep(5);
		system("cls");
	}

	return 0;
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

		//질문
/*
int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
//포인터 간의 연산을 통해서 바꿔주기
	int *pf = arr;
	int *pb = arr + 5;
	int temp;
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int m = 0; m < size; m++)
	{
		temp = *(pf + m);
		*(pf + m)= *(pb - m); //바로 넣지말라는거는 뭐지
		*(pb - m) = temp;
	}for (int i = 0; i < 6; i++)
	{
		printf("arr[%d] : %d \n",i,arr[i]);
	}
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

		for (int j = 0; j <  j< size; j++)
			{

			if(i > 0)
			{
				if (*(lotto_nums + i) == *(lotto_nums + j))
				{
					printf("같은 번호가 있습니다! \n");
					//printf("%d \n", *(lotto_nums + i));
					break;
				}
				else
				{
					count++;
					//printf("실행되었을때 %d \n", count);
				}
			}
			i++;
			}
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

	//문제, 과제14
	//입력한 문자의 길이 저장하기
	//전과 비교하여 더 큰 길이의 값만 남겨놓기
	//저장된 길이 출력하기
/*
int main()
{
	int ch = 0;
	char maxStr[80] ;
	char curStr[80];
	int len = 0;

	while(1)
	{
		int count = 0;

		ch = getchar();

		if (EOF == ch)
		{
			break;
		}
		while (ch!='\n')
		{
			curStr[count] = ch;
			count++;
			ch = getchar();
		}
		//다음문자에 널문자 넣어주기
		len = count > len ? count : len;
		//while문으로 돌려서 확인해주기
	}
	printf("%d", len);
	}
*/





//실습해보기

/*
int main()
{
	char str[12] = { "apple" };
	int* pstr = "apple";
	int res = 0;
	res = (str == pstr);
	printf("%d \n", res); //0
	res = ("apple" ==  pstr);
	printf("%d \n", res); //1
	res = ("apple" == "banana");
	printf("%d \n", res); //0
}
*/
	//p339
/*
int main()
{
	char str1[80] = "strawberry";
	char str2[80] = "apple";

	int *ps1 = "banana";
	int *ps2 = str2;

	printf("최초 문자열 : %s \n", str1);
	strcpy(str1, str2);
	printf("바뀐 문자열 : %s \n", str1);

	strcpy(str1, ps1);
	printf("바뀐 문자열 : %s \n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열 : %s \n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열 : %s \n", str1);
}
*/


//p340
//strncpy
/*
int main()
{
	char str[20] = "mango tree";
	strncpy(str, "apple-pie", 5);
	printf("%s \n", str);

	return 0;
}
*/

//위치와 크기 알아보기
//내가 찾고자 하는 단어가 어디있는지 찾을 수 있음
/*
void main()
{
	char szBuf[32] = { "I am a boy." };
	printf("%p \n", szBuf);

	printf("%p \n", strstr(szBuf, "am"));
	printf("%p \n", strstr(szBuf,"boy"));
}
*/





		//함수만들어주기

//char *my_strcpy(char *pd, char *ps);
//char *my_strcat(char *pd, char *ps);
//char my_strlen(char *ps);
//char my_strcmp( char *pa, char *pb);


/*
int main()
{
		//strcpy 만들기
	/*
	char ch[100] = "strawberry";

	printf("바꾸기 전 문자열 : %s \n",ch);
	*my_strcpy(ch,"apple");
	printf("바꾼 후 문자열 : %s \n", ch);
	*my_strcpy(ch, "kiwi");
	printf("다른 문자열 : %s \n", ch);
	*/
	
	//strcat함수 만들기

	//strlen함수 만들기
	
	//strcmp함수 만들기


	
//strcpy 만들기
/*
char *my_strcpy(char *pd, char *ps)
{

	/*
	int newCount = 0;
	for (int i = 0; *(ps + i) != '\0'; i++)
	{
		newCount++;
	}
	//printf("%d \n", newCount);
	for (int m = 0; m < newCount; m++) //while (*ps != '0')
	{
			*(pd + m) = *(ps + m);

	}
	*(pd + newCount) = '\0';

	return pd; //주소를 리턴
	
//char *po = pd; // 생략해도됨

while (*ps != '0')
{
	*pd = *ps;
	pd++;
	ps++;
}
*pd = '\0';

return po;
}
*/


//strcat함수 만들기
/*
char *my_strcat(char *pd, char *ps) 
{
	char *po = pd;

	while(*pd != '\0')
	{
		pd++;
	}
	while(*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	
	return po;

}

//strlen함수 만들기
char my_strlen(char *ps)
{
	int cnt = 0;
	while(*ps != '\0')
	{
		cnt++;
		ps++;
	}

	return cnt;
}

char my_strcmp(char *pa, char *pb) 
{
	while((*pa == *pb)&&(*pa != '\0'))
	{
		pa++;
		pb++;
	}

	if (*pa > *pb) return 1;
	else if (*pa < *pb) return -1;
	else return 0;
}
*/



//문제
//boy를 girl로 바꾸기
//문자를 찾아서 바꾸는 걸로 함수로 만들기
int my_change(int *pz,int *pd, int *pn);

void main()
{
	char szBuf[32] = { "I am a boy." };
	//printf("%p \n", szBuf);

	//printf("%p \n", strstr(szBuf, "am"));
	//printf("%p \n", strstr(szBuf, "boy"));
	my_change(szBuf,"boy","girl");
	printf("%s",szBuf);
}

int my_change(int *pa,int *pd, int *pn)
{
	
	int address = strstr(pa, pd);
	int count = 0;
	int Acount = 0;

	count = strlen(pd);
	Acount = strlen(pa);
	
	//printf("%d, %d", count, Acount);
	strcpy(pa, *pn);
	/*
	for(int i = count; i > Acount-count+1; i++)
	{
		printf("%d \n", i);
		strcpy((pa + i),*pn);
		
	}
	*/
	
	 
	
	

	 //주소값

	
	
	
	
	//006FF7DB
}

