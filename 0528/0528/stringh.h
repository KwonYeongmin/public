#pragma once
#ifndef STRING!_H
#include <iostream>
using std::ostream;
using std::istream;
class String
{
private:
		char *str;
		int len;
		static int num_strings;
		static const int CINLIM = 80;
public:
	String();
	String(const char *s);
	String(const char &st);
	~String();
	int length() const { return len; }
	//오버로딩 연산자 메서드
	String &operator=(const String &st);
	String &operator=(const char* s);
	char &operator[](int i);
	const char &operator[](int i) const;
	//오버로딩 연산자 프렌드
	friend bool operator<(const String &st1, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st1,const String &st2);
	friend ostream&operator << (std::ostream&os, const String &st);
	friend istream&operator >> (std::ostream&is, String &st);
	//static함수
	static int HowMany();
};

#endif // !STRING!_H


