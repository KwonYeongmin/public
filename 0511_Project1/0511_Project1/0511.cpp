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
	cout << "시간 값을 입력하시오 : ";
	cin >> hour;
	int min;
	cout << "분 값을 입력하시오 : ";
	cin >> min;

	input(hour,min);

	return 0;




	distance();

	return 0;
	int temperature;

	cout << "섭씨온도를 입력하고 Enter키를 누르십시오 : ";
	cin >> temperature;
	cout << "섭씨"<<temperature<<"도는 화씨로"<<(float)temperature*1.8+32.0<<"도 입니다 ";

	return 0;


	int age;
	cout << "Enter your age: ";
	cin >> age;
	
	cout << "이때 당신의 나이를 월수로 나타낼 경우"<< age*12 <<" 입니다. ";

	return 0;

	str1();
	str1();
	str2();
	str2();

	return 0;

	int mile;
	float km;

	cout << "입력 :  " ;
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

	cout << "광년 수를 입력하고 Enter키를 누르십시오 : ";
	cin >> lightyears;
	cout<< lightyears<< " 광년은"<< lightyears*63240 <<"천문답위 입니다.";

}

void input(int hour_data, int min_data)
{
	using namespace std;

	cout << "시각 : "<< hour_data <<" : "<< min_data;

}