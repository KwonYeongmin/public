#include "Cobject.h"
#include"Vector2D.h"
/*
Ŭ���̾�Ʈ ������ ���콺 ���� ��ư�� Ŭ���ϸ�
1. �ش���ġ �� ����, ����

2. ���� �������� �̵� Ŭ���̾�Ʈ �ܰ����� �ݻ�
Ŭ�����θ����

3. �ٸ� ������Ʈ�� �浹��
	3.1 �⺻ ���� ƨ�⵵�� ó��
	3.2 �󼺰��迡 ���� �� Ÿ���� �������� �������� �� ������ ũ��� ����
	3.3 �󼺰��迡 ���� �п� ���ʸ� ���� ũ���
	��>��>�簢��>��
	3.4 ���� ũ�� �̻��� �׳� �������, ���� ũ�� ���ϵ� �׳� ���������
4. 1��Ű ������ �� �ٸ� ������Ʈ �ε����� �ϳ��� ��ü�ؼ� Ŀ���ΰ�
2��Ű ������ �� �ٸ� ������Ʈ �ε�ġ�� �ϳ��� �п��ؼ� �۾�����

5. �������� �簢��, ��, �� �׷�������

6. ���� ȸ���ϵ���

�߰�����. ���� ���� ����Ʈ ����
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

//���̶� �浹
void CCircle0::Collision(RECT rclient, CCircle0 &other)//CCircle0 &other�̰� ���ø����� �ٲٱ�
{
	//���̶� �浹�� ��
	
	if (center.x + R > rclient.right) direction.x *= (-1); 
	if (center.y + R > rclient.bottom)direction.y *= (-1);
	if (center.x - R < rclient.left) direction.x *= (-1); 
	if (center.y - R < rclient.top)direction.y *= (-1);

	const double dis = sqrt(pow(other.getCenter().x - center.x, 2) + pow(other.getCenter().y - center.y, 2));
	
	//������ �浹�� ��
	if (dis <= 2 * R)
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


//�簢��

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
	//�浹
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