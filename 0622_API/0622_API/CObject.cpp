#include "Cobject.h"
#include"Vector2D.h"
 /*
��1.Ŭ���̾�Ʈ ������ ���콺 ���� ��ư�� Ŭ���ϸ�
1. �ش���ġ�� ���� ����,���� ����Ʈ�� ���� �� stl���
2. ���� �������� �̵�, Ŭ���̾�Ʈ �ܰ����� �ݻ�, Ŭ������ �����
3. �ٸ����� �浹�ϸ� ���� ƨ�⵵�� ó��
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

//���� ����, ������ �������� ƨ��
void CCircle0::Collision(RECT rclient, CCircle0 &other)
{
	//���̶� �浹�� ��
	if (center.x + R > rclient.right) direction.x *= (-1); //�������� ??
	if (center.y + R > rclient.bottom) direction.y *= (-1);
	if (center.x - R < rclient.left) direction.x *= (-1);
	if (center.y - R < rclient.top) direction.y *= (-1);

	//������ �浹�� ��
	if (sqrt(pow(other.getCenter().x - center.x, 2) + pow(other.getCenter().y - center.y, 2)) <= 2 * R)
	{
		//�ݴ���⿡�� �� ��
		if (other.getDirection().x*direction.x < 0 && other.getDirection().y*direction.y < 0)
		{
			direction.x *= (-1); direction.y *= (-1);
		}
		//x�� �ݴ���� �� ��
		else if (other.getDirection().x*direction.x < 0 && other.getDirection().y*direction.y > 0)
		{
			direction.x *= (-1);
		}
		//y�� �ݴ���� �� ��
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
	//�浹
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