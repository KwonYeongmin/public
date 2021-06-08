#include "Rectangle2D.h"
#include "math.h"
//(0,0) ,1,1 ���� ������
Rectangle2D::Rectangle2D() : x(0), y(0), width(1), height(1) {}

//(x,y) ,width,height ���� ������
Rectangle2D::Rectangle2D(double x_, double y_, double height_, double width_)
	: x(x_), y(y_), height(height_), width(width_){}

//get����Լ�
double Rectangle2D::get(char c) const
{
	if (c = 'x') return x;
	else if (c = 'y') return y;
	else if (c = 'h') return height;
	else if (c = 'w') return width;
}

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
	const double s=width * height;
	return s;
}
//�ѷ�
double Rectangle2D::getPerimeter() const 
{
	const double l= width * 2 + height * 2;
	return l;
}

//������ ��(x,y)�� ������ �簢�� ���ο� ���� ���,true�� ��ȯ
bool Rectangle2D::contains(double x_, double y_) const 
{
	double bo = y - height / 2;
	if ((x_ > left) && (x_ < right)&& (y_ > bottom) && (y_ < top))return true;
	else return false; 
}

//������ ���簢���� ������ ���簢�� ���ο� ���� ���,true�� ��ȯ
bool Rectangle2D::contains(const Rectangle2D &rec) const 
{
	if ((rec.top <= top) && (rec.bottom >= bottom) && (rec.right <= right ) && (rec.left >= left)) return true;
	else return false;
}
//������ ���� ������ ���簢���� 
//��ø�Ǵ� ���,true�� ��ȯ
bool Rectangle2D::overlaps(const Rectangle2D &rec) const
{

//	if (((rec.top < top) && (rec.left > left)) || ((rec.top < top) && (rec.right > right))|| ((rec.bottom > bottom) && (rec.right > right)) || ((rec.bottom > bottom) && (rec.left < left))) return true;
	if ((rec.top < top) && (rec.bottom > bottom) && (rec.right < right) && (rec.left > left)) return true;
else return false;
}