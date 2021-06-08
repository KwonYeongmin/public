#pragma once
#include "main.h"
#include  "random_map.h"

int PosX;
int PosY;
int num[4];
int unite_map[44][44];

int monster_x[4] = { 33, 33, 77, 77 };
int monster_y[4] = { 14, 36, 14, 36 };
int dir = 1;

clock_t g_start;
int g_limit =200;

void game_set()
{
	g_start = clock();
	g_start = 100;

	game_setting();
	monster_move();

	while (1)
	{
		character_move();
		earn_score();
		timer();
		//성공
		if (success() == SUCCESS)
		{
			//점수저장, 점수비교
			input_record();
			sceneManager(4);
			break;
		}
		//실패

		if (fail() == FAIL )
		{
			input_record();
			sceneManager(4);
			break;
		}
	}
	game_set();

}



//셋팅
void game_setting()
{
	//g_info.score = 0;
	ingame_table(g_info.timer, g_info.cur_playername, g_info.timer);
	drawing_map();
	character_setting();
}

void character_setting()
{
	//플레이어
	PosX = 11; PosY = 3;
	gotoxy(PosX, PosY);
	setColor(4);
	printf("●");

	monster_x[0] = 33; monster_y[0] = 14;
	monster_x[1] = 33; monster_y[1] = 36;
	monster_x[2] = 77; monster_y[2] = 14;
	monster_x[3] = 77; monster_y[3] = 36;


	//몬스터
	setColor(2);
	gotoxy(monster_x[0], monster_y[0]);
	printf("★");
	setColor(2);
	gotoxy(monster_x[1], monster_y[1]);
	printf("★");
	setColor(2);
	gotoxy(monster_x[2], monster_y[2]);
	printf("★");
	setColor(2);
	gotoxy(monster_x[3], monster_y[3]);
	printf("★");
}

//맵그리기
void drawing_map()
{
	//난수 생성
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		num[i] = rand() % 3;
	}

	//새로운 배열에 저장
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			unite_map[i][j] = randomMap[num[0]][i][j];
			unite_map[i][j + 22] = randomMap[num[1]][i][j]; //1,0
			unite_map[i + 22][j] = randomMap[num[2]][i][j]; //0,1
			unite_map[i + 22][j + 22] = randomMap[num[3]][i][j]; //1,1
		}

	}

	//맵그리기
	for (int i = 0; i < 44; i++)
	{
		for (int j = 0; j < 44; j++)
		{
			gotoxy(11 + j * 2, 3 + i);
			if (unite_map[i][j] == EMPTY) { printf("  "); }
			else if (unite_map[i][j] == WALL) { setColor(9); printf("▩"); }
			else if (unite_map[i][j] == LIGHT) { setColor(14);  printf("▲"); }
			else if (unite_map[i][j] == MONSTER) { printf("※"); }
		}
		printf("\n");
	}

}

//캐릭터 이동
void character_move()
{
	int dir = 1;
	if (_kbhit())
	{
		// 캐릭터 지우기
		gotoxy(PosX, PosY);
		printf("  ");


		//키보드 입력
		switch (_getch())
		{
		case LEFT:
			while(1)
			{ 
			PosX -= 2; 
			if ((unite_map[(PosY - 3) % 44][((PosX - 11) % 88) / 2 -1] == WALL) || (PosX <= 11)) { break; }
			}
		case RIGHT:
			while (1)
			{
				PosX += 2; 
				if ((unite_map[(PosY - 3) % 44][((PosX - 11) % 88) / 2 + 1] == WALL) || (PosX >= 97)) { break; }
			}
		case UP:
			if ((unite_map[(PosY - 3) % 44 - 1][((PosX - 11) % 88) / 2] == WALL) || (PosY <= 3)) { break; }
			PosY--;
			break;
		case DOWN:
			if ((unite_map[(PosY - 3) % 44 + 1][((PosX - 11) % 88) / 2] == WALL) || (PosY >= 46)) { break; }
			PosY++;
			break;
		}

		setColor(4);
		gotoxy(PosX, PosY);
		printf("●");

	

		monster_move();
		gotoxy(120,48);
		printf("%d,%d",PosX,PosY);
	}

}

//플레이어 움직임으로 결과
//성공
int success()
{

	if ((PosX == 97) && (PosY == 46))
	{
		return SUCCESS;
	}
}

