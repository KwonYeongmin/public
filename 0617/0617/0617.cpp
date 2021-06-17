#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*
문1
파일 내의 모든 바이트에 5를 더하도록 해서 부호화(encoding) 하여라
사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
입력 파일의 암호화된 버전을 출력파일로 저장하는 프로그램을 작성.

ex)	input source filename : source.txt
	input encoding filename : encoding.txt


문2
암호화된 파일을 복호화 하는 프로그램을 작성.
사용자가 입력 파일 이름과 출력 파일 이름을 입력하면 입력 파일의 암호가
풀린 버전을 출력 파일로 저장하는 프로그램을 작성.*/

using namespace std;

int main()
{

	//encoding();
	//decoding();
	return 0;
    
}


void decoding()
{
	string sourcename;
	string desname;
	int size;
	cout << "input source filename : ";
	cin >> sourcename;
	cout << "input decoding filename : ";
	cin >> desname;
	ifstream fin(sourcename, ios_base::in | ios_base::binary);
	ofstream fout(desname, ios_base::out | ios_base::binary);

	if (fin.is_open())
	{
		cout << "open success!" << endl;
		fin.seekg(0, ios::end);
		size = fin.tellg();
	}

	char buffer;// = new char[size];
	int buf;// = new int[size];

	for (int i = 0; i < size; i++)
	{
		fin.seekg(i, ios::beg);
		fin.read(&buffer, sizeof(char));
		buffer -= 5;
		fout.write(&buffer, sizeof(char));
	}

	fout.close();
	fin.close();
	cout << "decoding done!" << endl;
}
void encoding()
{
	string sourcename;
	string desname;
	int size;
	cout << "input source filename : ";
	cin >> sourcename;
	cout << "input encoding filename : ";
	cin >> desname;
	ifstream fin(sourcename, ios_base::in | ios_base::binary);
	ofstream fout(desname, ios_base::out | ios_base::binary);

	if (fin.is_open())
	{
		cout << "open success!" << endl;
		fin.seekg(0, ios::end);
		size = fin.tellg();
	}

	char buffer;// = new char[size];

	for (int i = 0; i < size; i++)
	{
		fin.seekg(i, ios::beg);
		fin.read(&buffer, sizeof(char));
		buffer += 5;
		fout.write(&buffer, sizeof(char));
	}

	fout.close();
	fin.close();
	cout << "encoding done!" << endl;
}