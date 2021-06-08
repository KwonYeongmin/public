#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void print_str(char **ps);
/*
int main() 
{
	
	//p466
	//입력을 세개 받았을때 확인하기
	char temp[80];
	char *str[21] = { 0 };
	int i = 0;

	while (i<20) 
	{
		printf("문자열을 입력하세요: ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);
	
	for (i = 0;  str[i] != NULL; i++) 
	{ 
		free(str[i]); 
	}

		//문제 p473
	//int *pa;
	//이중포인터


		//문제 p474
	
	int num,j,i,count=0;
	char temp_Pnum[100];
	char *PNum_row[5];
	char *PNum_col;
	printf("양수 입력 : ");
	scanf("%d",&num);

	for (j = 2; j <= num; j++) 
	{
		for (i = 2; i < j;i++) 
		{
			if (j%i == 0) temp_Pnum[j-2] = 'X'; 
		}
		if (i == j) 
		{
			temp_Pnum[j-2] = i;
			count++;
		}
	}
	for (int m = 0; m < num-1; m++) 
	{
		printf("%d \n",temp_Pnum[m]);
	}
	
	
	int n = 0;
	while (n<num-1)
	{
		if (n != temp_Pnum[n]) 
		{
			//*PNum_row[5] *PNum_row[n] = 'X';
		}
		PNum_col = (int*)malloc((num / 5));
		
		n++;
	}
	
	return 0;




	
}

*/










/*
void print_str(char **ps) 
{
	while (*ps != NULL) 
	{
		printf("%s\n", *ps);
		ps++;
	}
}*/

//p477 구조체
/*
struct student
{
	int num;
	double grade;
};
int main() 
{
	struct student s1;
	
	s1.num = 2;
	s1.grade = 2.7;

	printf("학번 : %d \n", s1.num);
	printf("학점 : %.1lf \n", s1.grade);
	printf("%d \n", sizeof(s1.num));
	printf("%d \n", sizeof(s1.grade));
	printf("%d \n",sizeof(s1));

	return 0;
}*/
/*
//배열과 포인터를 멤버로 갖는 구조체
p481

struct profile
{
	char name[20];
	int age;
	double height;
	char *intro;
};

int main() 
{
	struct profile yuni;
	strcpy(yuni.name,"서하윤");
	yuni.age = 17;
	yuni.height = 64.5;

	yuni.intro = (char*)malloc(80);
	printf("자기소개 :");
	get(yuni.intro);

	printf("이름 : %s \n", yuni.name);
	printf("나이 : %s \n", yuni.age);
	printf("키 : %s \n", yuni.height);
	printf("자기소개 : %s \n", yuni.intro);
	free( yuni.intro);
	return 0;
}*/
/*
p483
//배열과 포인터를 멤버로 갖는 구조체

struct profile 
{
	int age;
	double height;
};
struct student 
{
	struct profile pf;
	int id;
	double grade;
};

int main() 
{
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이 : %d\n", yuni.pf.age);
	printf("키 : %0.1lf\n", yuni.pf.height);
	printf("학번 : %d\n", yuni.id);
	printf("학점 : %.1lf\n", yuni.grade);
	return 0;
}*/

//p485
//구조체변수의 초기화와 대입연산
/*
struct student
{
	int id;

	char name[20];
	double grade;
};
int main() 
{
	struct student s1 = { 315,"홍길동",2.4 }
		, s2 = { 315,"홍길동",2.4 }
	, s3 = { 315,"홍길동",2.4 };
	
	struct student max;

	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s2.grade > max.grade) max = s3;

	printf("학번 : %d\n", max.id);
	printf("이름 : %s\n", max.name);
	printf("학점 : %.1lf\n",max.grade);

	return 0;

}*/
//p488
/*
struct vusion exchange(struct vusion robot);
int main(int argc,char **argv)
{
	struct vusion robot;

	return 0;
}

struct cracker 
{
	int price;
	int calories;
};

int main() 
{
	struct cracker crack;
	printf("바사삭의 가격과 열량을 입력하세요: ");
	scanf("%d", &crack.price);
	scanf("%d",&crack.calories);

	printf("바사삭의 가격 :%d 원 \n", crack.price);	
	printf("바사삭의 열량 :%d kcal \n",crack.calories);
}*/
/*p493
struct score
{
	int kor, eng, mat;
};

int main() 
{
	struct score yuni = { 90,80,70 };
	struct score *ps = &yuni;

	printf("국어: %d \n", (*ps).kor);
	printf("영어: %d \n", ps->eng);
	printf("수학: %d \n",ps->mat);

	return 0;
}*/

//p495
/*
struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

int main() 
{
	//struct address ad;
	
	struct  address list[5];

	for (int k=0;k<5;k++) 
	{
		gets(list[k].name);
		scanf("%d", &list[k].age);
		gets(list[k].tel);
		gets(list[k].addr);
		}

	int i;
	for (i = 0; i < 5; i++) 
	{
		printf("%10s%5d%15s%20s \n", 
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
}*/
//p497
/*
struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

int main()
{
	//struct address ad;

	struct  address list[5];

	for (int k=0;k<5;k++)
	{
		gets(list[k].name);
		scanf("%d", &list[k].age);
		gets(list[k].tel);
		gets(list[k].addr);
		}

	
}

void print_list(struct address *lp) 
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s \n",
			(lp+i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
	}
}*/
/*
p500
*/
//p504