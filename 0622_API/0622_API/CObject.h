#pragma once
#include "0622_API.h"
#include "Resource.h"
#include "framework.h"
#include "Vector2D.h"

class CObject
{
public:
	CObject(POINT p, int speed) : center{p.x,p.y}
	{
		srand((unsigned)time(NULL));
		//스피드 랜덤으로 주기
		direction.x = rand() % 2 * 2 - 1;
		direction.y = rand() % 2 * 2 - 1;
		movespeed.x = rand() % 5 + speed;
		movespeed.y = rand() % 5 + speed;
	}
	virtual void Collision(RECT rclient) {}
	virtual void Draw(HDC hdc) {}
	virtual void Update();
	POINT getCenter() { return center; }
	POINT getDirection() { return direction; }

private:
	POINT center;
	POINT movespeed;
	POINT direction;
};
//template <typename T>
class CCircle0 : public CObject
{
private:
	int R;
	POINT center;
	//Vector2D center(double x, double y);
	POINT movespeed;
	POINT direction;
	//POINT var;
	Vector2D var;
public:
	CCircle0(POINT p, int r, int speed) : CObject(p, speed)
	{
		
		srand((unsigned)time(NULL));
		setCenter();
		direction.x = rand() % 2 * 2 - 1;
		direction.y = rand() % 2 * 2 - 1;
		movespeed.x = rand() % 5 + speed;
		movespeed.y = rand() % 5 + speed;
		R = r;
	}
	void setCenter();
	virtual void Collision(RECT rclient, std::list<CCircle0*> b);
	virtual void Draw(HDC hdc);
	virtual void Update();
};

class CRectangle : public CObject
{
private:
	int R;
	POINT center;
	POINT movespeed;
	POINT direction;
	int width;
	int top;
	int bottom;
	int right;
	int left;
	
public:
	CRectangle(POINT p, int w, int speed) : CObject(p, speed)
	{
		srand((unsigned)time(NULL));
		width = w;
		R = width / 2;
		setCenter();
		//스피드,방향 랜덤 값
		direction.x = rand() % 2 * 2 - 1;
		direction.y = rand() % 2 * 2 - 1;
		movespeed.x = rand() % 5 + speed;
		movespeed.y = rand() % 5 + speed;
	}
	void setCenter();
	virtual void Collision(RECT rclient);
	virtual void Draw(HDC hdc);
	virtual void Update();
	
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
	CCircle1(POINT p, int r, int speed) : CObject(p,speed)
	{
		srand((unsigned)time(NULL));
		setCenter();
		direction.x = rand() % 2 * 2 - 1;
		direction.y = rand() % 2 * 2 - 1;
		movespeed.x = rand() % 5 + speed;
		movespeed.y = rand() % 5 + speed;
		R = r;
	}
	void setCenter() 
	{
		center.x = CObject::getCenter().x;
		center.y = CObject::getCenter().y;
	}
	virtual void Collision(RECT rclient, CCircle0 &other);

};

