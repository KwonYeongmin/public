#pragma once
#include<iostream>
#ifndef STRNGBAD_H_

class StringBad
{

private:
	char *str;
	int len;
	static int num_strings;
public:
	StringBad();
	~StringBad();
	StringBad(const char *s);
	
	//ÇÁ·»µå ÇÔ¼ö
	friend std::ostream&operator<<(std::ostream&OS, const StringBad &st);
};

#endif // !STRNGBAD_H_



