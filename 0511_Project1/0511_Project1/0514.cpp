#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <fstream>
#include <Windows.h>
using namespace std;

int quiz_0514();
int file_outfile();
int file_read();
int p368();
//double distance(float x, float y);

int arr_sum(const int *begin, const int *end);
unsigned int c_in_str(const char *str,char ch);
void countdown(int n);
void subdivide(char ar[], int low, int high, int level);

double gildong(int lns);
double moonsoo(int lns);


const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

const double * f1(const double *ar, int n) 
{
	return ar;
}

const double * f2(const double ar[], int n) 
{
	return ar + 1;
}

const double * f3(const double ar[], int n) 
{
	return ar + 2;
}


double gildong(int lns) 
{
	return 0.05*lns;
}
double moonsoo(int lns) 
{
	return 0.03*lns + 0.0004*lns*lns;
}

void estimate(int lines,double (*pf)(int)) 
{
	cout << lines << "���� �ۼ��ϴ� �� ";
	cout << (*pf)(lines) << "�ð��� �ɸ��ϴ�. \n";
}

void subdivide(char ar[], int low, int high, int level) 
{
	if (level == 0) return;
	int mid = (high + low) / 2;
	ar[mid] = 'l';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar,mid,high,level-1);
}
void yes() 
{
	//done������ ������
	char str[120];
	char words[120];
	int cnt = 0;
	cout << "���� �ܾ���� �Է��Ͻʽÿ�(�������� done�� �Է�) :" << endl;
	cin >> str;
	int i = 0;int k = 0;
	//while(1)
	//{
		
		while (1)
		{
			words[k] = str[i];
			
			if (str[i] == NULL) words[k] = 0; break; 
			i++;
			k++;
		}
		cnt++;
		cout << k << endl;
		cout << words[k - 2] << endl;
		cout << words[k - 1] << endl;
		cout << words[k] << endl;
		//cout << words << endl;

		//if (strcmp(words, "done") == 0) break;

	//}
			
		//cout << cnt<<endl;
		//cout << strcmp(words, "done");




	//n���� 10����
	//cctype �̿��ؼ�

}

/*
int main()
{
	using namespace std;

//p451
	double av[3] = {1112.3,1542.6,2227.9};
	const double *(*p1)(const double *, int) = f1;

	return 0;
	
	yes();
	
	return 0;
	
	//p446
	int code;
	cout << "�ʿ��� �ڵ��� �� ���� �Է��Ͻʽÿ� : " << endl;
	cin >> code;
	cout << "ȫ�浿�� �ð� ���� \n";
	estimate(code, gildong);
	cout << "�ڹ����� �ð� ���� \n";
	estimate(code, moonsoo);

	return 0;

	//p441
	const int Len = 66;
	const int Divs = 6;
	
	char ruler[Len];
	int i;
	for(i=1;i<Len-2;i++) ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max]='l';
	cout << ruler << endl; //����
	for(i=1;i<=Divs;i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2; j++) { ruler[j] = ' '; }
	}


	//

	//quiz_0514();

	//���� �Է� �� ���
	//file_outfile();

	//���� �б� --> å�� �ٸ�,,,
	//file_read();
	return 0;

	//p369��������
	p368();
	return 0;

	//p439
	countdown(4);

	return 0;
	//p416
	/*
	char mmm[15] = "minumum";
	//char pwail[15] = "ululate";
	//char *wail = pwail;
	const char *wail = "ululate";
	//char *pWail = new {"ululate"};
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "���� m�� " << ms << "�� ����ֽ��ϴ�. \n";
	cout << wail << "���� u�� " << us << "�� ����ֽ��ϴ�. \n";
	
	return 0;
*/
	/*
	//p406 �迭 ������ ����ϴ� �Լ� 
	const int ArSize = 8;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	return 0;

	//p406 �迭 ������ ����ϴ� �Լ� ����
	
	const int nSize = 3;
	int arr[nSize] = { 1,2,3 };
	cout<<arr_sum(arr, arr + nSize);
	
	return 0;
}


*/


//����

int p368() //����
{
	//4��
	const int strsize = 80;
	
	struct bop
	{
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference; // 0=full, 1=title, 2 = bop
	};
	/*
	ofstream File_info;
	File_info.open("info.txt");
	*/
	bop bopType[5] = 
	{
		{"Wimp Macho","X","X",0},
		{"Raki Rhodes","Junior Programmer","X",1},
		{"Celia Laiter","X","MIPS",2},
		{"Hoppy Hipman","Abalyst Trainee","X",1},
		{"Pat Hand","X","LOOPY",2}
	};

	cout << "Benevolent order of Programmers" << endl;
	cout << "a. �Ǹ����� ����         " << "b. �������� ����" << endl;
	cout << "c. BOP ���̵�� ����     " << "d. ȸ���� ������ ������ ����" << endl;
	cout << "q. ����     " << endl;
	cout << "���ϴ� ���� �����Ͻʽÿ� : " ;
	char index =0;
	cin >> index;
	/*
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	*/
		if (index='a') 
		{
			for(int i=0;i<5;i++) cout << bopType[i].fullname << endl;
		}
		else if (index = 'b')
		{
			for (int i = 0; i < 5; i++) cout << bopType[i].title << endl;
			//for (int i = 0; i < 5; i++) File_info << bopType[i].title;
		}
		else if (index = 'c') 
		{
			//for (int i = 0; i < 5; i++) File_info << bopType[i].bopname;
			for (int i = 0; i < 5; i++) cout << bopType[i].bopname;
		}
		else if (index = 'd') 
		{
			for (int i = 0; i < 5; i++) 
			{
				if (bopType[i].preference == 0) { cout << bopType[i].bopname; }//File_info << bopType[i].bopname; }
				else if (bopType[i].preference == 1) { cout << bopType[i].title; } //File_info << bopType[i].title;
				else if (bopType[i].preference == 2) { cout << bopType[i].bopname; } // File_info << bopType[i].bopname;
			}		
		}
		else if (index = 'q') { cout << "���α׷��� �����մϴ�. "; return 0; }
}

