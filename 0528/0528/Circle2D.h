#pragma once
class Circle2D
{
public:
	//(x, y)��(0, 0), radius�� 1�� �⺻ ���� �����ϴ� �μ� ���� ������
	Circle2D();
	//������ x,y,radius�� ���� �����ϴ� ������
	Circle2D(double x_, double y_, double radius_);

	//���� ������ ��ȯ
	double getArea() const;
	//���� �ѷ��� ��ȯ
	double getPerimeter() const;
	//������ ��(x,y)�� ������ �� ���ο� ���� ���,true�� ��ȯ
	bool contains(double x_, double y_) const;
	//������ ���� ������ �� ���ο� ���� ���,true�� ��ȯ
	bool contains(const Circle2D &circle) const;
	//������ ���� ������ ���� ��ø�Ǵ� ���,true�� ��ȯ
	bool overlaps(const Circle2D &circle) const;
	
		//�������̽� �Լ�
	//���� �߽��� ��Ÿ���� x�� y��� �ΰ��� double ������ �ʵ�� get��� �Լ�
	double get(char ch) const;
	
	void setXY(double *x_, double *y_) ;
	void setRadius(double *radius_);

private:
	double radius;
	double x;
	double y;
};

//���� �ܺ� �Ǵ� �ϳ�
//���� �ϳ� �׷����� �� �� �ȿ� �Ǵٸ� ���� ���Դ°� �ƴѰ�
//���� �ٸ� ���� ��ġ�°� �Ȱ�ġ�°�


