#pragma once
#include "main.h"


//������ ����

void input_record()
{
	FILE *info_fp;
	info_fp = fopen("..\\data\\cur.txt", "wb");
	fprintf(info_fp, "%d", g_info.score);
	fprintf(info_fp, "%c", '\n');
	fclose(info_fp);
}


//������
void rank_system()
{

}

//��ũ�� ������ ���
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

//���� �÷��̾� ���� ��ϰ� ���ϱ�
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

  //�ʱ�ȭ
FILE *ifp,*ofp;
int max_score;

  //����ü�ʱ�ȭ
struct player_list list[5];
list[0].score=50;
list[0].rank=0;

Info info;
info.cur_score=10;
//���̳ʸ� ���� �ؽ�Ʈ�� ���?, ��ŷ �ű�� ��� ?
//���� ����
ifp = fopen("a.txt", "wb");
ofp = fopen("b.txt", "wb");
//���� �ݺ�
int i = 0;
for ( i = 0; i < 3; i++)
{
	//�÷��̾��̸� �Է�
		printf("playername : ");
		scanf("%s",list[i].playername);
	//�÷��̾� ���� ����
	list[i].score=10+i;

	//���Ͽ� �Է�
	fwrite(&list, sizeof(list), 1, ifp); // ����ü ũ�⸸ŭ 1�� ����

	max_score = max_score > list[i].score ? max_score:list[i].score;
	}
//���� �ֱٿ� �Է��� �÷��̾� ���� ����
strcpy(info.cur_playername,list[i].playername);
info.cur_score = list[i].score;

   printf("%d \n",max_score);
  fprintf(ofp,"%d ",max_score);
	fclose(ifp); // ���Ͼ����� ����
	fclose(ofp); // ���Ͼ����� ����
//����ü�� �б�
 ifp = fopen("a.txt", "rb");
//printf("%d ",max_score);

//��ϼ����� ����
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
	������ ����
printf("����� ������ : ");
return 0;*/
//���� �ݺ�
/*
//�ְ���� b ���Ͽ� ����
ofp = fopen("a.txt","w");
fclose(ofp);

//���� �б�
ofp = fopen("a.txt","r");
fclose(ofp);

//��� �̸�, ����
printf(": \n");

//���� �б�
ofp = fopen("a.txt","r");
fclose(ofp);

//�ְ� ���� ���
printf("max score : %d\n",max_score);


}

*/