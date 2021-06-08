#include "main.h"



//현재 플레이어 이름, 현재 플레이어 스코어 저장
// 이전의 플레이어들과 비교해서 랭킹 매기기
// 5명만 보여주기

//현재 플레이어 정보 저장하기: 이름, 스코어
//플레이어 리스트에 저장하기: 이름, 스코어
void input_record() 
{
	FILE *info_fp;
	FILE *list_fp;
	info_fp = fopen("..\\data\\cur.txt", "wb");
	list_fp = fopen("..\\data\\list.txt", "wb");
	fprintf(info_fp, "%s %d", g_info.cur_playername, g_info.score);
	fclose(info_fp);
	fprintf(list_fp, "%s %d", g_info.cur_playername,g_info.score);
	//fputc('\n');
	fclose(list_fp);
}

//플레이어 리스트에 저장한 플레이어 랭킹 매기기
//5명만 출력하기 : 랭킹 이름 스코어 
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

//가장높은 점수 출력