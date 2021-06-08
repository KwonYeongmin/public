
#include "main.h"

int main()
{
	//창 크기, 이름 설정
	system("mode con cols=140 lines=50");
	system("title The upsidedown");
	//구조체 초기화
	init_info();
	init_list();
	//시작
	sceneManager(0);

	//ingame_table();
	//character_set();
	//test();
	//랭킹 시스템
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
	char guide[120] = "z키를 누르면 다음 화면으로 넘어갑니다.";
	char guide_[200] = "Z키를 누르면 게임을 다시 시작할 수 있습니다.\n \t\t\t\t\t\t\t\t Q키를 누르면 게임을 종료합니다.";

	//구조체 가져오기
//	struct cur_player_info cur_player;

	char temp[80] = "mini"; //cur_player.cur_playername
	int temp_maxscore = 0; //list.max_score
	int temp_timer = 0; //cur_player.timer
	int temp_score = 0; //cur_player.score
	//while () {}
	//분기
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
		//printf("인게임");
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
		if (_kbhit()) {        //키보드 입력 확인 (true / false)
			c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
			if (c == -32) {    // -32로 입력되면
				c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
				switch (c) {
				case LEFT:
					return 10; // printf("왼쪽으로 이동\n");
					break;
				case RIGHT:
					return 10; //printf("오른쪽으로 이동\n");
					break;
				case UP:
					return 10; //printf("위로 이동\n");
					break;
				case DOWN:
					return 10; //printf("아래로 이동\n");
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
