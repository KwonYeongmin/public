#pragma once
#include "framework.h"
const double PI = 3.1415926;

class Vector2D
{
private:
	double x, y;

public:
	Vector2D() {  }

	Vector2D(double _x, double _y) : x(_x), y(_y) {  }

	double GetX() { return x; }

	double GetY() { return y; }

	void SetX(double _x) { x = _x; }

	void SetY(double _y) { y = _y; }

	double length() { return sqrt(x * x + y * y); }  // ������ ũ��

	double dot(Vector2D v) { return x * v.x + y * v.y; }  // ������ ����

	Vector2D add(Vector2D v) { return Vector2D(x + v.x, y + v.y); }

	Vector2D sub(Vector2D v) { return Vector2D(x - v.x, y - v.y); }

	Vector2D mul(double val) { return Vector2D(x * val, y * val); }

	Vector2D div(double val) { return Vector2D(x / val, y / val); }

	Vector2D inv() { return Vector2D(x * -1, y * -1); } // ������ ������

	double angle(Vector2D v) { return acos(dot(v) / length() * v.length()); } // �� ���� ������ ����


	Vector2D reflection(Vector2D n) // �������� vertVec
	{
		// ����: �ݻ纤�� R = P + (2 x (n x (-P��n)))		
		Vector2D p(x, y);             // �Ի纤�� P
		Vector2D mp = p.inv();        // �Ի纤���� ������ -P
		double dotVal = mp.dot(n);    // �����Ϳ� ���������� ������ -P��n
		n = n.mul(dotVal);            // �ϼ��� ���� ������ ���� n x (-P��n)
		Vector2D res = p.add(n);  // �ݻ� ���� P + (2 x (n x (-P��n)))
		res = res.add(n);

		return res;
	}


	/*
	// �Ķ���ͷ� ���޵� �Ϲݰ�(Deg)�� ���⿡ ���� �������͸� �������ͷ� �����Ѵ�
	// sin(theta) = y / ����  -> �������� �̹Ƿ� ������ 1 -> sin(theta) = y
	// cos(theta) = x / ����                            -> cos(theta) = x
	static Vector2D getVertical(double deg)
	{
		double rad = (deg - 90) * PI / 180;
		return Vector2D(cos(rad), sin(rad));
	}
	*/
};
