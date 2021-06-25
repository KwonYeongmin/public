#include "CObject.h"
CObject::CObject(int r, int speed)
{
	size = r;
	srand((unsigned)time(NULL));
	v.x = (rand() % 2 * 2 - 1) * (rand() % 5 + speed);
	v.y = (rand() % 2 * 2 - 1)*  (rand() % 5 + speed);
}
void CObject::Update()
{
	center.x += v.x;
	center.x += v.y;
}

void CObject::collision()
{
	center.x += v.x;
	center.x += v.y;
}

void CObject::Draw(HDC hdc)
{
}


CCircle::CCircle(int r, int speed) :CObject(r, speed)
{
	srand((unsigned)time(NULL));
	R = r;
	v.x = (rand() % 2 * 2 - 1) * (rand() % 5 + speed);
	v.y = (rand() % 2 * 2 - 1)*  (rand() % 5 + speed);
}

void CCircle::Update()
{
	center.x += v.x;
	center.x += v.y;
}
void CCircle::collision()
{
	center.x += v.x;
	center.x += v.y;
}

void CCircle::Draw(HDC hdc)
{
	Ellipse(hdc, center.x - R, center.y - R, center.x + R, center.y + R);
}