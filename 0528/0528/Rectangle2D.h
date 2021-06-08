#pragma once
using namespace std;
class Rectangle2D
{
public:
	//(0,0) ,1,1 생성 생성자
	Rectangle2D();
	//(x,y) ,width,height 생성 생성자
	Rectangle2D(double x_, double y_, double height_, double width_);
	//get상수함수
	double get(char c) const;
	//set함수
	void setXY(double *x_,double *y_);
	//set함수
	void setWH(double *width_, double *height_);
	//면적
	double getArea() const;
	//둘레
	double getPerimeter() const;
	//지정된 점(x,y)가 생성된 사각형 내부에 있을 경우,true를 반환
	bool contains(double x_, double y_) const;
	//지정된 직사각형이 생성된 직사각형 내부에 있을 경우,true를 반환
	bool contains(const Rectangle2D &rec) const;
	//지정된 원이 생성된 직사각형과 중첩되는 경우,true를 반환
	bool overlaps(const Rectangle2D &rec) const;

private:
	//-직사각형의 중심을 나타내는 x,y라는 두개의 double 데이터 필드
	double x;
	double y;
	double width;
	double height;
	double right= x + width / 2;
	double left = x - width / 2;
	double top = y + height / 2;
	double bottom = y - height/2;
};

