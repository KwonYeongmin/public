
#include "main.h"

int main()
{
	//â ũ��, �̸� ����
	system("mode con cols=140 lines=50");
	system("title The upsidedown");
	//����ü �ʱ�ȭ
	//init_info();
	//init_list();
	//PlaySound(TEXT("..\\data\\strangethings.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);

	input_record();
	rank_system();
	//����
	sceneManager(0);
	

	//��ŷ �ý���
	


	//system("pause");
	return 0;
}

void sceneManager(int sceneNum)
{
	int index;
	index = sceneNum;
	char guide[120] = "zŰ�� ������ ���� ȭ������ �Ѿ�ϴ�.";
	char guide_[200] = "ZŰ�� ������ ������ �ٽ� ������ �� �ֽ��ϴ�.\n \t\t\t\t\t\t\t\t QŰ�� ������ ������ �����մϴ�.";
	
	if (index == 0)
	{
		outgame_table();
		outgame_content(0, guide, 30);
		if (keyboard_input() == 122) {
			sceneManager(1);
		}
	}
	else if (index == 1)
	{
		double_buf();
		outgame_table();
		outgame_content(1, guide, 30);
		if (keyboard_input() == 122) {
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
		set_game();
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
		else if (keyboard_input() == 113) { end_screen(); }
	}

}
int keyboard_input()
{

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
