#include "Circle2D.h"
#include <math.h>
//(x, y)��(0, 0), radius�� 1�� �⺻ ���� �����ϴ� �μ� ���� ������
Circle2D::Circle2D() 
{
	x = 0; 
	y = 0;
	radius = 1;
}


//������ x,y,radius�� ���� �����ϴ� ������
Circle2D::Circle2D(double x_, double y_, double radius_) 
{
	x = x_;
	y = y_;
	radius = radius_;
}

	//�������̽� �Լ�
	//���� �߽��� ��Ÿ���� x�� y��� �ΰ��� double ������ �ʵ�� get��� �Լ�
double Circle2D::get(char ch) const
{
	if (ch == 'x') return x;
	else if (ch == 'y') return y;
	else if(ch=='r') return radius;
}



void Circle2D::setXY(double *x_, double *y_)
{
	x = *x_;
	y = *y_;
}

//double ������ �ʵ� radius�� get ����Լ�
/*
Circle2D Circle2D::getRadius(const Circle2D &circle) const
{

}*/
void Circle2D::setRadius(double *radius_)
{
	radius = *radius_;
}


//���� ������ ��ȯ
double Circle2D::getArea() const 
{
	double s=pow(radius, 2)*3.14;
	return s;
}

//���� �ѷ��� ��ȯ
double Circle2D::getPerimeter() const 
{
	double l=2*3.14*radius;
	return l;
}

//������ ��(x,y)�� ������ �� ���ο� ���� ���,true�� ��ȯ
bool Circle2D::contains(double x_, double y_) const 
{
	const double dis=sqrt(pow((x - x_), 2) + pow((y - y_), 2));

	//���� �߽��� �Ÿ��� ���������� �۰ų� ���� ��
	if (dis <= radius) return true;
	//���� �߽��� �Ÿ��� ���������� Ŭ ��
	else return false;
}

//������ ���� ������ �� ���ο� ���� ���,true�� ��ȯ
bool Circle2D::contains(const Circle2D &circle) const 
{
	Circle2D c;
	const double dis = sqrt(pow((c.x - x), 2) + pow((c.y - y), 2));
	//���� �߽��� �Ÿ��� ���������� �۰ų� ���� ��
	if (dis <= radius) return true;
	//���� �߽��� �Ÿ��� ���������� Ŭ ��
	else return false;

}

//������ ���� ������ ���� ��ø�Ǵ� ���,true�� ��ȯ
bool Circle2D::overlaps(const Circle2D &circle) const 
{
	const double dis = sqrt(pow((circle.x - x), 2) + pow((circle.y - y), 2));
	//������ ���������� �Ÿ��� �� �������� �պ��� �۴�
	if (dis < radius+ circle.radius) return true;
	else return false;
}

