#pragma once
class Circle2D
{
public:
	//(x, y)가(0, 0), radius가 1인 기본 원을 생성하는 인수 없는 생성자
	Circle2D();
	//지정된 x,y,radius로 원을 생성하는 생성자
	Circle2D(double x_, double y_, double radius_);

	//원의 면적을 반환
	double getArea() const;
	//원의 둘레를 반환
	double getPerimeter() const;
	//지정된 점(x,y)가 생성된 원 내부에 있을 경우,true를 반환
	bool contains(double x_, double y_) const;
	//지정된 원이 생성된 원 내부에 있을 경우,true를 반환
	bool contains(const Circle2D &circle) const;
	//지정된 원이 생성된 원과 중첩되는 경우,true를 반환
	bool overlaps(const Circle2D &circle) const;
	
		//인터페이스 함수
	//원의 중심을 나타내는 x와 y라는 두개의 double 데이터 필드와 get상수 함수
	double get(char ch) const;
	
	void setXY(double *x_, double *y_) ;
	void setRadius(double *radius_);

private:
	double radius;
	double x;
	double y;
};

//내부 외부 판단 하나
//원이 하나 그려지면 그 원 안에 또다른 원이 들어왔는가 아닌가
//원과 다른 원이 겹치는가 안겹치는가


