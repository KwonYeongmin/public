// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class CObject 
{
private:
	int center[2];
	int movespeed;
	int direction[2];
	int size;
public:
	CObject(int p[2], int s, int speed, int dir[2])
	{
		center[0] = p[0]; center[1] = p[1];
		movespeed = speed;
		direction[0]= dir[0]; direction[1] = dir[1];
		size = s;
	}
	void Update(); //좌표갱신 -> 타이머
	virtual void Collision() {} // 충돌 검사 -> 업데이트가 끝난 후에 
	virtual void Draw() {}
	int *getCenter() { return center; }
};
void CObject::Update()
{
	center[0] += direction[0] * movespeed;
	center[1] += direction[1] * movespeed;
}

class CCircle : public CObject
{
private:
	int R;
public:
	CCircle(int p[2], int s, int speed, int dir[2]) : CObject(p, r, speed, dir)
	{
		R = r;
	}
	void setCenter();
	virtual void Collision(int rclient,int dir[2]);
	virtual void Draw(int hdc);
};
void CCircle::setCenter()
{
	center[0] = CObject::getCenter().x;
	center[1]= CObject::getCenter().y;
}

void CCircle::Draw(HDC hdc)
{
	Ellipse(hdc, center.x - R, center.y - R, center.x + R, center.y + R);
}


void CCircle::Collision(RECT rclient, POINT dir)
{
	if (center.x + R > rclient.right) center.x = rclient.right - R;
	if (center.y + R > rclient.bottom) center.y = rclient.bottom - R;
	if (center.x - R < rclient.left)center.x = rclient.left + R;
	if (center.y - R < rclient.top)center.y = rclient.top + R;
}
int main()
{
    std::cout << "Hello World!\n";
}