#pragma once
#include "framework.h"
/*
1. Ŀ�������̱�
2. Ŀ����� �� �������
3. �� ������� ��� ���� ���� --> ���� ����
4. ������ ����  �������̰� ����ũ 
*/
/*
1. ���� �����̴� ���� list�� ����
2. list�� ����� ������ �׸��� �׸���
3.


	static std::list<Bullet*> basket;
	static Bullet *bullet;
	bullet = new Bullet(turrent, 20);
	basket.push_back(bullet);
*/
class EnemyMove
{
private:
	POINT center;
	int r;
public:
	EnemyMove() {}
	void init(POINT p, int R, RECT rectview);
	POINT GetPos();
	void Update();
	void Draw(HDC hdc);
};

typedef struct ss
{
	POINT p;
	struct ss *next;
	struct ss *prev;
} ss;

class List
{
private:
	ss *head;
	ss *tail;
public:
	List();
	void AddBack(ss tdata);
	void Terminate(ss *list);
};

class Cursor
{
private:
	POINT center;
	//�����̴� ���� points�� ����
	std::list<POINT*> points;
	POINT savePoint;
	int moveSpeed;
	int r;

public:
	Cursor()
	{
		center = { 868,600 }; moveSpeed = 5; r = 20; 
	
	}
	void init(POINT p, int R, RECT rectview);
	void Update();
	POINT GetPos();	
	//void test1();
	//void test2(HDC hdc);
	//���� �׸���
	void OnGdi_Draw(HDC hdc);
	//�� �׸���
	void OnGdi_line(HDC hdc);
	//���� �浹 üũ
	void Collision();
};

class DrawBackImage 
{
	HBITMAP hBackImage;
	BITMAP bitBack;
	HBITMAP hBackBackImage;
	BITMAP bitBackBack;
	POINT pos;
public:
	DrawBackImage() { pos = {200,160}; }
	//BackImage
	void CreateBitmap();
	void DrawBitmap(HDC hMemDC, HDC hMemDC2, HBITMAP hOldBitmap2);
	void DeleteBitmap();
};

//frontImage
class DrawFrontImage 
{
private:
	ULONG_PTR g_GdiToken;
	POINT pos;
public:
	DrawFrontImage() { pos = { 200,160 }; }
	//FrontImage
	//void Gdi_Init();// winmain
	//void Gdi_End(); // winmain
	void OnGdi_Update(Cursor cursor);
	void OnGdi_Draw(HDC hdc); // ���̶� �׸�
	
};

