#include "Cobject.h"
#include"Vector2D.h"
 /*
문1.클라이언트 영역에 마우스 왼쪽 버튼을 클릭하면
1. 해당위치에 원을 생성,저장 리스트나 벡터 등 stl사용
2. 임의 방향으로 이동, 클라이언트 외곽에서 반사, 클래스로 만들기
3. 다른원과 충돌하면 서로 튕기도록 처리
*/


void CCircle0::setCenter()
{
	center.x = CObject::getCenter().x;
	center.y = CObject::getCenter().y;
}

void CCircle0::Draw(HDC hdc)
{
	Ellipse(hdc, center.x - R, center.y - R, center.x + R, center.y + R);
}
void CCircle0::Update()
{
	center.x += direction.x * movespeed;
	center.y += direction.y * movespeed;
}

//각도 일정, 원끼리 겹쳐지면 튕김
void CCircle0::Collision(RECT rclient, CCircle0 &other)
{
	//벽이랑 충돌할 때
	if (center.x + R > rclient.right) direction.x *= (-1); //법선벡터 ??
	if (center.y + R > rclient.bottom) direction.y *= (-1);
	if (center.x - R < rclient.left) direction.x *= (-1);
	if (center.y - R < rclient.top) direction.y *= (-1);

	//원끼리 충돌할 때
	if (sqrt(pow(other.getCenter().x - center.x, 2) + pow(other.getCenter().y - center.y, 2)) <= 2 * R)
	{
		//반대방향에서 올 때
		if (other.getDirection().x*direction.x < 0 && other.getDirection().y*direction.y < 0)
		{
			direction.x *= (-1); direction.y *= (-1);
		}
		//x만 반대방향 올 때
		else if (other.getDirection().x*direction.x < 0 && other.getDirection().y*direction.y > 0)
		{
			direction.x *= (-1);
		}
		//y만 반대방향 올 때
		else if (other.getDirection().x*direction.x > 0 && other.getDirection().y*direction.y < 0)
		{
			direction.y *= (-1);
		}
	}
}

	//CCircle1
void CCircle1::setCenter()
{
	center.x = CObject::getCenter().x;
	center.y = CObject::getCenter().y;
}
void CCircle1::Update() 
{

}

void CCircle0::Collision(RECT rclient, CCircle0 &other) 
{
	//충돌
	if (center.x - R < rclient.left) 
	{
		Vector2D p(1, 0);
		Vector2D n(other.center.x,other.center.y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.y - R < rclient.top) 
	{
		Vector2D p(0, 1);
		Vector2D n(other.center.x, other.center.y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.x + R > rclient.right) 
	{
		Vector2D p(-1, 0);
		Vector2D n(other.center.x, other.center.y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.y + R > rclient.bottom) 
	{
		Vector2D p(0, -1);
		Vector2D n(other.center.x, other.center.y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
}



void CCircle1::Draw(HDC hdc)
{
	Ellipse(hdc, center.x - R, center.y - R, center.x + R, center.y + R);
}