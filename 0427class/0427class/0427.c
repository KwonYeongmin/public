#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void print_str(char **ps);
/*
int main() 
{
	
	//p466
	//�Է��� ���� �޾����� Ȯ���ϱ�
	char temp[80];
	char *str[21] = { 0 };
	int i = 0;

	while (i<20) 
	{
		printf("���ڿ��� �Է��ϼ���: ");
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

		//���� p473
	//int *pa;
	//����������


		//���� p474
	
	int num,j,i,count=0;
	char temp_Pnum[100];
	char *PNum_row[5];
	char *PNum_col;
	printf("��� �Է� : ");
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

//p477 ����ü
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

	printf("�й� : %d \n", s1.num);
	printf("���� : %.1lf \n", s1.grade);
	printf("%d \n", sizeof(s1.num));
	printf("%d \n", sizeof(s1.grade));
	printf("%d \n",sizeof(s1));

	return 0;
}*/
/*
//�迭�� �����͸� ����� ���� ����ü
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
	strcpy(yuni.name,"������");
	yuni.age = 17;
	yuni.height = 64.5;

	yuni.intro = (char*)malloc(80);
	printf("�ڱ�Ұ� :");
	get(yuni.intro);

	printf("�̸� : %s \n", yuni.name);
	printf("���� : %s \n", yuni.age);
	printf("Ű : %s \n", yuni.height);
	printf("�ڱ�Ұ� : %s \n", yuni.intro);
	free( yuni.intro);
	return 0;
}*/
/*
p483
//�迭�� �����͸� ����� ���� ����ü

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

	printf("���� : %d\n", yuni.pf.age);
	printf("Ű : %0.1lf\n", yuni.pf.height);
	printf("�й� : %d\n", yuni.id);
	printf("���� : %.1lf\n", yuni.grade);
	return 0;
}*/

//p485
//����ü������ �ʱ�ȭ�� ���Կ���
/*
struct student
{
	int id;

	char name[20];
	double grade;
};
int main() 
{
	struct student s1 = { 315,"ȫ�浿",2.4 }
		, s2 = { 315,"ȫ�浿",2.4 }
	, s3 = { 315,"ȫ�浿",2.4 };
	
	struct student max;

	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s2.grade > max.grade) max = s3;

	printf("�й� : %d\n", max.id);
	printf("�̸� : %s\n", max.name);
	printf("���� : %.1lf\n",max.grade);

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
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ���: ");
	scanf("%d", &crack.price);
	scanf("%d",&crack.calories);

	printf("�ٻ���� ���� :%d �� \n", crack.price);	
	printf("�ٻ���� ���� :%d kcal \n",crack.calories);
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

	printf("����: %d \n", (*ps).kor);
	printf("����: %d \n", ps->eng);
	printf("����: %d \n",ps->mat);

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