int quiz_0514()
{
	//����3
	/*
	�ﰢ�� 3���� ��(x1, y1), (x2, y2), (x3, y3)�� �Է��Ͽ�
	������ ���ϴ� ���α׷�
	s = (side1+side2+side3)/2
	���� = root(s(s-side1)(s-side2)(s-side2))
	1.5 -3.4 4.6 5 9.5 -3.4 //33.6
	*/

	return 0;
	
	//����2
/*
�� ��(x1,y1)�� �� ��(x2,y2)�� �Է¹޾� �� �� �� ������ �Ÿ���
����ϴ� ���α׷� �ۼ�.
*/
	/*
	float x1,x2,y1,y2;
	cout << "�� ���� ��ǥ�� �Է��ϼ���"<<endl; 
	cout << "x1 �Է� ";
	cin >> x1;
	cout << "y1 �Է� ";
	cin >> y1;
	cout << "x2 �Է� ";
	cin >> x2;
	cout << "y2 �Է� ";
	cin >> y2;
	
	const double distance = sqrt(pow(x2-x1,2)+(pow(y2 - y1,2)));
	cout << "�� �� ������ �Ÿ���" << distance;

	return 0;
	*/
	//����1
/*
������� ���ӵ� a�� �̷��ӵ� v�� �־����� ��,
���� ������ ����Ͽ� ����Ⱑ �̷��ϱ� ���� 
�ּ� Ȱ�� ���̸� ����ϴ� ���α׷�
���� = v^2 / 2a
����ڿ��� m/2������ v�� m/s^2������ a�� �Է��ϵ���
�˷��ְ�, �ּ� Ȱ�� ���̸� ����ϴ� ���α׷� �ۼ�

ex > Speed and Accelation : 60 3.5
	 Minimum runway length : 514.286 m
*/
	float acc, speed;// , length;

	
	cout << "�̷��ӵ�(m/s)�� �Է��Ͻÿ� : ";
	cin >> speed	;	
	cout << "���ӵ�(m/s^2)�� �Է��Ͻÿ� : ";
	cin >> acc;

	const double length = pow(speed,2) / (2 * acc);
	cout << "�ּ� Ȱ�� ���� : " << length << "m";

	return 0;
}


//���� �����
int file_outfile() 
{
	//p352
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ�";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ�";
	cin >> year;
	cout << "���� ������ �Է��Ͻÿ�";
	cin >> a_price;
	d_price = 0.913 * a_price;

	//cout << fixed;
	//cout.precision(2);
	//cout.setf(ios_base::showpoint);

	/*
	cout << "����Ŀ�� ����: "<<automobile<<endl;
	cout << "����: " << year << endl;
	cout << "���� ���� : " << a_price << endl;
	cout << "���� ���� : "<<d_price<<endl;
	*/
	
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ����: " << automobile << endl;
	outFile << "����: " << year << endl;
	outFile << "���� ���� : " << a_price << endl;
	outFile << "���� ���� : " << d_price << endl;
	
	outFile.close();
	return 0;
}
int file_read() 
{
	const int  SIZE = 60;
	char filename[SIZE];
	ifstream inFile;
	cout << "������ ������ �̸��� �Է��Ͻÿ�";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open()) 
	{
		cout << filename << " ������ �� �� �����ϴ�. " << endl;
		cout  << " ���α׷��� �����մϴ�. \n" ;
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good()) 
	{
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof()) cout << "���� ���� �����߽��ϴ�. \n";
	else if (inFile.fail()) cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�. \n";
	else cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�. \n";

	if (count == 0) cout << "�����Ͱ� �����ϴ�. \n";
	else 
	{
		cout << "���� �׸��� ����: " << count << endl;
		cout << "�հ�: " << sum << endl;
		cout << "���: " <<sum/count<<endl;
	}

	inFile.close();
	return 0;
}



//p416
unsigned int c_in_str(const char *str, char ch)
{
	int count = 0;
	while (*str) 
	{
		if (*str == ch) 
		{
			count++;
		}
		str++;
	}
	return count;
}

//p439
void countdown(int n) 
{
	Sleep(1000);
	cout << "ī��Ʈ�ٿ� ... " << n << endl;
	if (n > 0) { countdown(n - 1); }
	cout << n << " : kaboom \n";
}
//p406 �迭 ������ ����ϴ� �Լ� 
int sum_arr(const int *begin, const int *end)
{
	return 0;
}

//p406 �迭 ������ ����ϴ� �Լ� ����
int arr_sum(const int *begin, const int *end)
{
	const int *pt;
	int tot = 0;
	for (pt = begin; pt < end; pt++)
	{
		tot += *pt;
	}

	return tot;
}
