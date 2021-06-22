#pragma once
#include "0622_API.h"
#include "Resource.h"
#include "framework.h"
#include "Vector2D.h"

class CObject
{
public:
	CObject(POINT p, POINT dir)
	{
		srand((unsigned)time(NULL));
		//스피드 랜덤으로 주기
		movespeed.x = rand() % 50;
		movespeed.y =rand()% 50;
		center.x = p.x; center.y = p.y;
		direction.x = dir.x; direction.y = dir.y;
	}
	//virtual void Collision(RECT rclient);
	//virtual void Draw(HDC hdc);
	POINT getCenter() { return center; }
	POINT getDirection() { return direction; }

private:
	POINT center;
	POINT movespeed;
	POINT direction;
};

class CCircle0 : public CObject
{
private:
	int R;
	POINT center;
	POINT movespeed;
	POINT direction;
public:
	CCircle0(POINT p, int r, int speed, POINT dir) : CObject(p, dir)
	{
		setCenter();
		center.x = p.x;
		center.y = p.y;
		movespeed.x = rand()%10+40;
		movespeed.y = rand() %10 + 40;
		direction = dir;
		R = r;
	}
	void setCenter();
	virtual void Collision(RECT rclient, CCircle0 &other);
	virtual void Draw(HDC hdc);
	void Update();
};


//movespeed를 랜덤으로 주기
class CCircle1 : public CObject
{
private:
	int R;
	POINT center;
	POINT movespeed;
	POINT direction;
public:
	CCircle1(POINT p, int r, POINT dir) : CObject(p,dir)
	{
		setCenter();
		center.x = p.x; center.y = p.y;
		srand((unsigned)time(NULL));
		movespeed.x =rand()%50;
		movespeed.y = rand() % 50;
		direction = dir;
		R = r;
	}
	void setCenter();
	virtual void Collision(RECT rclient, CCircle0 &other);
	virtual void Draw(HDC hdc);
	void Update();
};
