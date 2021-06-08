#include "complex0.h"
#include <iostream>
Complex::Complex() :A(0),B(0)
{
	
}
Complex::Complex(int a, int b) : A(a), B(b)
{

}

//º¹¼Ò¼ö µ¡¼À
Complex Complex::operator+(const Complex &f) const 
{
	Complex sum;
	
	sum.A = f.A + A;
	sum.B = f.B + B;
	Show(sum.A, sum.B);
	return sum;
}
//º¹¼Ò¼ö »¬¼À
Complex Complex::operator-(const Complex &f) const 
{
	Complex diff;
	return diff;
}
//º¹¼Ò¼ö °ö¼À
Complex Complex::operator*(const Complex &f) const 
{
	Complex multi;
	return multi;
}
//º¹¼Ò¼ö ½Ç¼ö °ö¼À 
Complex Complex::operator=(double n) const 
{
	Complex fmulti;
	return fmulti;
}
//°ø¾× º¹¼Ò¼ö
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

