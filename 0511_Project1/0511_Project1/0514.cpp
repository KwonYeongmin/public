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
	cout << lines << "행을 작성하는 데 ";
	cout << (*pf)(lines) << "시간이 걸립니다. \n";
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
	//done나오면 끝내기
	char str[120];
	char words[120];
	int cnt = 0;
	cout << "영어 단어들을 입력하십시오(끝내려면 done을 입력) :" << endl;
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




	//n진수 10진수
	//cctype 이용해서

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
	cout << "필요한 코드의 행 수를 입력하십시오 : " << endl;
	cin >> code;
	cout << "홍길동의 시간 예상 \n";
	estimate(code, gildong);
	cout << "박문수의 시간 예상 \n";
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
	cout << ruler << endl; //띄어쓰기
	for(i=1;i<=Divs;i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2; j++) { ruler[j] = ' '; }
	}


	//

	//quiz_0514();

	//파일 입력 및 출력
	//file_outfile();

	//파일 읽기 --> 책과 다름,,,
	//file_read();
	return 0;

	//p369연습문제
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
	cout << mmm << "에는 m이 " << ms << "개 들어있습니다. \n";
	cout << wail << "에는 u이 " << us << "개 들어있습니다. \n";
	
	return 0;
*/
	/*
	//p406 배열 범위를 사용하는 함수 
	const int ArSize = 8;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	return 0;

	//p406 배열 범위를 사용하는 함수 예시
	
	const int nSize = 3;
	int arr[nSize] = { 1,2,3 };
	cout<<arr_sum(arr, arr + nSize);
	
	return 0;
}


*/


//문제

int p368() //문제
{
	//4번
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
	cout << "a. 실명으로 열람         " << "b. 직함으로 열람" << endl;
	cout << "c. BOP 아이디로 열람     " << "d. 회원이 지정한 것으로 열람" << endl;
	cout << "q. 종료     " << endl;
	cout << "원하는 것을 선택하십시오 : " ;
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
		else if (index = 'q') { cout << "프로그램을 종료합니다. "; return 0; }
}

int quiz_0514()
{
	//문제3
	/*
	삼각형 3개의 점(x1, y1), (x2, y2), (x3, y3)을 입력하여
	면적을 구하는 프로그램
	s = (side1+side2+side3)/2
	면적 = root(s(s-side1)(s-side2)(s-side2))
	1.5 -3.4 4.6 5 9.5 -3.4 //33.6
	*/

	return 0;
	
	//문제2
/*
두 점(x1,y1)과 두 점(x2,y2)를 입력받아 이 두 점 사이의 거리를
출력하는 프로그램 작성.
*/
	/*
	float x1,x2,y1,y2;
	cout << "두 점의 좌표를 입력하세요"<<endl; 
	cout << "x1 입력 ";
	cin >> x1;
	cout << "y1 입력 ";
	cin >> y1;
	cout << "x2 입력 ";
	cin >> x2;
	cout << "y2 입력 ";
	cin >> y2;
	
	const double distance = sqrt(pow(x2-x1,2)+(pow(y2 - y1,2)));
	cout << "두 점 사이의 거리는" << distance;

	return 0;
	*/
	//문제1
/*
비행기의 가속도 a와 이륙속도 v가 주어졌을 때,
다음 공식을 사용하여 비행기가 이륙하기 위한 
최소 활주 길이를 계산하는 프로그램
길이 = v^2 / 2a
사용자에게 m/2단위로 v와 m/s^2단위로 a를 입력하도록
알려주고, 최소 활주 길이를 출력하는 프로그램 작성

ex > Speed and Accelation : 60 3.5
	 Minimum runway length : 514.286 m
*/
	float acc, speed;// , length;

	
	cout << "이륙속도(m/s)를 입력하시오 : ";
	cin >> speed	;	
	cout << "가속도(m/s^2)를 입력하시오 : ";
	cin >> acc;

	const double length = pow(speed,2) / (2 * acc);
	cout << "최소 활주 길이 : " << length << "m";

	return 0;
}


//파일 입출력
int file_outfile() 
{
	//p352
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "자동차 메이커와 차종을 입력하시오";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오";
	cin >> year;
	cout << "구입 가격을 입력하시오";
	cin >> a_price;
	d_price = 0.913 * a_price;

	//cout << fixed;
	//cout.precision(2);
	//cout.setf(ios_base::showpoint);

	/*
	cout << "메이커와 차종: "<<automobile<<endl;
	cout << "연식: " << year << endl;
	cout << "구입 가격 : " << a_price << endl;
	cout << "현재 가격 : "<<d_price<<endl;
	*/
	
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종: " << automobile << endl;
	outFile << "연식: " << year << endl;
	outFile << "구입 가격 : " << a_price << endl;
	outFile << "현재 가격 : " << d_price << endl;
	
	outFile.close();
	return 0;
}
int file_read() 
{
	const int  SIZE = 60;
	char filename[SIZE];
	ifstream inFile;
	cout << "데이터 파일의 이름을 입력하시오";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open()) 
	{
		cout << filename << " 파일을 열 수 없습니다. " << endl;
		cout  << " 프로그램을 종료합니다. \n" ;
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
	if (inFile.eof()) cout << "파일 끝에 도달했습니다. \n";
	else if (inFile.fail()) cout << "데이터 불일치로 입력이 종료되었습니다. \n";
	else cout << "알 수 없는 이유로 입력이 종료되었습니다. \n";

	if (count == 0) cout << "데이터가 없습니다. \n";
	else 
	{
		cout << "읽은 항목의 개수: " << count << endl;
		cout << "합계: " << sum << endl;
		cout << "평균: " <<sum/count<<endl;
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
	cout << "카운트다운 ... " << n << endl;
	if (n > 0) { countdown(n - 1); }
	cout << n << " : kaboom \n";
}
//p406 배열 범위를 사용하는 함수 
int sum_arr(const int *begin, const int *end)
{
	return 0;
}

//p406 배열 범위를 사용하는 함수 예시
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