//점수 얻기
void earn_score()
{
	//gotoxy(110, 42);  printf("%5d", g_info.score);
	if (unite_map[(PosY - 3) % 44][((PosX - 11) % 88) / 2] == LIGHT)
	{
		unite_map[(PosY - 3) % 44][((PosX - 11) % 88) / 2] = EMPTY;
		g_info.score++;
	}
	setColor(15);
	gotoxy(110, 42);  printf("%5d", g_info.score);
}

//캐릭터 죽기 => 점수 저장안됨
int fail()
{
	//몬스터랑 부딪혀서 죽기
	for (int i = 0; i < 4; i++)
	{
		if ((monster_x[i] == PosX) && (monster_y[i] == PosY))
		{
			return FAIL;
		}
	}

}



//타이머
int timer()
{
	g_info.timer = (clock() - g_start) / CLOCKS_PER_SEC;
	setColor(15);
	gotoxy(115, 19);   
	printf("%2d", g_info.timer);
	

	if (g_info.timer > g_limit) { return FAIL; }

}



//몬스터
//몬스터 움직이기()
void monster_move()
{

	if (_kbhit()) {
		for (int i = 0; i < 4; ++i) {
			
			//기존 이미지 지우기
			gotoxy(monster_x[i], monster_y[i]);
			printf("  ");
			
			if (abs(monster_x[i] - PosX) < 8 && abs(monster_y[i] - PosY) < 4)
			{
				monster_closer(i, i);
			}
			else 
			{
				monster_pattern(i, i);
			}
					
			gotoxy(monster_x[i], monster_y[i]);
			setColor(2);
			printf("★");

		}
	}

}

void monster_pattern(int x, int y)
{
	while (1) 
	{
		int monster_num;                                
		int move_ck = 0;

		int monster_x_pos = ((monster_x[x] - 11) % 88) / 2;
		int monster_y_pos = (monster_y[y] - 3) % 44;
		monster_num = rand() % 4;

		switch (monster_num)
		{
		case 0:
			if ((unite_map[monster_y_pos][monster_x_pos + 1] == WALL) || (monster_x[x] >= 97)) break;
			else {
				monster_x[x] += 2;
				move_ck = 1;
				break;
			}

		case 1:
			if ((unite_map[monster_y_pos][monster_x_pos - 1] == WALL) || (monster_x[x] <= 11)) break;
			else {
				monster_x[x] -= 2;
				move_ck = 1;
				break;
			}

		case 2:
			if ((unite_map[monster_y_pos - 1][monster_x_pos] == WALL) || (monster_y[y] <= 3)) break;
			else {
				monster_y[y] --;
				move_ck = 1;
				break;
			}

		case 3:
			if ((unite_map[monster_y_pos + 1][monster_x_pos] == WALL) || (monster_y[y] >= 46)) break;
			else {
				monster_y[y] ++;
				move_ck = 1;
				break;
			}

		}
		//몬스터 좌표 디버깅
		/*
		gotoxy(110, 48);
		printf("(%d,%d),%d, %d, %d", monster_x[x], monster_y[y], x, y, move_ck);
		*/
		if (move_ck==1) break;
	}
}

void monster_closer(int x, int y)
{
	
	int abs_ck;
	if (monster_x[x] > PosX ) { abs_ck = 0; }
	else if (monster_x[x] <= PosX) { abs_ck = 1; }
	else if (monster_y[y] > PosY) { abs_ck = 2; }
	else if (monster_y[y] <= PosY) { abs_ck = 3; }
	
	switch (abs_ck) 
	{
	case 0: 
		if ((unite_map[((monster_x[x] - 11) % 88) / 2][(monster_y[y] - 3) % 44 - 1] == WALL) || (monster_x[x]<= 11 )) break;
		monster_x[x] -= 2; 
		break;
	case 1:
		if ((unite_map[((monster_x[x] - 11) % 88) / 2][(monster_y[y] - 3) % 44 +1] == WALL) || (monster_x[x]>= 97 )) break;
		monster_x[x] += 2; 
		break;
	case 2:
		if ((unite_map[((monster_x[x] - 11) % 88) / 2 -1][(monster_y[y] - 3) % 44 ] == WALL) || (monster_y[y] <= 3 )) break;
		monster_y[y] --;
		break;
	case 3:
		if ((unite_map[((monster_x[x] - 11) % 88) / 2 + 1][(monster_y[y] - 3) % 44] == WALL) || (monster_y[y]>= 46)) break;
		monster_y[y] ++;
		break;
	
	}
	
}

