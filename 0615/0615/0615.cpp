// 0615.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void password();

const char *file = "guests.txt";
int main()
{
	
	char ch;
	ifstream fin;
	fin.open(file);
	if (fin.is_open()) 
	{
		cout << file << "파일의 현재 내용은 다음과 같습니다.:\n";
		while (fin.get(ch)) cout << ch;
		fin.close();
	}
	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "출력을 위해" << file << "파일을 열수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	cout << "새로운 손님 이름들을 입력하십시오(끝내려면 빈줄 입력): \n";
	string name;
	while (getline(cin, name) && name.size() > 0) 
	{
		fout << name << endl;
	}
	fout.close();
	fin.clear();
	fin.open(file);
	if (fin.is_open()) 
	{
		cout << file << "파일의 개정된 내용은 다음과 같습니다.:\n";
		while (fin.get(ch)) cout << ch;
		fin.close();
	}
	cout << "프로그램을 종료합니다.";
		
		return 0;

	
	/*
	int input;
	int sum = 0;
	while (cin >> input) 
	{
		sum += input;
	}
	cout << "마지막으로 입력한 값 : " << input << endl;
	cout << "마지막으로 입력한 값 : " << sum << endl;*/
}

void password() 
{
	string filename;
	cout << "새 파일을 위한 이름 입력: ";
	cin >> filename;
	ofstream fout(filename.c_str());
	fout << "비밀 번호 노출에 주의하십시오.\n";
	cout << "비밀 번호를 입력: ";
	fout << "귀하의 비밀번호는 ";
	//문자로 읽기,,,


	while (1)
	{
		char temp;
		cin >> temp;
		if (temp == 13) break;
		fout << temp;
	}
	cout << "입니다.\n";
	fout.close();

	ifstream fin_(filename.c_str());
	cout << filename << " 파일의 내용은 다음과 같습니다.\n";
	char ch_;
	while (fin_.get(ch_)) cout << ch_;
	cout << "프로그램을 종료합니다.\n";
	fin_.close();
}