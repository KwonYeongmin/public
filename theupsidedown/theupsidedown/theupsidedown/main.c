#pragma once
#include "main.h"

int main() 
{
	//ũ�� ����
	system("mode con cols=140 lines=50");
	system("title The upsidedown");

	//�뷡
	PlaySound(TEXT("..\\data\\strangerthings.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	//����ü �ʱ�ȭ
	init_info();
	init_list();
	
	//����
	sceneManager(0);
	
	//�ΰ���
	//game_set();

	return 0;
}

void sceneManager(int sceneNum) 
{
	int index;
	index = sceneNum;
	char guide[120] = "zŰ�� ������ ���� ȭ������ �Ѿ�ϴ�.";
	char guide_[200] = "ZŰ�� ������ ������ �ٽ� ������ �� �ֽ��ϴ�.\n \t\t\t\t\t\t\t\t QŰ�� ������ ������ �����մϴ�.";

	//����ü ��������
//	struct cur_player_info cur_player;

	
	if (index == 0)
	{
		outgame_table();
		
		outgame_content(0, guide, 30);
		if (keyboard_input() == NEXT) {
			sceneManager(1);
		}
	}
	else if (index == 1)
	{
		double_buf();
		outgame_table();
		outgame_content(1, guide, 30);
		if (keyboard_input() == NEXT) {
			sceneManager(2);
		}
	}
	else if (index == 2)
	{
		double_buf();
		outgame_table();
		outgame_content(2, guide, 30);
		if (keyboard_input() == 122) { sceneManager(3); }
	}
	else if (index == 3)
	{
		double_buf();
		game_set();
		
		//printf("�ΰ���");
	}
	else if (index == 4)
	{
		double_buf();
		outgame_table();
		outgame_content(4, guide, 30);
		if (keyboard_input() == 122) {
			index++; sceneManager(5);
		}
	}
	else if (index == 5)
	{
		double_buf();
		strcpy(guide, guide_);
		outgame_table();
		outgame_content(5, guide, 30);
		if (keyboard_input() == 122) { sceneManager(0); }
		else if (keyboard_input() == 113) { return 0; }
	}

}

int keyboard_input()
{

	char c;
	for (;;) {
		c = _getch();
		if (c == NEXT)
		{
			return c;
		}
		else if (c == 'q')
		{
			return c;
		}
	}
}