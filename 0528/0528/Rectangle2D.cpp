#include "Rectangle2D.h"
#include "math.h"
//(0,0) ,1,1 생성 생성자
Rectangle2D::Rectangle2D() : x(0), y(0), width(1), height(1) {}

//(x,y) ,width,height 생성 생성자
Rectangle2D::Rectangle2D(double x_, double y_, double height_, double width_)
	: x(x_), y(y_), height(height_), width(width_){}

//get상수함수
double Rectangle2D::get(char c) const
{
	if (c = 'x') return x;
	else if (c = 'y') return y;
	else if (c = 'h') return height;
	else if (c = 'w') return width;
}

//set함수
void Rectangle2D::setXY(double *x_, double *y_) 
{ 
	x = *x_; y = *y_; 
}

//set함수
void Rectangle2D::setWH(double *width_, double *height_) 
{
	width = *width_; height = *height_;
}
//면적
double Rectangle2D::getArea() const 
{
	const double s=width * height;
	return s;
}
//둘레
double Rectangle2D::getPerimeter() const 
{
	const double l= width * 2 + height * 2;
	return l;
}

//지정된 점(x,y)가 생성된 사각형 내부에 있을 경우,true를 반환
bool Rectangle2D::contains(double x_, double y_) const 
{
	double bo = y - height / 2;
	if ((x_ > left) && (x_ < right)&& (y_ > bottom) && (y_ < top))return true;
	else return false; 
}

//지정된 직사각형이 생성된 직사각형 내부에 있을 경우,true를 반환
bool Rectangle2D::contains(const Rectangle2D &rec) const 
{
	if ((rec.top <= top) && (rec.bottom >= bottom) && (rec.right <= right ) && (rec.left >= left)) return true;
	else return false;
}
//지정된 원이 생성된 직사각형과 
//중첩되는 경우,true를 반환
bool Rectangle2D::overlaps(const Rectangle2D &rec) const
{

//	if (((rec.top < top) && (rec.left > left)) || ((rec.top < top) && (rec.right > right))|| ((rec.bottom > bottom) && (rec.right > right)) || ((rec.bottom > bottom) && (rec.left < left))) return true;
	if ((rec.top < top) && (rec.bottom > bottom) && (rec.right < right) && (rec.left > left)) return true;
else return false;
}