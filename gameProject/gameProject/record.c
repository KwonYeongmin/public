#include "main.h"



//���� �÷��̾� �̸�, ���� �÷��̾� ���ھ� ����
// ������ �÷��̾��� ���ؼ� ��ŷ �ű��
// 5�� �����ֱ�

//���� �÷��̾� ���� �����ϱ�: �̸�, ���ھ�
//�÷��̾� ����Ʈ�� �����ϱ�: �̸�, ���ھ�
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

//�÷��̾� ����Ʈ�� ������ �÷��̾� ��ŷ �ű��
//5�� ����ϱ� : ��ŷ �̸� ���ھ� 
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