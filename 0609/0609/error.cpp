/*
#include <iostream>
#include <cmath>
#include "exc_mean.h"
using namespace std;

void update(int number) 
{
	
	if(number%2==0)cout << "¦��" << endl;//cout << number<<endl;
	else throw "Ȧ��";

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
	cout << "�� ���� �Է�: ";
	while (cin >> x >> y)
	{
		try 
		{
			z = hmean(x, y); 
			cout << x << ",  " << y << " �� ��ȭ �����"
				<< z << "�Դϴ�.\n";
			cout << x << ",  " << y << " �� ���� �����"
				<< gmean(x,y) << "�Դϴ�.\n";
			cout << "�ٸ� �μ��� �Է��Ͻʽÿ�(�������� q)";
		}
		catch (bad_hmean &bh) 
		{
			bh.mesg();
			cout << "�ٽ� �Ͻʽÿ�:" << endl;
			continue;
		}
		catch (bad_gmean &bg) 
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", "
				<< bg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ���� �� �� �����ϴ�.\n";
			break;
		}
	}
	cout << "���α׷��� �����մϴ�\n";

	return 0;

	int number;
	cin >> number;

	try { update(number); }
	catch (const char *s) { cout << s << endl; }

	return 0;
}*/