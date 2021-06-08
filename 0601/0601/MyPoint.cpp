#include "MyPoint.h"
#include <math.h>

MyPoint::MyPoint() :x(0), y(0) {}

MyPoint::MyPoint(double x_, double y_) : x(x_), y(y_) {}

double MyPoint::getX() const { return x; }

double  MyPoint::getY() const { return y; }

void  MyPoint::setX(double *x_) { x = *x_; }
	
void  MyPoint::setY(double *y_) { y = *y_; }

double MyPoint::distance(const MyPoint& m) const
{
	const double dis = sqrt ( pow((m.x - x), 2) + pow((m.y - y), 2) );
	return dis;
}

bool MyPoint::isIn(Circle2D& circle) const
{
	if(circle.contains(x,y) ==1)return true;
	else return false;	 
}

bool MyPoint::isIn(Rectangle2D& rec) const
{
	if (rec.contains(x, y) == 1)return true;
	else return false;
}