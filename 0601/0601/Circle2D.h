
#pragma once
class Circle2D
{
public:

	Circle2D();
	Circle2D(double x_, double y_, double radius_);
	double getArea() const;
	double getPerimeter() const;
	bool contains(double x_, double y_) const;
	bool contains(const Circle2D &circle) const;
	bool overlaps(const Circle2D &circle) const;

	double getX() const;
	double getY() const;
	double getR() const;

	void setX(double *x_);
	void setY(double *y_);
	void setR(double *radius_);

private:
	double radius;
	double x;
	double y;
};
