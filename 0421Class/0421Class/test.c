#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>

	//����
	//���� 11 : ���� 10�� �����ͷ� �ٲٱ� 
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

	
	//����2, ����12
/*���̰� 6�� int�� �迭�� arr�� �����ϰ� �̸� 1,2,3,4,5,6����
�ʱ�ȭ �� ����, �迭�� ����� ���� ������ 6,5,4,3,2,1��
�ǵ��� �����ϴ� ���α׷��� �ۼ�����
�� �迭�� �հ� �ڸ� ����Ű�� ������ ���� �ΰ��� �����ؼ�
�̸� Ȱ���Ͽ� ����� ���� ������ �ڹٲ�� �Ѵ�.
*/
//�ּҴ� ù��° �ּ�
//�����ʹ� ��

		//����
/*
int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
//������ ���� ������ ���ؼ� �ٲ��ֱ�
	int *pf = arr;
	int *pb = arr + 5;
	int temp;
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int m = 0; m < size; m++)
	{
		temp = *(pf + m);
		*(pf + m)= *(pb - m); //�ٷ� ��������°Ŵ� ����
		*(pb - m) = temp;
	}for (int i = 0; i < 6; i++)
	{
		printf("arr[%d] : %d \n",i,arr[i]);
	}
	}
*/


	
	
	

	//p292
	//����, ���� 13
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
		printf("��ȣ �Է� : ");
		scanf("%d", lotto_nums);

		for (int j = 0; j <  j< size; j++)
			{

			if(i > 0)
			{
				if (*(lotto_nums + i) == *(lotto_nums + j))
				{
					printf("���� ��ȣ�� �ֽ��ϴ�! \n");
					//printf("%d \n", *(lotto_nums + i));
					break;
				}
				else
				{
					count++;
					//printf("����Ǿ����� %d \n", count);
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
		printf("�ζ� ��ȣ");
	}

}
*/

	//����, ����14
	//�Է��� ������ ���� �����ϱ�
	//���� ���Ͽ� �� ū ������ ���� ���ܳ���
	//����� ���� ����ϱ�
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
		//�������ڿ� �ι��� �־��ֱ�
		len = count > len ? count : len;
		//while������ ������ Ȯ�����ֱ�
	}
	printf("%d", len);
	}
*/





//�ǽ��غ���

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

	printf("���� ���ڿ� : %s \n", str1);
	strcpy(str1, str2);
	printf("�ٲ� ���ڿ� : %s \n", str1);

	strcpy(str1, ps1);
	printf("�ٲ� ���ڿ� : %s \n", str1);

	strcpy(str1, ps2);
	printf("�ٲ� ���ڿ� : %s \n", str1);

	strcpy(str1, "banana");
	printf("�ٲ� ���ڿ� : %s \n", str1);
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

//��ġ�� ũ�� �˾ƺ���
//���� ã���� �ϴ� �ܾ ����ִ��� ã�� �� ����
/*
void main()
{
	char szBuf[32] = { "I am a boy." };
	printf("%p \n", szBuf);

	printf("%p \n", strstr(szBuf, "am"));
	printf("%p \n", strstr(szBuf,"boy"));
}
*/





		//�Լ�������ֱ�

//char *my_strcpy(char *pd, char *ps);
//char *my_strcat(char *pd, char *ps);
//char my_strlen(char *ps);
//char my_strcmp( char *pa, char *pb);


/*
int main()
{
		//strcpy �����
	/*
	char ch[100] = "strawberry";

	printf("�ٲٱ� �� ���ڿ� : %s \n",ch);
	*my_strcpy(ch,"apple");
	printf("�ٲ� �� ���ڿ� : %s \n", ch);
	*my_strcpy(ch, "kiwi");
	printf("�ٸ� ���ڿ� : %s \n", ch);
	*/
	
	//strcat�Լ� �����

	//strlen�Լ� �����
	
	//strcmp�Լ� �����


	
//strcpy �����
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

	return pd; //�ּҸ� ����
	
//char *po = pd; // �����ص���

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


//strcat�Լ� �����
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

//strlen�Լ� �����
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



//����
//boy�� girl�� �ٲٱ�
//���ڸ� ã�Ƽ� �ٲٴ� �ɷ� �Լ��� �����
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
	
	 
	
	

	 //�ּҰ�

	
	
	
	
	//006FF7DB
}

