#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	int A;
	int B;
	
public :
	Complex();
	Complex(int a, int b);
	
	Complex operator+(const Complex &f) const;
	Complex operator-(const Complex &f) const;
	Complex operator*(const Complex &f) const;
	Complex operator=(double n) const;
	Complex operator/(const Complex &f) const;
	void Show(int a, int b)const;
};

