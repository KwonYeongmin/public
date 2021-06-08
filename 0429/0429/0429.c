#define _CRT_SECURE_NO_WARNINGS
#define PRINTT_EXPR(x) printf(#x " =%d\n",x)

//---------------------------------------------------
#include <stdio.h>
#include <string.h>
#include "student.h"

//---------------------------------------------------

void fileopen_read(char *filename);
void fileopen_write(char *filename);
void file(char *filename);
void file_(char *filename);
void file__(char *filename1, char *filename2); //p539 //�̰� �� �ȵǴ����𸣰���
void file___(char *filename1, char *filename2); //p543
void quiz1(char *filename1, char *filename2, char *filename3); //p554
void quiz2(char *filename1);
void quiz3();

//---------------------------------------------------

int main() 
{
	//file("..\\data\\a.txt");
	//file_("..\\data\\a.txt");

	//fileopen_write("..\\data\\b.txt");
	//fileopen_read("..\\data\\a.txt");

	//file__("..\\data\\a.txt", "..\\data\\b.txt");
	//file___("..\\data\\a.txt", "..\\data\\b.txt");

	//quiz1("..\\data\\a.txt", "..\\data\\b.txt", "..\\data\\c.txt");
	//quiz2("..\\data\\99.txt");
	quiz3();

	return 0;
}
void fileopen_read(char *filename) 
{
	FILE*fp;
	int ch;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}
	printf("success");
	fclose(fp);

}
void fileopen_write(char *filename)
{
	FILE*fp;
	char str[] = "banana";
	int i = 0;

	fp = fopen("filename", "w");
	if (fp == NULL)
	{
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	while (str[i]!='\0')
	{
		fputc(str[i], fp);
		i++;
	}
	
	printf("success");
	fputc('\n', fp); 
	fclose(fp);

}
void file(char *filename) 
{
	FILE *fp;
	int ary[10] = { 13,10,13,13,10,26,13,10,13,10 };
	int i, res;

	fp = fopen(filename, "wb");
	for (i = 0; i < 10; i++) 
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	//fp = fopen(filename, "rt"); //�ؽ�Ʈ�� �б�
	fp = fopen(filename, "rb"); //���̳ʸ��� �б�
	while (1) 
	{
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d",res);

	}
	fclose(fp);

	return 0;
}

void file_(char *filename) 
{
	FILE *fp;
	char str[20];

	fp = fopen("a.txt", "a+");
	if (fp == NULL) 
	{
		printf("������ ������ ���߽��ϴ�. \n");
		return 1;
	}
	while (1)
	{
		printf("���� �̸�: ");
		scanf("%s", &str);
		if (strcmp(str, "end") == 0) break;
		else if (strcmp(str, "list") == 0) 
		{
			fseek(fp, 0, SEEK_SET);
			while (1) 
			{
				fgetc(str, sizeof(str), fp);
				if (feof(fp)) 
				{
					break;
				}
				printf("%s",str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);
}
void file__(char *filename1, char *filename2)
{
	FILE*ifp, *ofp;
	char str[80];
	char *res;

	ifp = fopen(filename1, "r");
	if (ifp == NULL) 
	{
		printf("�Է�����X \n");
		return 1;
	}

	ofp = fopen(filename2, "w");
	if (ofp == NULL) 
	{
		printf("�������X \n");
		return 1;
	}

	while (1) 
	{
		res = fgetc(str, sizeof(str), ifp);
		if (res == NULL) 
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);
	fclose(ofp);
}

void file___(char *filename1, char *filename2) 
{
	FILE*ifp, *ofp;
	char name[20];
	int kor, eng, mat;
	int tot;
	double avg;
	int res;

	ifp = fopen(filename1, "r");
	if (ifp == NULL) 
	{
		printf("�Է�����X\n");
		return 1;
	}

	ofp = fopen(filename2, "w");
	if (ofp == NULL) 
	{
		printf("�������X \n");
		return 1;
	}
	while (1) 
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &mat);
		if (res == EOF) break;
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(ofp,"%s%5d%7.1lf\n",name,tot,avg);
	}
	fclose(ifp);
	fclose(ofp);
}
 



//p554
//�޸� �÷��ֱ�

void quiz1(char *filename1, char *filename2, char *filename3)
{
	FILE*ifp_1, *ifp_2, *ofp;
	char animal1[20];
	char animal2[20];
	
	int i,j;

	ifp_1 = fopen(filename1, "r");
	if (ifp_1 == NULL)
	{
		printf("�Է�����X\n");
		return 1;
	}

	ifp_2 = fopen(filename2, "r");
	if (ifp_1 == NULL)
	{
		printf("�Է�����X \n");
		return 1;
	}

	ofp = fopen(filename3, "w");
	if (ofp == NULL)
	{
		printf("�������X\n");
		return 1;
	}
/*
	int res1, res2;
	
	while (1)
	{
		res1 = fscanf(ifp_1, "%s", animal1);
		if (res1 == EOF) { break; }
		printf("%d",res1);
	}*/
		
		
	for (int k = 0; k < 10; k++)
	{
		fgets(animal1[k], 20, ifp_1);
	}
	for (int k = 0; k < 10; k++)
	{
		fgets(animal2[k], 20, ifp_2);
	}
	//printf("%d\t%d", res1, res2);
	
	//���ϱ�
	
	
	for (i = 0; i < 10; i++)
	{
		int count = 0;

		for (j = 0; j < 10; j++)
		{
			if (strcmp(animal2[i],animal1[j]) == 0)
			{
				count++;
				break;
			}
		}
		if(count==0)fprintf(ofp, "%s", animal2[i]);	
	}
		
	fclose(ifp_1);
	fclose(ifp_2);
	fclose(ofp);
}

//����2
void quiz2(char *filename1)
{
	FILE*ifp,*ofp;
	char table[80];

	//99.txt���� ����
	ifp = fopen(filename1, "w");
	if (ifp == NULL)
	{
		printf("�Է�����X \n");
		return 1;
	}


	//������ ����
	for (int i = 2; i < 10; i++) 
	{
		//fprintf(ifp, "%d��\n",i);
		for (int j = 1; j < 10; j++)
		{
			fprintf(ifp, "%2d X %2d = %2d\n", i, j, i*j); //������ ����Ʈ�� �����ֱ�
		}
	}
	//���� �ݱ�
	fclose(ifp);

	//���ϴ� ������ �Է�
	int num ;
	printf("��� ���ϴ� �������� ? ");
	scanf("%d",&num);
	
	//���� �ٽ� ����
	ifp = fopen(filename1, "r");
	//������ ���
	fgets(table, 80, ifp);
	int len = strlen(table);
	fseek(ifp, (num - 2) *(len+1)*9 , SEEK_SET);

	for (int m = 0; m < 9; m++) 
	{
		//�˻��ϴ� �ڵ�
		if (strcpy(table, "\0") == 0) { break; }
		//���̺� �б�
		fgets(table, 80, ifp);
		printf("%s", table);	
	}	
	fclose(ifp);
}


//����3
/*���Ϻ��� ���α׷� �����
������ ���ϸ�� ���� �� �����Ǵ� ���ϸ��� �Է� �޾Ƽ�
������ ������ �����ϴ� ���α׷� �ۼ�.
��, txt���ϻӸ� �ƴ϶� �̹��� ���� ���� ��� ������ ���Ͽ�
�� �����ϰ� ������ �� �־�� �Ѵ�.
���� ���� ������ ������� ȭ�鿡 ǥ�����ֵ��� �ϰ�,
�ѹ��� 4����Ʈ�� �����ϵ��� �Ѵ�.
(4����Ʈ ������ �����Ϳ� ���� ó���� �ʿ�)
ex
���� ���� : source.txt
��� ���� : dest.txt

		������ : 12%
		fseek .. ftell
*/
void quiz3()
{
	FILE *copy_fp, *paste_fp;
	
	//���� ����
	char source_fname[80];
	char dest_fname[80];
	char dir[80]= "..\\data\\";
	//�а����� ����
	char str[80];

	//������ ���ϸ� �Է�
	scanf("%s", source_fname);	
	strcat(dir, source_fname);
	copy_fp = fopen(dir, "rb");
	if (copy_fp == NULL)
	{
		printf("������ ����X \n");
		return 1;
	}

	//���� ���ϸ� �Է�, ���� ����
	strcpy(dir, "..\\data\\");
	scanf("%s", dest_fname);
	strcat(dir, dest_fname);
	paste_fp = fopen(dir, "wb");
	if (paste_fp == NULL)
	{
		printf("���� ����X \n");
		return 1;
	}
	
	int res;
	//�����б�
	while(1)
	{
		res= fgets(str, sizeof(str), copy_fp);
		
		
		if (feof(copy_fp)) 
		{
			break;
		}
		printf("%s",str);
	}

	/*
	for (int i=0;i< i++) 
	{
		fseek(copy_fp, 4*(i-1), SEEK_SET);
	}
	*/
	
	//100������ �ؼ� �����������


	//���뺹��
	
	//������̱�



	//���ϴݱ�
	fclose(copy_fp);
	fclose(paste_fp);

}
