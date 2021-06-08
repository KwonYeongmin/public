#include "Circle2D.h"
#include <math.h>

Circle2D::Circle2D() : x(0), y(0), radius(1) {}


Circle2D::Circle2D(double x_, double y_, double radius_) : x(x_), y(y_), radius(radius_) {}

//인터페이스 함수
double Circle2D::getX() const { return x; }
double Circle2D::getY() const { return y; }
double Circle2D::getR() const { return radius; }

void Circle2D::setX(double *x_) {x = *x_;}
void Circle2D::setY(double *y_) { y = *y_; }
void Circle2D::setR(double *radius_) { radius = *radius_;}


//원의 면적을 반환
double Circle2D::getArea() const
{
	double s = pow(radius, 2)*3.14;
	return s;
}

//원의 둘레를 반환
double Circle2D::getPerimeter() const
{
	double l = 2 * 3.14*radius;
	return l;
}

//지정된 점(x,y)가 생성된 원 내부에 있을 경우,true를 반환
bool Circle2D::contains(double x_, double y_) const
{
	const double dis = sqrt(pow((x - x_), 2) + pow((y - y_), 2));

	//점과 중심의 거리가 반지름보다 작거나 같을 때
	if (dis <= radius) return true;
	//점과 중심의 거리가 반지름보다 클 때
	else return false;
}

//지정된 원이 생성된 원 내부에 있을 경우,true를 반환
bool Circle2D::contains(const Circle2D &circle) const
{
	Circle2D c;
	const double dis = sqrt(pow((c.x - x), 2) + pow((c.y - y), 2));
	//점과 중심의 거리가 반지름보다 작거나 같을 때
	if (dis <= radius) return true;
	//점과 중심의 거리가 반지름보다 클 때
	else return false;

}

//지정된 원이 생성된 원과 중첩되는 경우,true를 반환
bool Circle2D::overlaps(const Circle2D &circle) const
{
	const double dis = sqrt(pow((circle.x - x), 2) + pow((circle.y - y), 2));
	//중점과 중점사이의 거리가 두 반지름의 합보다 작다
	if (dis < radius + circle.radius) return true;
	else return false;
}

