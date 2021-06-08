#include "main.h"
#include "map.h"

struct  record_list g_list[5];
struct cur_player_info g_info;


int PosX = 11;
int PosY = 3;
clock_t start, end;
//인게임 셋팅
void set_game()
{
	
	ingame_table();
	map_setting();
	
	enemy_system();
	player_move();

	//time_ck();
	start = clock();
	
	//g_info.timer = 100;
	input_record();
	
	while(1)
	{
		//update_data();
		
		end = clock();
		if ((g_info.timer == 0) || enemy_hit==3) break;
	}
	end_game(); 
}


void player_move()
{
	
	setColor(4);
	gotoxy(PosX, PosY);
	printf("●");

	while (1)
	{
		if (_kbhit())
		{
			// 캐릭터 지우기
			gotoxy(PosX, PosY);
			printf("  ");

			switch (_getch())
			{
			case LEFT:
				if (PosX <= 11) break;
				//if (ary[PosX-2][PosY]!=0) { PosX -= 2; }
				PosX -= 2;
				break;

			case RIGHT:
				if (PosX >= 96) break;
				//if (ary[PosX +2][PosY] != 0) { PosX += 2; }
				PosX += 2;
				break;

			case UP:
				if (PosY <= 3) break;
				//if (ary[PosX ][PosY-1] != 0) { PosY --; }
				PosY--;
				break;

			case DOWN:
				if (PosY >= 46)	break;
				//if (ary[PosX ][PosY+1] != 0) { PosY ++; }
				PosY++;
				break;
			}
			gotoxy(PosX, PosY);
			setColor(4);
			printf("●");
			setColor(15);
			
			enemy_hit_ck = enemy_hit(PosX, PosY);
			//gotoxy(120,30);
			//printf("%d",ary[PosX][PosY]);
			gotoxy(110, 19);   
			 g_info.timer = ((int)(end - start) / CLOCKS_PER_SEC);
			 
			 printf(" %5d", g_info.timer); 
			 add_score(PosX, PosY);
			 setColor(15);
			 update_data();
			 if (g_info.score == 20) {  update_data(); break; }
			
		}
		
	}
	
}
//스코어
void add_score(int x, int y) 
{
	if (ary[x][y] == 0) 
	{
		g_info.score++; 
		ary[x][y] == 1;
	}
}

//적과 부딪힘
int enemy_hit(int x, int y) 
{
	if (ary[x][y] == 4) { return 3; }
}



//적 이동 시스템
void enemy_system() {}

//타이머

void time_ck() 
{

	
	

	for (int i = 0; i < 5; i++)
	{
		Sleep(500000);
	}
	
	
	

}




void map_setting() 
{

	int num[4];
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		num[i] = rand() % 3;
	}


	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i][j] = randomMap[num[0]][i][j];
			gotoxy(11 + j * 2, 3 + i);
			if (randomMap[num[0]][i][j] == 0)
			{
				printf("  ");
			}
			else if (randomMap[num[0]][i][j] == 1)
			{
				setColor(15);

				printf("▨");
			}

			else if (randomMap[num[0]][i][j] == 2)
			{
				setColor(2);

				printf("♣");

			}
			else if (randomMap[num[0]][i][j] == 4)
			{
				setColor(8);

				printf("★");
			}
		}
		printf("\n");
	}
	//(1,0)
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i+22][j] = randomMap[num[0]][i][j];
			gotoxy(55 + j * 2, 3 + i);
			if (randomMap[num[1]][i][j] == 1)
			{
				setColor(15);
				printf("▨");
			}
			else if (randomMap[num[1]][i][j] == 0)
			{
				printf("  ");
			}
			else if (randomMap[num[1]][i][j] == 2)
			{
				setColor(2);
				printf("♣");

			}
			else if (randomMap[num[1]][i][j] == 4)
			{
				setColor(8);
				printf("★");
			}
		}
		printf("\n");
	}
	//(0, 1)
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i ][j+22] = randomMap[num[0]][i][j];
			gotoxy(11 + j * 2, 25 + i);
			if (randomMap[num[2]][i][j] == 1)
			{
				setColor(15);
				printf("▨");
			}
			else if (randomMap[num[2]][i][j] == 0)
			{
				printf("  ");
			}
			else if (randomMap[num[2]][i][j] == 2) 
			{
				setColor(2);
				printf("♣");

			}
			else if (randomMap[num[2]][i][j] == 4)
			{
				setColor(8);
				printf("★");
			}
		}
		printf("\n");
	}
	//(1,1)
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i+22][j + 22] = randomMap[num[0]][i][j];
			gotoxy(55 + j * 2, 25 + i);
			if (randomMap[num[3]][i][j] == 1)
			{
				
				setColor(15);
				printf("▨");
			}
			else if (randomMap[num[3]][i][j] == 0)
			{
				printf("  ");
			}
			else if (randomMap[num[3]][i][j] == 2)
			{
				setColor(2);
				printf("♣");

			}
			else if (randomMap[num[3]][i][j] == 4)
			{
				setColor(8);
				printf("★");
			}
		}
		printf("\n");
	}

}

void end_game() { sceneManager(4); }

