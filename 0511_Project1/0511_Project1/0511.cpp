#include <iostream>
void str1();
void str2();
void distance();
void input(int hour_data,int min_data);

/*
int main() 
{
	using namespace std;

	int hour;
	cout << "�ð� ���� �Է��Ͻÿ� : ";
	cin >> hour;
	int min;
	cout << "�� ���� �Է��Ͻÿ� : ";
	cin >> min;

	input(hour,min);

	return 0;




	distance();

	return 0;
	int temperature;

	cout << "�����µ��� �Է��ϰ� EnterŰ�� �����ʽÿ� : ";
	cin >> temperature;
	cout << "����"<<temperature<<"���� ȭ����"<<(float)temperature*1.8+32.0<<"�� �Դϴ� ";

	return 0;


	int age;
	cout << "Enter your age: ";
	cin >> age;
	
	cout << "�̶� ����� ���̸� ������ ��Ÿ�� ���"<< age*12 <<" �Դϴ�. ";

	return 0;

	str1();
	str1();
	str2();
	str2();

	return 0;

	int mile;
	float km;

	cout << "�Է� :  " ;
	cin >> mile;
	km = (float)mile * 1.60934; 
	cout << km << "km " << endl;


}*/

void str1() 
{
	using namespace std;
	cout << "Three blind mice"<< endl;

}

void str2()
{
	using namespace std;
	cout << "see how they run" << endl;

}

void distance() 
{
	using namespace std;
	double lightyears;

	cout << "���� ���� �Է��ϰ� EnterŰ�� �����ʽÿ� : ";
	cin >> lightyears;
	cout<< lightyears<< " ������"<< lightyears*63240 <<"õ������ �Դϴ�.";

}

void input(int hour_data, int min_data)
{
	using namespace std;

	cout << "�ð� : "<< hour_data <<" : "<< min_data;

}