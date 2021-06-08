

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void reverseDisplay(int value);
void reverseDisplay_s(const string& s);
using
/*
int main()
{
	
	return 0;
	int size;
	int i;
	std::cin >> size;
	int *A = new int[size];
	int *B = new int[size];
	int *C = new int[size];
	A = { 0 };
	B = { 0 };
	C = { 0 };
	for (i = size; i > 0; i--)
	{
		cout << "[" << A[i] << "]\t" << "[" << B[i] << "]\t" << "[" << C[i] << "]\t";
	}

	return 0;
	//문제2
	reverseDisplay_s("Hello");
	return 0;
	//문제1
	reverseDisplay(12345);
	return 0;
}*/
void reverseDisplay(int value)
{
	using namespace std;
	double val;
	val = value % 10;
	value *= 0.1;

	if (val > 10) val = val * 0.1;
	cout << val;
	if (val > 1) reverseDisplay(value);

}

//문제2_2
/*
문자열 값을 역으로 화면에 출력하는 재귀함수를 작성
*/
void reverseDisplay_s(const string& s)
{
	cout << s.begin;
	cout << s.begin;}
	/*
	string str="aaaaa";
	char temp;
	int j,i;
	if (str == "aaaaa") i = s.length();
	else { i = str.length(); }
	
	for (j = 0; j < i; j++)  
	{
		temp=s[j];
		str[j]=temp;
	}
	cout << str[i-1];
	if(str.length() >0) reverseDisplay_s(str);
	 */
