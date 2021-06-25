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
	//����
	vector center;
	//������ -> ���� ������, �簢���� �� ���� ����/2, ���� ������ ������
	int size;
	//�����̴� ũ����� ��Ÿ���� ���Ͱ� ���Ϳ� �������� ��.
	vector v;
public:
	//������ -> �����ɶ��� ����
	CObject(int r, int speed);
	virtual void Update();
	virtual void collision();
	virtual void Draw(HDC hdc);
};

class CCircle :public CObject
{
private:
	//����
	vector center;
	int R;
	//�����̴� ũ����� ��Ÿ���� ���Ͱ� ���Ϳ� �������� ��.
	vector v;
public:
	//������ -> �����ɶ��� ����
	//CCircle(int r,int speed);
	CCircle(int r, int speed);
	virtual void Update();
	virtual void collision();
	virtual void Draw(HDC hdc);
};
