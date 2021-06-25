#pragma once
#include"framework.h"
typedef struct VECTOR2D
{
	double x;
	double y;
}vector;

class CObject
{
private:
	//센터
	vector center;
	//사이즈 -> 원은 반지름, 사각형은 한 변의 길이/2, 별은 원외접 반지름
	int size;
	//움직이는 크기방향 나타내는 벡터값 센터에 더해지게 됨.
	vector v;
public:
	//생성자 -> 생성될때의 방향
	CObject(int r, int speed);
	virtual void Update();
	virtual void collision();
	virtual void Draw(HDC hdc);
};

class CCircle :public CObject
{
private:
	//센터
	vector center;
	int R;
	//움직이는 크기방향 나타내는 벡터값 센터에 더해지게 됨.
	vector v;
public:
	//생성자 -> 생성될때의 방향
	//CCircle(int r,int speed);
	CCircle(int r, int speed);
	virtual void Update();
	virtual void collision();
	virtual void Draw(HDC hdc);
};
