/*#define _crt_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	int row = 0, col = -1;
	int val = 1;
	int dir = 1;
	int ary[5][5];
	int size = 5;

	while (0<=size)
	{
		for (i = 0; i < size; i++)
		{
			col = col + dir;
			ary[row][col] = val;
			val++;
		}
		size--;
		for (i = 0; i < size; i++)
		{
			row = row + dir;
			ary[row][col] = val;
			val++;
		}
		dir = dir * (-1);
	}


	for (row = 0; row < 5; row++)
	{
		for (col = 0; col < 5; col++)
		{
			printf("%5d",ary[row][col]);
		}
		printf("\n");
	}

	return 0;
}
*/
/*
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


//--wj--------------------------------------------------------
//int ary[44][44];

//--함수--------------------------------------------------------
void gotoxy(int x, int y);
void setColor(int color);

void game_set();
void player_move(int n);

void game_table();

void game_timer();

void map_drwaing();
void ghostMove();


void test();



void file();

//--구조체--------------------------------------------------------

struct player_list
{
	char playername[80];
	int score;
	int rank;
};

struct cur_info
{
	char cur_playername[80];
	int cur_score;
};

int timer=0;

//--디자인 함수--------------------------------------------------------

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	system("mode con cols=140 lines=50");
	//game_set();

	test();
	
	return 0;

}

void test() 
{
	int ary[5][5];

	int PosX = 11;
	int PosY = 3;

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
			gotoxy(11 + j*2, 3 +  i); 
			if (ary[i][j]== 0)
			{

				printf("□");
			}
			else if (ary[i][j] == 1)
			{
				printf("■");
			}
			else if (ary[i][j] == 2)
			{
				printf("○");
			}
			else if (ary[i][j] == 3)
			{
				printf("●");
			}
			else if (ary[i][j] == 4)
			{
				printf("★");
			}

		}
		puts("");
	}


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
				//if (ary[PosX + 2][PosY] == 0) { PosX -= 2; }
				PosX -= 2;
				break;

			case RIGHT:
				if (PosX >= 96)
					break;
				//if (ary[PosX -2][PosY] == 0) { PosX += 2; }
				PosX += 2;
				break;

			case UP:
				if (PosY <= 3)
					break;
				//if (ary[PosX][PosY + 1] == 0) { PosY--; }
				PosY--;
				break;

			case DOWN:
				if (PosY >= 46)
					break;
				//if (ary[PosX][PosY - 1] == 0) { PosY++; }
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
			printf("%d", ary[PosX][PosY+1]);
			
			gotoxy(10, 48);
			printf("%d", ary[PosX][PosY]);
			//printf("(%d,%d)\n", PosX, PosY);

		}

	}
}*/
/*

void game_set()
{
	game_table();
	map_drwaing();
	game_timer();
	player_move(1);
	
	
	
}


void player_move(int n)
{
	//플레이어 기본 위치
	
	int PosX = 11;
	int PosY = 3;
	gotoxy(PosX, PosY);
	printf("●");

	ghostMove();

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
				//if (ary[PosX + 2][PosY] == 0) { PosX -= 2; }
				PosX -=2;
				break;

			case RIGHT:
				if (PosX >= 96)
					break;
				//if (ary[PosX -2][PosY] == 0) { PosX += 2; }
				PosX += 2;
				break;

			case UP:
				if (PosY <= 3)
					break;
				//if (ary[PosX][PosY + 1] == 0) { PosY--; }
				PosY--;
				break;

			case DOWN:
				if (PosY >= 46)
					break;
				//if (ary[PosX][PosY - 1] == 0) { PosY++; }
				PosY++;
				break;
			}
			gotoxy(PosX, PosY);
			printf("●");
			/*
			gotoxy(10, 49); 
			printf("%d", ary[PosX][PosY-1]);
			gotoxy(8, 48);
			printf("%d", ary[PosX-1][PosY]);
			gotoxy(12, 48);
			printf("%d", ary[PosX+1][PosY]);
			gotoxy(10, 47);
			printf("%d", ary[PosX][PosY+1]);
			
			gotoxy(10, 48);
			//printf("%d", ary[PosX][PosY ]);
			//printf("(%d,%d)\n", PosX, PosY);
			
		}
		
	}
	
}
*/
/*
void ghostMove() 
{
	//고스트 기본 위치
	int PosX_go[2] = { 33,77 };
	int PosY_go[2] = { 12,34 };

	gotoxy(PosX_go[0], PosY_go[0]);
	printf("★");
	gotoxy(PosX_go[1], PosY_go[0]);
	printf("★");
	gotoxy(PosX_go[1], PosY_go[1]);
	printf("★");
	gotoxy(PosX_go[0], PosY_go[1]);
	printf("★");
}



void  game_timer()
{
	clock_t start = clock();
	int time = 500;
	//int timer=0;
	int sec_time, temp;

	
		clock_t end = clock();

		temp = end - start;
		sec_time = temp / CLOCKS_PER_SEC; //초단위 변환
		timer = time - sec_time;
		//printf("경과시간 : %d\n", timer);
		
	

}

void game_table()
{
	//테이블 크기 90X90
	//맵 크기 88X88
	//2칸씩 움직임
	setColor(1);
	gotoxy(9, 2); for (int i = 0; i < 46; i++) printf("▦");
	for (int i = 3; i < 47; i++) { gotoxy(9, i);  printf("▦"); }
	for (int i = 3; i < 47; i++) { gotoxy(99, i);  printf("▦"); }
	gotoxy(9, 47); for (int i = 0; i < 46; i++) printf("▦");

	//player_box
	setColor(1);
	gotoxy(107, 3); for (int i = 0; i < 12; i++) printf("▦");
	for (int i = 4; i < 10; i++) { gotoxy(107, i);  printf("▦"); }
	for (int i = 4; i < 10; i++) { gotoxy(129, i);  printf("▦"); }
	gotoxy(107, 10); for (int i = 0; i < 12; i++) printf("▦");
	gotoxy(110, 5);  setColor(15); printf(" playername : ");
	//플레이어이름 길이에 따라 밑줄에 이름내려올수있게 if로 ㄴ
	//gotoxy(110, 8);  printf(" %10s", g_info.cur_playername);

	//timer_box
	setColor(1);
	gotoxy(107, 14); for (int i = 0; i < 12; i++) printf("▦");
	for (int i = 15; i < 21; i++) { gotoxy(107, i);  printf("▦"); }
	for (int i = 15; i < 21; i++) { gotoxy(129, i);  printf("▦"); }
	gotoxy(107, 21); for (int i = 0; i < 12; i++) printf("▦");
	gotoxy(110, 16);  setColor(15); printf(" timer : ");
	gotoxy(110, 19);   printf(" %5d", timer);

	//highscore_box
	setColor(1);
	gotoxy(107, 25); for (int i = 0; i < 12; i++) printf("▦");
	for (int i = 26; i < 32; i++) { gotoxy(107, i);  printf("▦"); }
	for (int i = 26; i < 32; i++) { gotoxy(129, i);  printf("▦"); }
	gotoxy(107, 32); for (int i = 0; i < 12; i++) printf("▦");
	gotoxy(110, 27);  setColor(15); printf(" high score : ");
	//gotoxy(110, 30);  printf(" %5d", g_list[0].max_score);

	//score_box
	setColor(1);
	gotoxy(107, 37); for (int i = 0; i < 12; i++) printf("▦");
	for (int i = 38; i < 44; i++) { gotoxy(107, i);  printf("▦"); }
	for (int i = 38; i < 44; i++) { gotoxy(129, i);  printf("▦"); }
	gotoxy(107, 44); for (int i = 0; i < 12; i++) printf("▦");
	gotoxy(110, 39);  setColor(15); printf(" score : ");
	//gotoxy(110, 42);  printf(" %5d", g_info.score);
}

*//*
void map_drwaing()
{
	
	int num[4];
	srand(time(NULL));
	for (int n = 0; n < 4; n++)
	{
		num[n] = rand() % 3;
	}
	//(0,0)

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i][j] = randomMap[num[0]][i][j];
			if (ary[i][j] == 1)
			{
				gotoxy(11 + j*2, 3 +  i);
				printf("▨");
			}
			else if (ary[i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			ary[i + 22][j] = randomMap[num[1]][i][j];
			if (ary[i + 22][j] == 1)
			{
				gotoxy(55 + j * 2, 3 + i);
				printf("▨");
			}
			else if (ary[i + 22][j] == 0)
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
			ary[i][j + 22] = randomMap[num[2]][i][j];
			if (ary[i][j + 22] == 1)
			{
				gotoxy(11+ j * 2, 25 + i); // gotoxy(3 + j * 2, 11 + i); //gotoxy(11 + 2 * i, 3 + j);
				printf("▨");
			}
			else if (ary[i][j + 22] == 0) 
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
			ary[i + 22][j + 22] = randomMap[num[3]][i][j];
			if (ary[i + 22][j + 22] == 1)
			{
				gotoxy(55 + j * 2, 25 + i);
				printf("▨");
			}
			else if (ary[i + 22][j + 22] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	
}*/
/*
void file()
{
	//초기화
	FILE *ifp, *ofp;
	int max_score = 0;

	//구조체초기화
	struct player_list list[5];
	list[0].score = 50;
	list[0].rank = 0;
	struct cur_info info;
	info.cur_score = 10;
	//바이너리 말고 텍스트로 어떻게?, 랭킹 매기기 어떻게 ?
	//파일 열기
	ifp = fopen("..\\data\\a.txt", "wt");
	ofp = fopen("..\\data\\b.txt", "wt");
	//세번 반복
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		//플레이어이름 입력
		printf("playername : ");
		scanf("%s", list[i].playername);
		//플레이어 점수 저장
		list[i].score = 10 + i;

		//파일에 입력
		fwrite(&list, sizeof(list), 1, ifp); // 구조체 크기만큼 1개 쓰기
		max_score = max_score > list[i].score ? max_score : list[i].score;
	}
	//가장 최근에 입력한 플레이어 정보 저장
	strcpy(info.cur_playername, list[i].playername);
	info.cur_score = list[i].score;

	printf("%d \n", max_score);
	fprintf(ofp, "%d ", max_score);
	fclose(ifp);
	fclose(ofp);

	ifp = fopen("..\\data\\a.txt", "rt");
	ifp = fopen("..\\data\\b.txt", "rt");
	//printf("%d ",max_score);

	//기록순으로 저장
	printf("records \n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", list[i].playername, list[i].score);
	}

	printf("%s score : %d \n", info.cur_playername, info.cur_score);
	printf("best score : %d \n", max_score);
	fclose(ifp); fclose(ofp);
}


*/