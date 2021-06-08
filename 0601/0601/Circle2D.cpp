#include "Circle2D.h"
#include <math.h>

Circle2D::Circle2D() : x(0), y(0), radius(1) {}


Circle2D::Circle2D(double x_, double y_, double radius_) : x(x_), y(y_), radius(radius_) {}

//�������̽� �Լ�
double Circle2D::getX() const { return x; }
double Circle2D::getY() const { return y; }
double Circle2D::getR() const { return radius; }

void Circle2D::setX(double *x_) {x = *x_;}
void Circle2D::setY(double *y_) { y = *y_; }
void Circle2D::setR(double *radius_) { radius = *radius_;}


//���� ������ ��ȯ
double Circle2D::getArea() const
{
	double s = pow(radius, 2)*3.14;
	return s;
}

//���� �ѷ��� ��ȯ
double Circle2D::getPerimeter() const
{
	double l = 2 * 3.14*radius;
	return l;
}

//������ ��(x,y)�� ������ �� ���ο� ���� ���,true�� ��ȯ
bool Circle2D::contains(double x_, double y_) const
{
	const double dis = sqrt(pow((x - x_), 2) + pow((y - y_), 2));

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
	if (dis < radius + circle.radius) return true;
	else return false;
}

