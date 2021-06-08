#include <iostream>
#include <math.h>
#include "GeometricObject.h"

	//GeometricObject
//인터페이스 함수 2개
GeometricObject::GeometricObject() {}
double GeometricObject::getX() const { return x; }

double GeometricObject::getY() const {return y;}

void GeometricObject::setX(double x_) {x = x_;}

void GeometricObject::setY(double y_) {y = y_;}

//재정의 함수 5개

double GeometricObject::getArea() const {return false;}
double GeometricObject::getPerimeter() const {return false;}
bool GeometricObject::contains(double x_, double y_) const {return false;}
bool GeometricObject::contains() const {return false;}
bool GeometricObject::overlaps() const {return false;}


	//circle2D
//생성자 2개
Circle2D::Circle2D() { x = 0;  y = 0;  radius = 1; }
Circle2D::Circle2D(double x_, double y_, double radius_)  
{
	x = x_; y = y_; radius = radius_;
}
//인터페이스 함수
double Circle2D::getRadius() const { return radius; }
void Circle2D::setRadius(double radius_) { radius = radius_; }
//재정의 함수 5개 
double Circle2D::getArea() const
{
	double s = pow(radius, 2)*3.14;
	return s;
}
double Circle2D::getPerimeter() const
{
	double l = 2 * 3.14*radius;
	return l;
}
bool Circle2D::contains(double x_, double y_) const
{
	const double dis = sqrt(pow((x - x_), 2) + pow((y - y_), 2));
	if (dis <= radius) return true;
	else return false;
}

bool Circle2D::contains(const Circle2D &circle) const
{
	const double dis = sqrt(pow((circle.x - x), 2) + pow((circle.y - y), 2));
	if (dis <= radius) return true;
	else return false;
}

bool Circle2D::overlaps(const Circle2D &circle) const
{
	const double dis = sqrt(pow((circle.x - x), 2) + pow((circle.y - y), 2));
	if (dis < radius + circle.radius) return true;
	else return false;
}

	//Rectangle2D
//생성자 2개
Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}
Rectangle2D::Rectangle2D(double x_, double y_, double height_, double width_) 
{
	x = x_; y = y_;
	height = height_; width = width_;
}
//인터페이스 함수 4개
double Rectangle2D::getWidth() const {return width;}
double Rectangle2D::getHeight() const { return height; }
void Rectangle2D::setWidth(double *width_) { width = *width_; }
void Rectangle2D::setHeight(double *height_) { height = *height_; }

//재정의함수5개
double Rectangle2D::getArea() const 
{
	const double s = width * height;
	return s;
}
double Rectangle2D::getPerimeter() const 
{
	const double l = width * 2 + height * 2;
	return l;
}
bool Rectangle2D::contains(double x_, double y_) const 
{
	double bo = y - height / 2;
	if ((x_ > left) && (x_ < right) && (y_ > bottom) && (y_ < top))return true;
	else return false;
}
bool Rectangle2D::contains(const Rectangle2D &rec) const
{
	if ((rec.top <= top) && (rec.bottom >= bottom) && (rec.right <= right) && (rec.left >= left)) return true;
	else return false;
}

bool Rectangle2D::overlaps(const Rectangle2D &rec) const
{
	if ((rec.top < top) && (rec.bottom > bottom) && (rec.right < right) && (rec.left > left)) return true;
	else return false;
}

	//MyPoint
//생성자 2개
MyPoint::MyPoint() { x = 0; y = 0; }
MyPoint::MyPoint(double x_, double y_) { x = x_; y = y_; }

double MyPoint::distance(const MyPoint& m)
{
	const double dis = sqrt(pow((m.x - x), 2) + pow((m.y - y), 2));
	return dis;
}
bool MyPoint::isIn(const Rectangle2D& rec) const
{
	if (rec.contains(x, y) == 1)return true;
	else return false;
}
bool MyPoint::isIn(const Circle2D& circle) const
{
	if (circle.contains(x, y) == 1)return true;
	else return false;
}