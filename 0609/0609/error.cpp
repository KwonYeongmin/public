/*
#include <iostream>
#include <cmath>
#include "exc_mean.h"
using namespace std;

void update(int number) 
{
	
	if(number%2==0)cout << "짝수" << endl;//cout << number<<endl;
	else throw "홀수";

}

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

double hmean(double a, double b) 
{
	if (a == -b) throw bad_hmean(a, b);
	return 2.0*a*b / (a+b);
}

double gmean(double a, double b)
{
	if (a<0||b<0) throw bad_gmean(a, b);
	return sqrt(a * b);
}
int main()
{
	double x, y, z;
	cout << "두 수를 입력: ";
	while (cin >> x >> y)
	{
		try 
		{
			z = hmean(x, y); 
			cout << x << ",  " << y << " 의 조화 평균은"
				<< z << "입니다.\n";
			cout << x << ",  " << y << " 의 기하 평균은"
				<< gmean(x,y) << "입니다.\n";
			cout << "다른 두수를 입력하십시오(끝내려면 q)";
		}
		catch (bad_hmean &bh) 
		{
			bh.mesg();
			cout << "다시 하십시오:" << endl;
			continue;
		}
		catch (bad_gmean &bg) 
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", "
				<< bg.v2 << endl;
			cout << "죄송합니다. 더 이상 진행 할 수 없습니다.\n";
			break;
		}
	}
	cout << "프로그램을 종료합니다\n";

	return 0;

	int number;
	cin >> number;

	try { update(number); }
	catch (const char *s) { cout << s << endl; }

	return 0;
}*/