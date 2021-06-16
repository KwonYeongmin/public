
#include <iostream>
#include <fstream>
#include <string>
void splitFile();
void combineFile();

/*
용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는 유틸리티 프로그램을 작성.
사용자로부터 소스 파일을 입력받은 후 
각각 분할된 작은 파일의 바이트 값을 입력받아
해당 크기의 파일로 분할한다.

ex)
Enter file name : test.zip
Enter file size : 1024
-> file Test0.div
-> file Test1.div
-> file Test2.div
....
Split done!
*/

/*
사용자로부터 분할된 소스파일의 개수, 소스파일의 이름, 목적파일의 이름을 입력받아
새로운 하나의 파일로 조합하는 프로그램을 작성
ex 
Enter file number:2
Enter source filename 1: test0.div
Enter source filename 2: test1.div
Enter Target filename : temp.zip
...
combine Done!
*/
using namespace std;





int main()
{
	splitFile();
	return 0;
}




void combineFile()
{
	int number, i;
	string targetname;
	cout << "Enter file number : ";
	cin >> number;
	string *filename = new string[number];
	for (i = 0; i < number; i++)
	{
		cout << "Enter source filename" << i << ": ";
		cin >> filename[i];
	}
	cout << "Enter Target filename : ";
	cin >> targetname;

	//각 파일 사이즈
	int *size = new int[number];

	for (i = 0; i < number; i++)
	{
		ifstream fin(filename[i], ios_base::in | ios_base::binary);
		fin.seekg(0, ios::end);
		size[i] = fin.tellg();
		fin.close();
	}

	for (i = 0; i < number; i++)
	{
		ifstream fin(filename[i], ios_base::in | ios_base::binary);
		ofstream fout(targetname, ios_base::out | ios_base::binary | ios_base::app);
		char *buffer = new char[size[i]];

		fin.read(buffer, size[i]);
		fin.seekg(size[i], ios::beg);
		fout.write(buffer, size[i]);
	}


	cout << "Combine Done!" << endl;

	delete[] filename;
	delete[] size;
}

void splitFile()
{
	char filename[20];
	int filesize;
	streamoff size;
	cout << "Enter file name : ";
	cin >> filename;
	cout << "Enter file size(kb): ";
	cin >> filesize;
	filesize *= 1024;
	//파일 열기
	ifstream fin(filename, ios_base::in | ios_base::binary);

	//파일 사이즈 가지고 오기
	if (fin.is_open())
	{
		cout << "open success!" << endl;
		fin.seekg(0, ios::end);
		size = fin.tellg() ;
		cout << "totoal filesize : " << size / 1024.0 << "kb" << endl;
	}
	else  cout << "파일을 열지 못했습니다." << endl;

	//파일 개수 지정
	double temp = (double)size / (double)filesize;
	int filenum;
	if (temp > (int)temp) filenum = (int)temp + 1;
	else filenum = (int)temp;

	//파일의 크기
	streamoff *fsize = new streamoff[filenum];
	for (int i = 0; i < filenum - 1; i++)
	{
		fsize[i] = filesize;
	}
	fsize[filenum - 1] = size - (filesize*(filenum - 1));

	//생성된 파일 이름 지정 
	string *splitfile = new string[filenum];

	char *buffer = new char[filesize];

	for (int i = 0; i < filenum; i++)
	{
		splitfile[i] = filename + to_string(i) + ".div";
		ofstream fout(splitfile[i], ios_base::out | ofstream::binary);
		
		fin.seekg(fsize[i]  * i, ios::beg);
		fin.read(buffer, fsize[i] );
		fout.write(buffer, fsize[i] );
		cout << "->" << splitfile[i] << endl;
		fout.close();
	}
	cout << "Split done!";
	fin.close();

	delete[] buffer;
	delete[]fsize;
	delete[]splitfile;
}