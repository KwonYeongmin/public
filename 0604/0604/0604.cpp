
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


//��1 
//�Ǽ��� �Է��ϰ� �̰��� ���ڿ��� ��ȯ�Ͽ� õ������ ','�� �߰��ϰ�
//�Ҽ����� ����ϴ� ���α׷��� �ۼ��Ͽ���

void quiz1() 
{
	int len;
	double number;
	cout << "�Ǽ� �Է�: ";
	cin >> number;
	int i, j;
	//�Ǽ��κ� �Ҽ��κ� �и�
	int itg = number;
	double ft = number - itg;

	//�����κ�����
	string str_itg = to_string(itg);
	cout << "���1: �����κ�" << str_itg << ",  ";
	for (i = 0; i < str_itg.length(); i++) 
	{
		if ((i+4) % 4 == 0) str_itg.insert(str_itg.length()-i, ",");
	}
	str_itg[str_itg.length()-1] = '\0';	
	//�Ҽ��κ�����
	string str = to_string(ft);
	for(i = 0; i < str.length(); i++) 
	{
		char temp;
		str[i] = str[i + 1];
	}
	str[str.length()] = '\0';
	str[0]='\0';
	cout << "�Ҽ��κ�: " << str << endl;
	str[0] = '.';
	//�����κа� �Ҽ��κ� �ٿ��ֱ�
	str.insert(0, str_itg);
	//���
	cout<<"���2: " << str;
}


//��2 
//����ڰ� �Ǽ��� �Է��ϸ� �� �Ǽ��� �м��� ȭ�鿡 ����ϴ� ���α׷���
//�ۼ��϶�.
//(���ڿ��� �о�, ���ڿ��κ��� �����ο� �Ҽ��θ� �����ϰ�,
//�Ǽ��� ���� �������� ���϶�. )
//ex > �Ǽ� : 3.25 (<- �Է�)

//	�м� : 13/4 (<- �Է�)

void quiz2()
{
	std::stringstream ssdouble;

	double number;
	int i, k;

	cout << "�Ǽ� �Է�: ";
	cin >> number;
	//������ �Ҽ� �и�
	int itg = number;
	float ft = number - itg;

	//�Ҽ��κ� ����
	//���� ���ڿ��� �ٲٱ�
	ssdouble << ft;
	string s_ft = ssdouble.str();
	char s_ftt[20];
	for (i = 0; i < s_ft.length() - 2; i++) s_ftt[i] = s_ft[i + 2];
	s_ftt[s_ft.length() - 2] = '\0';
	//cout << "�Ҽ� �κ� ���: " << s_ftt << endl;

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
	cout << "�м� : " << up << "/" << bottom << endl;
}

	
	/*

		cout << "�м� �Է�: ";
		string num;
		getline(cin, num);
		for (i = 0; i < num.length(); i++) 
		{
			if (num[i] == '/') { k = i; break; }
		}
		char itg[80]; char ft[80];
		//����
		for (i = 0; i < k; i++) 
		{
			itg[i] = num[i];
		}
		itg[i] = 'k';
		int int_itg= stof(itg);
		
		//�и�
		for (i = 0; i < num.length()-k; i++)
		{
			ft[i] = num[i+k+1];
		}
		ft[num.length() - k] = '\0';
		int it_ft=stof(ft);
		const double res = (double)int_itg / (double)it_ft;
		cout << "��� "<< res;
		return 1;*/


//�뷡�ϴ´���
/*
#include "worker0.h"
const int LIM = 4;
int main() 
{
	Waiter bob("ȫ�浿", 314L, 5);
	Singer bev("������", 522L, 3);
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

	
	Waiter bob("ȫ�浿", 314L, 5);
	Singer bev("������",522L,3);
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