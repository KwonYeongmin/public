
//--define 선언----------------------------------------------------------------------------------//
#pragma warning(disable: 4819)
#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define z 122
//--헤더 선언----------------------------------------------------------------------------------//

#include <stdio.h> 
#include <windows.h> 
#include <string.h> 
#include <conio.h> 
#include <malloc.h>    
#include <time.h> //<process.h> 
#include <process.h>  



//--전역변수---------------------------------------------------------------------------------//

//--구조체 선언----------------------------------------------------------------------------------//
struct record_list
{
	int max_score ;
	char players_name[80];
	int rank ;
};

struct cur_player_info
{
	int score;
	char cur_playername[80] ;
	int timer ;
};

extern struct cur_player_info g_info;
extern struct  record_list g_list[5];

//--함수 선언----------------------------------------------------------------------------------//

void sceneManager(int sceneNum);
void double_buf();
void setColor(int color);
void outgame_table();
void outgame_content(int index, char *third, int second_line);
void ingame_table();


void input_record();
void output_records();
void rank_system();


void *first_box(int index);
void second_box(int index);


int keyboard_input();
int end_screen();

void gotoxy(int x, int y);
void init_info();
void init_list();
//--인게임 함수--------------------------------------------------------------------------------//
void set_game();
int player_move();
void map_setting();
void add_score();

void enemy_system();

int set_character();
void GameEnd();
//void PlayerMove(int * PosX, int * PosY, int Key);

//-----------------------------------------------------------------------------------//


//void GamePlay(void);
