#pragma once
#include "main.h"

struct cur_player_info g_info;
struct  record_list g_list[5];

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
/*
 ���� 0          �Ͼ� 15
 ��ο� �Ķ� 1 �Ķ� 9
 ��ο� �ʷ� 2 �ʷ� 10
 ��ο� �ϴ� 3 �ϴ� 11
 ��ο� ���� 4 ���� 12
 ��ο� ���� 5 ���� 13
 ��ο� ��� 6 ��� 14
 ȸ�� 7 ��ο� ȸ�� 8
*/

void init_info()
{
	strcpy(g_info.cur_playername, "");
	g_info.score = 0;
	g_info.timer = 0;
}

void init_list()
{
	strcpy(g_list[0].players_name, "");
	g_list[0].max_score = 500;
	g_list[0].rank = 0;
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void double_buf()
{
	system("cls");
}


void outgame_table()
{
	//first_box
	setColor(9);
	gotoxy(9, 4); for (int i = 0; i < 60; i++) printf("��");
	for (int i = 5; i < 9; i++) { gotoxy(9, i);  printf("��"); }
	for (int i = 5; i < 9; i++) { gotoxy(127, i);  printf("��"); }
	gotoxy(9, 9); for (int i = 0; i < 60; i++) printf("��");


	//second_box
	setColor(9);
	gotoxy(9, 14); for (int i = 0; i < 60; i++) printf("��");
	for (int i = 15; i < 34; i++) { gotoxy(9, i);  printf("��"); }
	for (int i = 15; i < 34; i++) { gotoxy(127, i);  printf("��"); }
	gotoxy(9, 34); for (int i = 0; i < 60; i++) printf("��");


	//����° ��
	setColor(9);
	gotoxy(9, 39); for (int i = 0; i < 60; i++) printf("��");
	for (int i = 40; i < 44; i++) { gotoxy(9, i);  printf("��"); }
	for (int i = 40; i < 44; i++) { gotoxy(127, i);  printf("��"); }
	gotoxy(9, 44); for (int i = 0; i < 60; i++) printf("��");
}


void outgame_content(int index, char *third, int second_line)
{
	gotoxy(55, 7);	setColor(15); first_box(index);
	gotoxy(57, second_line);	setColor(15); second_box(index);
	gotoxy(50, 42);	setColor(15); 	printf("%s", third);
}


void menu_first() 
{
	//ù��° �ڽ�
	gotoxy(55, 7);	setColor(15);
	printf("highScore : %10d", g_list[0].max_score);
	
	//�ι�° �ڽ�
	setColor(15);
	//gotoxy(57, 15); printf() {}
	printf("The upsidedown");
	
	//ù��° �ڽ�
}

void *first_box(int index)
{
	if (index == 0, 1) //ȭ��1, ȭ��2
	{
		printf("highScore : %10d", g_list[0].max_score);
	}
	else if (index == 2, 4, 5) //ȭ��3,5,6
	{
		printf("%s", g_info.cur_playername);
	}
	return 0;
}

void second_box(int index)
{
	char temp[80] = "";

	if (index == 0)
	{
		printf("The upsidedown");
	}
	else if (index == 1)
	{
		printf("player name : ");
		scanf("%s", temp);
		strcpy(g_info.cur_playername, temp);
	}
	else if (index == 2)
	{
		printf("���� ����");
	}
	else if (index == 4)
	{
		printf("score : %d \n", g_info.score);
		printf("\t\t\t\t\t\tgameOver !");
	}
	else if (index == 5)
	{
		//���� ��� �Լ�
		printf("���� �����ֱ�");
	}
}



void ingame_table()
{

	//���̺� ũ�� 90X90
	//�� ũ�� 88X88
	//2ĭ�� ������
	setColor(9);
	gotoxy(9, 2); for (int i = 0; i < 46; i++) printf("��");
	for (int i = 3; i < 47; i++) { gotoxy(9, i);  printf("��"); }
	for (int i = 3; i < 47; i++) { gotoxy(99, i);  printf("��"); }
	gotoxy(9, 47); for (int i = 0; i < 46; i++) printf("��");

	//player_box
	setColor(9);
	gotoxy(107, 3); for (int i = 0; i < 12; i++) printf("��");
	for (int i = 4; i < 10; i++) { gotoxy(107, i);  printf("��"); }
	for (int i = 4; i < 10; i++) { gotoxy(129, i);  printf("��"); }
	gotoxy(107, 10); for (int i = 0; i < 12; i++) printf("��");
	gotoxy(110, 5);  setColor(15); printf(" playername : ");
	gotoxy(110, 8);  printf(" %10s", g_info.cur_playername);

	//timer_box
	setColor(9);
	gotoxy(107, 14); for (int i = 0; i < 12; i++) printf("��");
	for (int i = 15; i < 21; i++) { gotoxy(107, i);  printf("��"); }
	for (int i = 15; i < 21; i++) { gotoxy(129, i);  printf("��"); }
	gotoxy(107, 21); for (int i = 0; i < 12; i++) printf("��");
	gotoxy(110, 16);  setColor(15); printf(" timer : ");
	//gotoxy(110, 19);   printf(" %5d", g_info.timer);

	//highscore_box
	setColor(9);
	gotoxy(107, 25); for (int i = 0; i < 12; i++) printf("��");
	for (int i = 26; i < 32; i++) { gotoxy(107, i);  printf("��"); }
	for (int i = 26; i < 32; i++) { gotoxy(129, i);  printf("��"); }
	gotoxy(107, 32); for (int i = 0; i < 12; i++) printf("��");
	gotoxy(110, 27);  setColor(15); printf(" high score : ");
	gotoxy(110, 30);  printf(" %5d", g_list[0].max_score);

	//score_box
	setColor(9);
	gotoxy(107, 37); for (int i = 0; i < 12; i++) printf("��");
	for (int i = 38; i < 44; i++) { gotoxy(107, i);  printf("��"); }
	for (int i = 38; i < 44; i++) { gotoxy(129, i);  printf("��"); }
	gotoxy(107, 44); for (int i = 0; i < 12; i++) printf("��");
	gotoxy(110, 39);  setColor(15); printf(" score : ");
	//gotoxy(110, 42);  printf("%5d", g_info.score);
}



//����ȭ��
int end_screen()
{
	double_buf();
	printf("�����մϴ�\n");
	return 0;
}