#include "main.h"
#include "map.h"


//--Ű����---------------------------------------------------
#define UP 72
#define DOWN 80 
#define LEFT 75     
#define RIGHT 77

//--��---------------------------------------------------

#define WALL 1
#define SPACE 0

int ary[44][44];

struct  record_list g_list[5];
struct cur_player_info g_info;


int timer = 120;


//�÷��̾�,��, ��ġ ����
void set_game() 
{
	gotoxy(10, 3);
	
	ingame_table();
	map_setting();
	set_character();

	enemy_system();
	player_move();
	add_score();

}



//�� ��� ���� ����
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
			gotoxy(11 + 2 * j, 3 + i);
			if (ary[i][j] == 1)
			{
				printf("��");
			}
			else if (ary[i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	/*
	//(1, 0) //11,3
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (randomMap[num[1]][i][j] == 1)
			{
				gotoxy(55 + i * 2, 3 + j);
				printf("��");
			}
			else if (randomMap[num[1]][i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	//(0, 1)
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (randomMap[num[2]][i][j] == 1)
			{
				gotoxy(11 + i * 2, 25 + j);
				printf("��");
			}
			else if (randomMap[num[2]][i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	//(1,1)
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (randomMap[num[3]][i][j] == 1)
			{
				gotoxy(55 + i * 2, 25 + j);
				printf("��");
			}
			else if (randomMap[num[3]][i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}*/

	//�������� �����ϸ� 3�� ��ȯ
	//���� ������ 4�� ��ȯ
	//�����۰� ���� ��ġ�� ���� 5�� ��ȯ
	return 0;
}


/*
void PlayerMove(int * PosX, int * PosY, int Key) 
{
	switch (Key) {
		case UP: 
			if (randomMap[*PosY - 1][*PosX] != WALL) 
		{ 
			randomMap[*PosY][*PosX] = SPACE; *PosY -= 1; 
		}
				 break;
		case DOWN: if (randomMap[*PosY + 1][*PosX] != WALL) { randomMap[*PosY][*PosX] = SPACE; *PosY += 1; } break;
		case LEFT: if (randomMap[*PosY][*PosX - 1] != WALL) { randomMap[*PosY][*PosX] = SPACE; *PosX -= 1; } break;
		case RIGHT: if (randomMap[*PosY][*PosX + 1] != WALL) { randomMap[*PosY][*PosX] = SPACE; *PosX += 1; } break;
	}
	randomMap[*PosY][*PosX] = PLAYER;
	
	return;
}
*/

int set_character() 
{
	//�÷��̾�
	int PosX = 11;
	int PosY = 3;

	//ĳ���͸��
	gotoxy(PosX, PosY);
	setColor(4);
	printf("��");

	//��Ʈ
	gotoxy(33, 12);
	setColor(2);
	printf("��");
}

int player_move()
{
	int dir = 1;

	int characterSize = 1;

	//�÷��̾� �⺻ ��ġ
	int PosX = 11;
	int PosY = 3;

//ĳ���͸��
	gotoxy(PosX, PosY);
	setColor(4);
	printf("��");

	while (1)
	{
		if (_kbhit())
		{
			// ĳ���� �����
			gotoxy(PosX, PosY);
			printf("  ");
			
			switch (_getch())
			{
			case LEFT:

				if (PosX <= 11) break;
				
					PosX -= 2;
					dir *= (-1);
				
			break;

			case RIGHT:
				if (PosX >= 96)
					break;
				
					PosX += 2;
					dir *= (-1);
	
				break;

			case UP:
				if (PosY <= 3)
					break;
					PosY--;
					dir *= (-1);
				
				break;
				
			case DOWN:
				if (PosY >= 46)	break;
				
					PosY++;
					dir *= (-1);
				
				
				break;
			}
			gotoxy(PosX, PosY);
			setColor(4);
			printf("��");
			
			

			gotoxy(10, 48);
			//printf("(%d,%d)", PosX, PosY);
			printf("%d", ary[PosX][PosY]);
		}
	}
	//�������� �����ϸ� 5
	//���� ������ 3
	//������ ȹ���ϸ� 4
	return 0;
}


//�÷��̾� ���� ȹ��
void add_score() 
{
	for(;;)
	{
		if (player_move()==4)
		{
			g_info.score++;
		}
	}
}

//�� �̵�
void enemy_system() 
{
	int dir = 1;

	int ghostSize = 1;

	//�÷��̾� �⺻ ��ġ
	/*
	int PosX[2] = {33,77};
	int PosY[2] = { 12,34 };

	gotoxy(PosX[0], PosY[0]);
	setColor(2);
	printf("��");*/
	gotoxy(33, 12);
	setColor(2);
	printf("��");

}

//
void GameEnd() 
{
}