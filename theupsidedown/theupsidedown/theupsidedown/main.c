#pragma once
#include "main.h"

int main() 
{
	//크기 지정
	system("mode con cols=140 lines=50");
	system("title The upsidedown");

	//노래
	PlaySound(TEXT("..\\data\\strangerthings.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	//구조체 초기화
	init_info();
	init_list();
	
	//시작
	sceneManager(0);
	
	//인게임
	//game_set();

	return 0;
}

void sceneManager(int sceneNum) 
{
	int index;
	index = sceneNum;
	char guide[120] = "z키를 누르면 다음 화면으로 넘어갑니다.";
	char guide_[200] = "Z키를 누르면 게임을 다시 시작할 수 있습니다.\n \t\t\t\t\t\t\t\t Q키를 누르면 게임을 종료합니다.";

	//구조체 가져오기
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
		
		//printf("인게임");
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