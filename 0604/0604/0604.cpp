
#include<iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <string.h>
using namespace std;
void quiz1();
void quiz2();
int main() 
{
	quiz2();
	//quiz1();
	return 0;
}


//문1 
//실수를 입력하고 이것을 문자열로 변환하여 천단위로 ','를 추가하고
//소수점을 출력하는 프로그램을 작성하여라

void quiz1() 
{
	int len;
	double number;
	cout << "실수 입력: ";
	cin >> number;
	int i, j;
	//실수부분 소수부분 분리
	int itg = number;
	double ft = number - itg;

	//정수부분정리
	string str_itg = to_string(itg);
	cout << "출력1: 정수부분" << str_itg << ",  ";
	for (i = 0; i < str_itg.length(); i++) 
	{
		if ((i+4) % 4 == 0) str_itg.insert(str_itg.length()-i, ",");
	}
	str_itg[str_itg.length()-1] = '\0';	
	//소수부분정리
	string str = to_string(ft);
	for(i = 0; i < str.length(); i++) 
	{
		char temp;
		str[i] = str[i + 1];
	}
	str[str.length()] = '\0';
	str[0]='\0';
	cout << "소수부분: " << str << endl;
	str[0] = '.';
	//정수부분과 소수부분 붙여주기
	str.insert(0, str_itg);
	//출력
	cout<<"출력2: " << str;
}


//문2 
//사용자가 실수를 입력하면 그 실수를 분수로 화면에 출력하는 프로그램을
//작성하라.
//(문자열을 읽어, 문자열로부터 정수부와 소수부를 추출하고,
//실수에 대한 유리수를 구하라. )
//ex > 실수 : 3.25 (<- 입력)

//	분수 : 13/4 (<- 입력)

void quiz2()
{
	std::stringstream ssdouble;

	double number;
	int i, k;

	cout << "실수 입력: ";
	cin >> number;
	//정수와 소수 분리
	int itg = number;
	float ft = number - itg;

	//소수부분 정리
	//숫자 문자열로 바꾸기
	ssdouble << ft;
	string s_ft = ssdouble.str();
	char s_ftt[20];
	for (i = 0; i < s_ft.length() - 2; i++) s_ftt[i] = s_ft[i + 2];
	s_ftt[s_ft.length() - 2] = '\0';
	//cout << "소수 부분 출력: " << s_ftt << endl;

	int bottom = pow(10, strlen(s_ftt));
	int up = bottom * ft + bottom * itg;
	int pp;
	int gg = bottom * ft;
	for (i = 2; i < gg + 1; i++)
	{
		if ( (bottom % i == 0)&&( gg % i ==0)) pp = i;
	}
	bottom = bottom / pp;
	up = bottom * ft + bottom * itg;
	cout << "분수 : " << up << "/" << bottom << endl;
}

	
	/*

		cout << "분수 입력: ";
		string num;
		getline(cin, num);
		for (i = 0; i < num.length(); i++) 
		{
			if (num[i] == '/') { k = i; break; }
		}
		char itg[80]; char ft[80];
		//분자
		for (i = 0; i < k; i++) 
		{
			itg[i] = num[i];
		}
		itg[i] = 'k';
		int int_itg= stof(itg);
		
		//분모
		for (i = 0; i < num.length()-k; i++)
		{
			ft[i] = num[i+k+1];
		}
		ft[num.length() - k] = '\0';
		int it_ft=stof(ft);
		const double res = (double)int_itg / (double)it_ft;
		cout << "결과 "<< res;
		return 1;*/


//노래하는닭털
/*
#include "worker0.h"
const int LIM = 4;
int main() 
{
	Waiter bob("홍길동", 314L, 5);
	Singer bev("조수미", 522L, 3);
	SingingWaiter newhire("Madon",2005,6,soprano);
	SingingWaiter sw_temp;
	Worker *pw[LIM] = { &bob,&bev,&bbb,&sw_temp };
	int i;
	for (i = 3; i < LIM; i++)
	{
		pw[i]->Set();
	}
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	return 0;

	
	Waiter bob("홍길동", 314L, 5);
	Singer bev("조수미",522L,3);
	Waiter w_temp;
	Singer s_temp;

	Worker*pw[LIM] = { &bob,&bev,&w_temp,&s_temp };
	int i;
	for (i = 2; i < LIM; i++) 
	{
		pw[i]->Set();
	}
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	return 0;
	
}*/