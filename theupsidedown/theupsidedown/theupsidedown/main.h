#pragma once


//--define----------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

//Ű����
#define NEXT 122

//����Ű
#define LEFT 75        
#define RIGHT 77    
#define UP 72        
#define DOWN 80        

//��
#define WALL 1
#define EMPTY 0
#define LIGHT 2
#define MONSTER 5

#define SUCCESS 12
#define FAIL 13

//---���----------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//#include  "random_map.h"



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

//---�Լ�----------------------------------------------------------------------

//���̺�
void gotoxy(int x, int y);
void double_buf();
void setColor(int color);

void outgame_table();
//void outgame_content(int index, char *third, int second_line);
void *first_box(int index);
void second_box(int index);

void ingame_table();
int end_screen();

//�ʱ�ȭ
void init_info();
void init_list();

//����
void sceneManager(int sceneNum);
int keyboard_input();

//��ũ

void rank_system();
void input_record();
void output_records();




//����
void drawing_map();
void character_move();
//void characters_set();
void game_set();
void game_setting();


void monster_move();
int timer();
int success();
void earn_score();
void character_setting();
int fail();

void monster_pattern(int x,int y);
void monster_closer(int x, int y);

//---����----------------------------------------------------------------------
//�׽�Ʈ


