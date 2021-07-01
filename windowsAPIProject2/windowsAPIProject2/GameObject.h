#pragma once
#include "framework.h"
/*
1. 커서움직이기
2. 커서대로 선 만들어짐
3. 선 만들어진 대로 도형 생김 --> 면적 리턴
4. 도형의 색깔  빨간색이거 마스크 
*/
/*
1. 센터 움직이는 점을 list에 저장
2. list에 저장된 값으로 그림을 그리기
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
	//움직이는 점을 points에 저장
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
	//도형 그리기
	void OnGdi_Draw(HDC hdc);
	//선 그리기
	void OnGdi_line(HDC hdc);
	//적과 충돌 체크
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
	void OnGdi_Draw(HDC hdc); // 선이랑 그림
	
};

