#pragma once
#include "main.h"


//데이터 저장

void input_record()
{
	FILE *info_fp;
	info_fp = fopen("..\\data\\cur.txt", "wb");
	fprintf(info_fp, "%d", g_info.score);
	fprintf(info_fp, "%c", '\n');
	fclose(info_fp);
}


//점수비교
void rank_system()
{

}

//랭크된 데이터 출력
void output_records()
{
	FILE *fp;
	fp = fopen("..\\data\\list.txt", "rb");
	if (fp == NULL)
	{
		printf("X");
		//return 1;
	}
	fclose(fp);
}

//현재 플레이어 점수 기록과 비교하기
void compare_score() 
{
	FILE *fp;
	fp = fopen("..\\data\\list.txt", "rb");
	if (fp == NULL)
	{
		printf("X");
		//return 1;
	}

	fclose(fp);
}

/*
typedef struct player_list
{
	char playername[80];
	int score;
	int rank;
} ;

typedef struct cur_info
{
	char cur_playername[80];
	int cur_score;
} Info;

int main()
{

  //초기화
FILE *ifp,*ofp;
int max_score;

  //구조체초기화
struct player_list list[5];
list[0].score=50;
list[0].rank=0;

Info info;
info.cur_score=10;
//바이너리 말고 텍스트로 어떻게?, 랭킹 매기기 어떻게 ?
//파일 열기
ifp = fopen("a.txt", "wb");
ofp = fopen("b.txt", "wb");
//세번 반복
int i = 0;
for ( i = 0; i < 3; i++)
{
	//플레이어이름 입력
		printf("playername : ");
		scanf("%s",list[i].playername);
	//플레이어 점수 저장
	list[i].score=10+i;

	//파일에 입력
	fwrite(&list, sizeof(list), 1, ifp); // 구조체 크기만큼 1개 쓰기

	max_score = max_score > list[i].score ? max_score:list[i].score;
	}
//가장 최근에 입력한 플레이어 정보 저장
strcpy(info.cur_playername,list[i].playername);
info.cur_score = list[i].score;

   printf("%d \n",max_score);
  fprintf(ofp,"%d ",max_score);
	fclose(ifp); // 파일쓰기모드 종료
	fclose(ofp); // 파일쓰기모드 종료
//구조체로 읽기
 ifp = fopen("a.txt", "rb");
//printf("%d ",max_score);

//기록순으로 저장
	for(int i=0;i<3;i++){
	printf("%s %d\n", list[i].playername,list[i].score);
	}
	//if(list[0].score>list[1].score){ printf("%d \n",list.score);}


	fclose(ifp);
/*
ifp = fopen("b.txt", "rb");
fread(&max_score,sizeof(max_score),1,ofp);
//printf("%d \n",max_score);
	fclose(ifp);
	점수만 저장
printf("당신의 점수는 : ");
return 0;*/
//세번 반복
/*
//최고수만 b 파일에 저장
ofp = fopen("a.txt","w");
fclose(ofp);

//파일 읽기
ofp = fopen("a.txt","r");
fclose(ofp);

//출력 이름, 점수
printf(": \n");

//파일 읽기
ofp = fopen("a.txt","r");
fclose(ofp);

//최고 점수 출력
printf("max score : %d\n",max_score);


}

*/