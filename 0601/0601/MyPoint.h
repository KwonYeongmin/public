#pragma once

#include "Rectangle2D.h"
#include "Circle2D.h"
class MyPoint
{
public:
	MyPoint();
	MyPoint(double x_, double y_);
	double getX() const;
	double getY() const;
	void setX(double *x_);
	void setY(double *y_);
	double distance(const MyPoint& m) const;
	bool isIn(Rectangle2D&) const;
	bool isIn(Circle2D&) const;
private:
	double x;
	double y;
};

