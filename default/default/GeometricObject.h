#pragma once
class GeometricObject
{
protected:
	double x;
	double y;
public:
	GeometricObject();
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual bool contains(double x_,double y_) const;
	virtual bool contains() const;
	virtual bool overlaps() const;
	double getX() const;
	double getY() const;
	void setX(double x_);
	void setY(double y_);
};
class Rectangle2D : public GeometricObject
{
public:
	Rectangle2D();
	Rectangle2D(double x_, double y_,double height_,double width_);
	double getWidth() const;
	double getHeight() const;
	void setWidth(double *width_);
	void setHeight(double *height_);

	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual bool contains(double x_, double y_) const;
	virtual bool contains(const  Rectangle2D &rec) const;
	virtual bool overlaps(const  Rectangle2D &rec) const;
private:
	double width;
	double height;
	double right = x + width / 2;
	double left = x - width / 2;
	double top = y + height / 2;
	double bottom = y - height / 2;
};

class Circle2D :public GeometricObject 
{
private:
	double radius;
public:
	Circle2D();
	Circle2D(double x_,double y_,double radius_);
	double getRadius() const;
	void setRadius(double radius_) ;

	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual bool contains(double x_, double y_) const;
	virtual bool contains(const Circle2D &circle) const;
	virtual bool overlaps(const Circle2D &circle) const;
};

class MyPoint : public GeometricObject
{
public:
	MyPoint();
	MyPoint(double x_, double y_);
	double distance(const MyPoint& m);
	bool isIn(const Rectangle2D& rec) const;
	bool isIn(const Circle2D& circle) const;
};


