
#include "main.h"

int main()
{
	//â ũ��, �̸� ����
	system("mode con cols=140 lines=50");
	system("title The upsidedown");
	//����ü �ʱ�ȭ
	init_info();
	init_list();
	//����
	sceneManager(0);

	//ingame_table();
	//character_set();
	//test();
	//��ŷ �ý���
	input_record();
	rank_system();

	//set_map();
	

	system("pause");
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

	char temp[80] = "mini"; //cur_player.cur_playername
	int temp_maxscore = 0; //list.max_score
	int temp_timer = 0; //cur_player.timer
	int temp_score = 0; //cur_player.score
	//while () {}
	//�б�
	if (index == 0) 
	{
		outgame_table();
		outgame_content(0, guide, 30);
		if (keyboard_input() == 122) { sceneManager(1);
		}
	}
	else if (index == 1) 
	{
		double_buf();
		outgame_table();
		outgame_content(1, guide, 30);
		if (keyboard_input() == 122) {  sceneManager(2);
		}
	}
	else if (index == 2)
	{
		double_buf();
		outgame_table();
		outgame_content(2, guide, 30);
		if (keyboard_input() == 122) {  sceneManager(3); }
	}
	else if (index == 3)
	{
		double_buf();
		set_game();
		//ingame_table(temp_timer, temp, temp_score);
		//printf("�ΰ���");
	}
	else if (index == 4) 
	{
		double_buf();
		outgame_table();
		outgame_content(4, guide, 30);
		if (keyboard_input() == 122) { index++; sceneManager(5);
		}
	}
	else if (index == 5) 
	{
		double_buf();
		strcpy(guide,guide_);
		outgame_table();
		outgame_content(5, guide, 30);
		if (keyboard_input() == 122) { sceneManager(0); }
		else if (keyboard_input() == 113) { end_screen(); }
	}

}
int keyboard_input() 
{
	/*
	for (;;) {
		if (_kbhit()) {        //Ű���� �Է� Ȯ�� (true / false)
			c = _getch();      // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
			if (c == -32) {    // -32�� �ԷµǸ�
				c = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
				switch (c) {
				case LEFT:
					return 10; // printf("�������� �̵�\n");
					break;
				case RIGHT:
					return 10; //printf("���������� �̵�\n");
					break;
				case UP:
					return 10; //printf("���� �̵�\n");
					break;
				case DOWN:
					return 10; //printf("�Ʒ��� �̵�\n");
					break;
				}
			}
		}
	}*/
	char c;
	for (;;) {
		c = _getch(); 
		if (c == 'z')
		{		
			return c;
		}
		else if (c == 'q') 
		{
			return c;
		}
	}
}




//-----------------------------------------------------------------------------------//
