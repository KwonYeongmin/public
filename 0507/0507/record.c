#include "main.h"



//���� �÷��̾� �̸�, ���� �÷��̾� ���ھ� ����
// ������ �÷��̾��� ���ؼ� ��ŷ �ű��
// 5�� �����ֱ�

//���� �÷��̾� ���� �����ϱ�: �̸�, ���ھ�
//�÷��̾� ����Ʈ�� �����ϱ�: �̸�, ���ھ�
//�÷��̾� ����Ʈ�� ������ �÷��̾� ��ŷ �ű��
//5�� ����ϱ� : ��ŷ �̸� ���ھ� 

void input_record()
{
	/*
	FILE *info_fp;
	FILE *list_fp;
	info_fp = fopen("..\\data\\cur.txt", "wb");
	list_fp = fopen("..\\data\\list.txt", "wb");
	fprintf(info_fp, "%s %d", g_info.cur_playername, g_info.score);
	fclose(info_fp);
	fprintf(list_fp, "%s %d", g_info.cur_playername, g_info.score);
	//fputc('\n');
	fclose(list_fp);
	*/
//	test();
}


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

//������� ���� ���

void test() 
{

	//�ʱ�ȭ
	int max_score = 0;

	FILE *info_fp;
	FILE *list_fp;
	info_fp = fopen("..\\data\\cur.txt", "wb");
	list_fp = fopen("..\\data\\list.txt", "wb"); //

	//fwrite(&list, sizeof(list), 1, ifp); // ����ü ũ�⸸ŭ 1�� ����
	fwrite(&g_info, sizeof(g_info), 1, info_fp); // ����ü ũ�⸸ŭ 1�� ����

	
	g_list->max_score = g_list->max_score > g_info.score ? g_list->max_score : g_info.score;
	


	//printf("%d \n", max_score);
	fprintf(list_fp, "%d ", g_list->max_score);
	fclose(info_fp); // ���Ͼ����� ����
	fclose(list_fp); // ���Ͼ����� ����

}