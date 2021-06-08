#include "Rectangle2D.h"
#include "math.h"
//(0,0) ,1,1 ���� ������
Rectangle2D::Rectangle2D() : x(0), y(0), width(1), height(1) {}

//(x,y) ,width,height ���� ������
Rectangle2D::Rectangle2D(double x_, double y_, double height_, double width_)
	: x(x_), y(y_), height(height_), width(width_) {}

//get����Լ�
double Rectangle2D::getX() const { return x; }
double Rectangle2D::getY() const { return y; }
double Rectangle2D::getW() const { return width; }
double Rectangle2D::getH() const { return height; }

//set�Լ�
void Rectangle2D::setXY(double *x_, double *y_)
{
	x = *x_; y = *y_;
}

//set�Լ�
void Rectangle2D::setWH(double *width_, double *height_)
{
	width = *width_; height = *height_;
}
//����
double Rectangle2D::getArea() const
{
	const double s = width * height;
	return s;
}
//�ѷ�
double Rectangle2D::getPerimeter() const
{
	const double l = width * 2 + height * 2;
	return l;
}

//������ ��(x,y)�� ������ �簢�� ���ο� ���� ���,true�� ��ȯ
bool Rectangle2D::contains(double x_, double y_) const
{
	double bo = y - height / 2;
	if ((x_ > left) && (x_ < right) && (y_ > bottom) && (y_ < top))return true;
	else return false;
}

//������ ���簢���� ������ ���簢�� ���ο� ���� ���,true�� ��ȯ
bool Rectangle2D::contains(const Rectangle2D &rec) const
{
	if ((rec.top <= top) && (rec.bottom >= bottom) && (rec.right <= right) && (rec.left >= left)) return true;
	else return false;
}
//������ ���� ������ ���簢���� 
//��ø�Ǵ� ���,true�� ��ȯ
bool Rectangle2D::overlaps(const Rectangle2D &rec) const
{
	if ((rec.top < top) && (rec.bottom > bottom) && (rec.right < right) && (rec.left > left)) return true;
	else return false;
}