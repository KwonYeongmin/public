#include "complex0.h"
#include <iostream>
Complex::Complex() :A(0),B(0)
{
	
}
Complex::Complex(int a, int b) : A(a), B(b)
{

}

//���Ҽ� ����
Complex Complex::operator+(const Complex &f) const 
{
	Complex sum;
	
	sum.A = f.A + A;
	sum.B = f.B + B;
	Show(sum.A, sum.B);
	return sum;
}
//���Ҽ� ����
Complex Complex::operator-(const Complex &f) const 
{
	Complex diff;
	return diff;
}
//���Ҽ� ����
Complex Complex::operator*(const Complex &f) const 
{
	Complex multi;
	return multi;
}
//���Ҽ� �Ǽ� ���� 
Complex Complex::operator=(double n) const 
{
	Complex fmulti;
	return fmulti;
}
//���� ���Ҽ�
Complex Complex::operator/(const Complex &f) const
{
	Complex m;
	
	m.B= f.B *(-1);
	m.A = f.A;

	Show(m.A,m.B);
	return m;
}
void Complex :: Show(int a, int b)const
{

	cout << "(" << a << "," << b << "i)"<<endl;
}

