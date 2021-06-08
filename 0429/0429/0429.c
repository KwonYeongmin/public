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
void file__(char *filename1, char *filename2); //p539 //이거 왜 안되는지모르겠음
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
		printf("파일이 열리지 않았습니다.\n");
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
		printf("파일이 만들지 못했습니다.\n");
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

	//fp = fopen(filename, "rt"); //텍스트로 읽기
	fp = fopen(filename, "rb"); //바이너리로 읽기
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
		printf("파일을 만들지 못했습니다. \n");
		return 1;
	}
	while (1)
	{
		printf("과일 이름: ");
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
		printf("입력파일X \n");
		return 1;
	}

	ofp = fopen(filename2, "w");
	if (ofp == NULL) 
	{
		printf("출력파일X \n");
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
		printf("입력파일X\n");
		return 1;
	}

	ofp = fopen(filename2, "w");
	if (ofp == NULL) 
	{
		printf("출력파일X \n");
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
//메모리 늘려주기

void quiz1(char *filename1, char *filename2, char *filename3)
{
	FILE*ifp_1, *ifp_2, *ofp;
	char animal1[20];
	char animal2[20];
	
	int i,j;

	ifp_1 = fopen(filename1, "r");
	if (ifp_1 == NULL)
	{
		printf("입력파일X\n");
		return 1;
	}

	ifp_2 = fopen(filename2, "r");
	if (ifp_1 == NULL)
	{
		printf("입력파일X \n");
		return 1;
	}

	ofp = fopen(filename3, "w");
	if (ofp == NULL)
	{
		printf("출력파일X\n");
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
	
	//비교하기
	
	
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

//문제2
void quiz2(char *filename1)
{
	FILE*ifp,*ofp;
	char table[80];

	//99.txt파일 생성
	ifp = fopen(filename1, "w");
	if (ifp == NULL)
	{
		printf("입력파일X \n");
		return 1;
	}


	//구구단 저장
	for (int i = 2; i < 10; i++) 
	{
		//fprintf(ifp, "%d단\n",i);
		for (int j = 1; j < 10; j++)
		{
			fprintf(ifp, "%2d X %2d = %2d\n", i, j, i*j); //한줄을 바이트로 맞춰주기
		}
	}
	//파일 닫기
	fclose(ifp);

	//원하는 구구단 입력
	int num ;
	printf("출력 원하는 구구단은 ? ");
	scanf("%d",&num);
	
	//파일 다시 열기
	ifp = fopen(filename1, "r");
	//단으로 계산
	fgets(table, 80, ifp);
	int len = strlen(table);
	fseek(ifp, (num - 2) *(len+1)*9 , SEEK_SET);

	for (int m = 0; m < 9; m++) 
	{
		//검사하는 코드
		if (strcpy(table, "\0") == 0) { break; }
		//테이블 읽기
		fgets(table, 80, ifp);
		printf("%s", table);	
	}	
	fclose(ifp);
}


//문제3
/*파일복사 프로그램 만들기
복사할 파일명과 복사 후 생성되는 파일명을 입력 받아서
파일의 내용을 복사하는 프로그램 작성.
단, txt파일뿐만 아니라 이미지 파일 등의 모든 종류의 파일에
다 동일하게 적용할 수 있어야 한다.
복사 진행 과정을 백분율로 화면에 표시해주도록 하고,
한번에 4바이트씩 복사하도록 한다.
(4바이트 이하의 데이터에 대한 처리가 필요)
ex
원본 파일 : source.txt
대상 파일 : dest.txt

		복사중 : 12%
		fseek .. ftell
*/
void quiz3()
{
	FILE *copy_fp, *paste_fp;
	
	//변수 선언
	char source_fname[80];
	char dest_fname[80];
	char dir[80]= "..\\data\\";
	//읽고복사할 파일
	char str[80];

	//복사할 파일명 입력
	scanf("%s", source_fname);	
	strcat(dir, source_fname);
	copy_fp = fopen(dir, "rb");
	if (copy_fp == NULL)
	{
		printf("복사할 파일X \n");
		return 1;
	}

	//복사 파일명 입력, 파일 생성
	strcpy(dir, "..\\data\\");
	scanf("%s", dest_fname);
	strcat(dir, dest_fname);
	paste_fp = fopen(dir, "wb");
	if (paste_fp == NULL)
	{
		printf("복사 파일X \n");
		return 1;
	}
	
	int res;
	//내용읽기
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
	
	//100나누기 해서 복사진행과정


	//내용복사
	
	//내용붙이기



	//파일닫기
	fclose(copy_fp);
	fclose(paste_fp);

}
