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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>  
#include  "map.h"
#include  "random_map.h"//random_map

//방향키
#define LEFT 75        
#define RIGHT 77    
#define UP 72        
#define DOWN 80        
//맵
/*
#define WALL 1
#define SAPCE 0
#define RMS 25
#define START 3
#define FINISH 4*/

//--wj--------------------------------------------------------


//--함수--------------------------------------------------------
void gotoxy(int x, int y);
void setColor(int color);

void game_set();
void player_move();
void game_table();
void map_setting();

//int *random_value();




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
} ;

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
	game_set();


	return 0;

}

/*
int *random_value() 
{
	int data[4];
	srand(time(NULL));
	for (int i = 0; i < 4;i++) 
	{
		data[i] = rand() % 3;
	}
	
	
	return data;
}*/

void game_set() 
{
	
	game_table();
	map_setting();
	player_move();
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
	//gotoxy(110, 19);   printf(" %5d", g_info.timer);

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


void map_setting() 
{
	int num[4];
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		num[i] = rand() % 3;
	}
	
	//(0,0)
	for (int i = 0; i < 22; i++) 
	{
		for (int j = 0; j < 22; j++) 
		{
			if (randomMap[num[0]][i][j] == 1)
			{
				gotoxy(11 + 2 * i, 3 + j);
				printf("▨");
			}
			else if (randomMap[num[0]][i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	//(1, 0) //11,3
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (randomMap[num[1]][i][j] == 1)
			{
				gotoxy(55+i*2, 3 + j);  
				printf("▨");
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
				printf("▨");
			}
			else if (randomMap[num[2]][i][j] == 0) //어딨니??
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
				printf("▨");
			}
			else if (randomMap[num[3]][i][j] == 0)
			{
				printf("  ");
			}
		}
		puts("");
	}
	/*
	for (int i = 0; i < 44; i++)
	{
		for (int j = 0; j < 44; j++)
		{
			if (map[i][j] == 1)
			{
				//gotoxy(9 + i*2, 2 + j);
				gotoxy(11 + 2 * i, 3 + j);
				printf("▨");
			}
			else if (map[i][j] == 0)
				printf("  ");
		}
		puts("");    // 자동줄바꿈
	}*/

}

void player_move() 
{
	int dir = 1;

	//플레이어 기본 위치
	int PosX = 11;
	int PosY = 3;
	
		
	gotoxy(PosX, PosY);
	printf("◎◎");
	printf("\n");
	gotoxy(PosX, PosY + 1);
	printf("●●");

	// 좌표 확인
	//
	gotoxy(10, 48);
	printf("(%d,%d)", PosX, PosY);

	while (1)
	{
		if (_kbhit())  
		{
			//
			// 기존 정보 정리
			//
			// 캐릭터 지우기
			gotoxy(PosX, PosY);
			printf("      "); 
			printf("\n");
			gotoxy(PosX, PosY+1);
			printf("      "); 
			printf("\n");
			gotoxy(PosX, PosY + 2);
			printf("      "); 
			//키보드 입력
			switch (_getch())
			{
			case LEFT:
				
				if (PosX <= 11)
					break;
				PosX -= 2;
				dir *= (-1);
				break;

			case RIGHT:
				if (PosX >= 92)
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
				if (PosY >= 44)
					break;
				PosY++;
				dir *= (-1);
				break;
			}

			// 플레이어 이동
			if (dir > 0) 
			{
				gotoxy(PosX, PosY);
				printf("●●");
				printf("\n");
				gotoxy(PosX, PosY + 1);
				printf("●●");
			}
			else 
			{
				gotoxy(PosX, PosY);
				printf(" ● ");
				printf("\n");
				gotoxy(PosX, PosY+1);
				printf("●●");
			}
			
			

			
			gotoxy(10, 48);
			printf("(%d,%d)", PosX, PosY);
		}
	}
}

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


	