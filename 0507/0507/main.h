
//--define ����----------------------------------------------------------------------------------//
//#include <Ole2.h>
//#include <gdiplus.h>
#pragma warning(disable: 4819)
//using namespace Gdiplus;
//#pragma comment(lib, "winmm.lib")
#define _CRT_SECURE_NO_WARNINGS

//Ű����
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define z 122


//��
#define WALL 1
#define SPACE 0
#define DEST 3
#define START 4;

//--��� ����----------------------------------------------------------------------------------//


//#include<mmsystem.h>


#include <stdio.h> 
#include <windows.h> 
#include <string.h> 
#include <conio.h> 
#include <malloc.h>    
#include <time.h> //<process.h> 
#include <process.h>  


//--��������---------------------------------------------------------------------------------//
//int timer = 120;
int enemy_hit_ck;
int ary[44][44];
int start_time , end_time, gap;


//--����ü ����----------------------------------------------------------------------------------//
struct record_list
{
	int max_score;
	char players_name[80];
	int rank;
};

struct cur_player_info
{
	int score;
	char cur_playername[80];
	int timer;
};

extern struct cur_player_info g_info;
extern struct  record_list g_list[5];



//--�Լ� ����----------------------------------------------------------------------------------//

//main
void sceneManager(int sceneNum);
void double_buf();
int keyboard_input();

//�ʱ�ȭ �Լ�
void init_info();
void init_list();

//���̺�
void gotoxy(int x, int y);
void setColor(int color);
void ingame_table();
void outgame_table();
void outgame_content(int index, char *third, int second_line);
void *first_box(int index);
void second_box(int index);
int end_screen();

//records
void input_record();
void output_records();
void rank_system();
void test();


//�ΰ��� �Լ�
void set_game();
void player_move();
void map_setting();
void add_score(int x, int y);
int enemy_hit(int x, int y);
void enemy_system();
void time_ck();
void end_game();

//
void update_data();

