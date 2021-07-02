#pragma once
#include "framework.h"
//Æ÷Å¾
class Turret
{
private:
	POINT center;
	int r;
	POINT pos;
	int nr;
	double X, Y;
	int angle;
public :
	Turret() {}
	void init(POINT p, int R, RECT rclinent);
	long getPosX();
	long getPosY();
	int getAngle();
	int getRadius();
	void update(int cnt1, int cnt2, RECT rclinent);
	void draw(HDC hdc);
};

class Object;
//ÃÑ¾Ë
class Bullet 
{
private:
	POINT center;
	int r;
	int speed;
	POINT ss;
	//int direction;
public:
	Bullet(Turret t, int R);
	POINT getCenter();
	int getRadius();
	BOOL Collision(Object obj);
	void update(Turret t);
	void draw(HDC hdc);
};

//¶³¾îÁö´Â ¿ÀºêÁ§Æ®
class Object 
{
private:
	POINT p[7];
	POINT pos;
	int speed;
public:
	Object(POINT c, int s);
	void Update();
	void Draw(HDC hdc);
	POINT* getPoint();
	BOOL Collision(Bullet b);
};

//¹Ù´Ú
class defenseWall 
{
private: int life;
		 int r;
		 POINT center;
public:
	defenseWall(int R, POINT p);
	BOOL collsion(Object obj);
	void Update();
	void Draw(HDC hdc);
};