#include "Cobject.h"
#include"Vector2D.h"
/*
클라이언트 영역에 마우스 왼쪽 버튼을 클릭하면
1. 해당위치 원 생성, 저장

2. 임의 방향으로 이동 클라이언트 외곽에서 반사
클래스로만들기

3. 다른 오브젝트와 충돌시
	3.1 기본 서로 튕기도록 처리
	3.2 상성관계에 따라 한 타입의 도형으로 합쳐지고 그 도형의 크기는 증가
	3.3 상성관계에 따라 분열 한쪽만 작은 크기로
	별>원>사각형>별
	3.4 일정 크기 이상은 그냥 사라지고, 일정 크기 이하도 그냥 사라지도록
4. 1번키 눌렀을 때 다른 오브젝트 부딪히면 하나로 합체해서 커지로고
2번키 눌렀을 때 다른 오브젝트 부딪치면 하나로 분열해서 작아지게

5. 랜덤으로 사각형, 원, 별 그려지도록

6. 도형 회전하도록

추가사항. 각자 만든 리스트 적용
*/
void CObject::Update()
{
	center.x += direction.x * movespeed.x;
	center.y += direction.y * movespeed.y;
}
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
	center.x += direction.x * movespeed.x;
	center.y += direction.y * movespeed.y;
}

//벽이랑 충돌
void CCircle0::Collision(RECT rclient, CCircle0 &other)//CCircle0 &other이거 템플릿으로 바꾸기
{
	//벽이랑 충돌할 때
	
	if (center.x + R > rclient.right) direction.x *= (-1); 
	if (center.y + R > rclient.bottom)direction.y *= (-1);
	if (center.x - R < rclient.left) direction.x *= (-1); 
	if (center.y - R < rclient.top)direction.y *= (-1);

	const double dis = sqrt(pow(other.getCenter().x - center.x, 2) + pow(other.getCenter().y - center.y, 2));
	
	//원끼리 충돌할 때
	if (dis <= 2 * R)
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


//사각형

void CRectangle::setCenter()
{
	center.x = CObject::getCenter().x;
	center.y = CObject::getCenter().y;
}

void CRectangle::Draw(HDC hdc)
{
	Rectangle(hdc, center.x - (width / 2.0), center.y - (width / 2.0), center.x + (width / 2.0), center.y + (width / 2.0));
}

void CRectangle::Update()
{
	center.x +=  direction.x * movespeed.x;
	center.y += direction.y * movespeed.y;
}


void CRectangle::Collision(RECT rclient)
{
	if (center.x + R > rclient.right) direction.x *= (-1);
	if (center.y + R > rclient.bottom) direction.y *= (-1);
	if (center.x - R < rclient.left)direction.x *= (-1);
	if (center.y - R < rclient.top) direction.y *= (-1);
}


	//CCircle1
/*
void CCircle1::setCenter()
{
	center.x = CObject::getCenter().x;
	center.y = CObject::getCenter().y;
}
void CCircle1::Update() 
{

}*/

void CCircle1::Collision(RECT rclient, CCircle0 &other) 
{
	//충돌
	if (center.x - R < rclient.left) 
	{
		Vector2D p(1, 0);
		// other.getCenter().x,other.getCenter().y
		// 
		Vector2D n(other.getCenter().x,other.getCenter().y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.y - R < rclient.top) 
	{
		Vector2D p(0, 1);
		Vector2D n(other.getCenter().x, other.getCenter().y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.x + R > rclient.right) 
	{
		Vector2D p(-1, 0);
		Vector2D n(other.getCenter().x, other.getCenter().y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
	if (center.y + R > rclient.bottom) 
	{
		Vector2D p(0, -1);
		Vector2D n(other.getCenter().x, other.getCenter().y);
		center.x = p.reflection(n).GetX();
		center.y = p.reflection(n).GetY();
	}
}


/*
void CCircle1::Draw(HDC hdc)
{
	Ellipse(hdc, center.x - R, center.y - R, center.x + R, center.y + R);
}*/