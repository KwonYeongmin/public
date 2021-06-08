#pragma once
using namespace std;
class Rectangle2D
{
public:

	Rectangle2D();
	Rectangle2D(double x_, double y_, double height_, double width_);
	double getX() const;
	double getY() const;
	double getW() const;
	double getH() const;
	void setXY(double *x_, double *y_);
	void setWH(double *width_, double *height_);
	double getArea() const;
	double getPerimeter() const;
	bool contains(double x_, double y_) const;
	bool contains(const Rectangle2D &rec) const;
	bool overlaps(const Rectangle2D &rec) const;

private:
	double x;
	double y;
	double width;
	double height;
	double right = x + width / 2;
	double left = x - width / 2;
	double top = y + height / 2;
	double bottom = y - height / 2;
};


