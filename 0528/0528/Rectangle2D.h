#pragma once
using namespace std;
class Rectangle2D
{
public:
	//(0,0) ,1,1 ���� ������
	Rectangle2D();
	//(x,y) ,width,height ���� ������
	Rectangle2D(double x_, double y_, double height_, double width_);
	//get����Լ�
	double get(char c) const;
	//set�Լ�
	void setXY(double *x_,double *y_);
	//set�Լ�
	void setWH(double *width_, double *height_);
	//����
	double getArea() const;
	//�ѷ�
	double getPerimeter() const;
	//������ ��(x,y)�� ������ �簢�� ���ο� ���� ���,true�� ��ȯ
	bool contains(double x_, double y_) const;
	//������ ���簢���� ������ ���簢�� ���ο� ���� ���,true�� ��ȯ
	bool contains(const Rectangle2D &rec) const;
	//������ ���� ������ ���簢���� ��ø�Ǵ� ���,true�� ��ȯ
	bool overlaps(const Rectangle2D &rec) const;

private:
	//-���簢���� �߽��� ��Ÿ���� x,y��� �ΰ��� double ������ �ʵ�
	double x;
	double y;
	double width;
	double height;
	double right= x + width / 2;
	double left = x - width / 2;
	double top = y + height / 2;
	double bottom = y - height/2;
};

