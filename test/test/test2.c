

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>  
#include  "test_head.h"
#include  "random_map.h"//random_map

//방향키
#define LEFT 75        
#define RIGHT 77    
#define UP 72        
#define DOWN 80        

//맵
#define WALL 1
#define EMPTY 0
#define START 3
#define FINISH 4

#define FRUIT 5
#define COLLISION 10
int ary[5][5];
void character();
void test();
void gotoxy(int x, int y);

int main() 
{
	test();
	return 0;
}
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void test() 
{

	
	int num[4];
	srand(time(NULL));

	for (int n = 0; n < 4; n++)
	{
		num[n] = rand() % 3;
	}

	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ary[i][j] = mMap[num[0]][i][j];
			
			if (ary[i][j] == 0)
			{
				gotoxy(11 + j * 2, 3 + i);
				printf("□");
			}
			else if (ary[i][j] == 1)
			{
				gotoxy(11 + j * 2, 3 + i);
				printf("■");
				printf("%d",ary[i][j]);
			}
			else if (ary[i][j] == 2)
			{
				gotoxy(11 + j * 2, 3 + i);
				printf("○");
			}
			else if (ary[i][j] == 3)
			{
				gotoxy(11 + j * 2, 3 + i);
				printf("●");
			}
			else if (ary[i][j] == 4)
			{
				gotoxy(11 + j * 2, 3 + i);
				printf("★");
			}

		}
		puts("");
	}

	int PosX = 11;
	int PosY = 3;
	gotoxy(PosX, PosY);
	printf("＠");

	while (1)
	{
		if (_kbhit())
		{
			// 캐릭터 지우기
			gotoxy(PosX, PosY);
			printf("  ");

			//키보드 입력
			switch (_getch())
			{
			case LEFT:
				if (PosX <= 11)
					break;
				PosX -= 2;
				break;

			case RIGHT:
				if (PosX >= 96)
					break;
				PosX += 2;
				break;

			case UP:
				if (PosY <= 3)
					break;
				PosY--;
				break;

			case DOWN:
				if (PosY >= 46)
					break;
				PosY++;
				break;
			}
			gotoxy(PosX, PosY);
			printf("＠");
			/*
			gotoxy(10, 49);
			printf("%d", ary[PosX][PosY-1]);
			gotoxy(8, 48);
			printf("%d", ary[PosX-1][PosY]);
			gotoxy(12, 48);
			printf("%d", ary[PosX+1][PosY]);
			gotoxy(10, 47);
			printf("%d", ary[PosX][PosY+1]);*/

			gotoxy(10, 30);
			printf("%d", ary[PosX][PosY]);
			//printf("(%d,%d)\n", PosX, PosY);

		}

	}
	

	
}

void character() 
{

	


}