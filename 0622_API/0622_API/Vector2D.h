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

	double length() { return sqrt(x * x + y * y); }  // 벡터의 크기

	double dot(Vector2D v) { return x * v.x + y * v.y; }  // 벡터의 내적

	Vector2D add(Vector2D v) { return Vector2D(x + v.x, y + v.y); }

	Vector2D sub(Vector2D v) { return Vector2D(x - v.x, y - v.y); }

	Vector2D mul(double val) { return Vector2D(x * val, y * val); }

	Vector2D div(double val) { return Vector2D(x / val, y / val); }

	Vector2D inv() { return Vector2D(x * -1, y * -1); } // 벡터의 역벡터

	double angle(Vector2D v) { return acos(dot(v) / length() * v.length()); } // 두 벡터 사이의 각도


	Vector2D reflection(Vector2D n) // 단위벡터 vertVec
	{
		// 공식: 반사벡터 R = P + (2 x (n x (-Pㆍn)))		
		Vector2D p(x, y);             // 입사벡터 P
		Vector2D mp = p.inv();        // 입사벡터의 역벡터 -P
		double dotVal = mp.dot(n);    // 역벡터와 단위벡터의 내적값 -Pㆍn
		n = n.mul(dotVal);            // 완성된 수직 벡터의 성분 n x (-Pㆍn)
		Vector2D res = p.add(n);  // 반사 벡터 P + (2 x (n x (-Pㆍn)))
		res = res.add(n);

		return res;
	}


	/*
	// 파라미터로 전달된 일반각(Deg)의 방향에 대한 수직벡터를 단위벡터로 리턴한다
	// sin(theta) = y / 빗변  -> 단위벡터 이므로 빗변이 1 -> sin(theta) = y
	// cos(theta) = x / 빗변                            -> cos(theta) = x
	static Vector2D getVertical(double deg)
	{
		double rad = (deg - 90) * PI / 180;
		return Vector2D(cos(rad), sin(rad));
	}
	*/
};
