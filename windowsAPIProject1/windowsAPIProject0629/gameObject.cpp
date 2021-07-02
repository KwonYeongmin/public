#include "gameObject.h"
//초기화
void Turret::init( POINT p, int R, RECT rclinent)
{
	r = R;
	nr = R * 2;
	angle = 40.0;
	center.x = p.x;
	center.y = p.y;
	pos.x = center.x;
	pos.y = center.y - nr;
	
}
long Turret::getPosX() { return pos.x; }
long Turret::getPosY() { return pos.y; }
int Turret::getAngle() { return angle; }
int Turret::getRadius() { return r; }

void Turret::update(int lcnt,int rcnt,RECT rclinent)
{
	angle = 60 * (lcnt-rcnt)-330;
	const double PI = 3.14159265358979323846;
	X = nr * cos((angle) / PI);
	Y = nr * sin((angle) / PI);

	pos.x = center.x + X;
	pos.y = rclinent.bottom- 120 - Y;
	
}

//총알 나오는거 그리기
void Turret::draw(HDC hdc)
{
	//포 그리기
	MoveToEx(hdc, center.x, center.y, NULL);
	LineTo(hdc, pos.x, pos.y);
	//탑
	Ellipse(hdc, center.x - r, center.y - r, center.x + r, center.y + r);
}

//총알
Bullet::Bullet(Turret t, int R )
{
	const double PI = 3.14159265358979323846;
	r = R;
	center.x = t.getPosX();
	center.y = t.getPosY();
	speed = 40;
	ss.x = t.getRadius()*cos(t.getAngle() / PI)-(speed + t.getRadius())*cos(t.getAngle() / PI);
	ss.y = t.getRadius()*sin(t.getAngle() / PI)-(speed + t.getRadius())*sin(t.getAngle() / PI);
}

//각도를 이용해서 방향 구하기
void Bullet::update(Turret t) 
{
	if (speed >= t.getPosX()) { center.x += ss.x; }
	else { center.x -= ss.x; }
	center.y += ss.y;
}

void Bullet::draw(HDC hdc) 
{
	Ellipse(hdc,center.x-r,center.y-r,center.x+r,center.y+r);
}

BOOL Bullet::Collision(Object obj) 
{
	int left = obj.getPoint()[2].x;
	int right = obj.getPoint()[4].x;
	int top = obj.getPoint()[0].y;
	int bottom = obj.getPoint()[3].y;

	if (top<center.y && bottom>center.y - r && left<center.x + 2 * r&&right>center.x)
	{
		return true;
	}
}


POINT Bullet::getCenter() { return center; }

int Bullet::getRadius() { return r; }


//바닥
defenseWall::defenseWall(int R, POINT p) 
{
	r = R;
	center.x = p.x;
	center.y = p.y;
}


BOOL defenseWall::collsion(Object obj)
{
	int left = obj.getPoint()[2].x;
	int right = obj.getPoint()[4].x;
	int top = obj.getPoint()[0].y;
	int bottom = obj.getPoint()[3].y;

	if (top<center.y && bottom>center.y - r&&left<center.x +2*r&&right>center.x) 
	{
		return true;
	}
}

void defenseWall::Draw(HDC hdc)
{
	Rectangle(hdc, center.x, center.y - r, center.x + 2 * r, center.y);
}

Object::Object( POINT c, int s)
{
	speed = s;
	pos.x = c.x;
	pos.y = c.y;
}

void Object::Update() { pos.y += speed; }
POINT* Object::getPoint() { return p; }

BOOL Object::Collision(Bullet b)
{
	int left = p[2].x;
	int right = p[4].x;
	int top = p[0].y;
	int bottom = p[3].y;
	
	if (b.getCenter().x > left - b.getRadius() && b.getCenter().y > top - b.getRadius() && b.getCenter().x < right + b.getRadius()&& b.getCenter().y < bottom + b.getRadius())
	{
		return true;
	}

	
}
void Object::Draw(HDC hdc)
{
	p[0] = { pos.x,pos.y }; //top
	p[1] = { pos.x,pos.y + 60 };
	p[2] = { pos.x - 15,pos.y + 60 }; //left
	p[3] = { pos.x + 15,pos.y + 90 }; //bottom
	p[4] = { pos.x + 45,pos.y + 60 }; //right
	p[5] = { pos.x + 30,pos.y + 60 };
	p[6] = { pos.x + 30,pos.y };

	Polygon(hdc,p,7);
}