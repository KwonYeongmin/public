#include <iostream>
#include <cmath>
#include <string>

using namespace std;
void quiz1();
void quiz2();

void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);


struct free_throws 
{
		string name;
		int made;
		int attempts;
		float percent;
};
void p495();
string version1(const string & s1, const string & s2);
const string & version2(const string & s1, const string & s2);
const string & version3(const string & s1, const string & s2);

string version1(const string & s1, const string & s2) 
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}
const string & version2( string & s1, const string & s2) 
{
	s1 = s2 + s1 + s2;
	return s1;
}
const string & version3(string & s1, const string & s2) 
{
	string temp;

	temp= s2 + s1 + s2;
	return temp;
}
void p495()
{
	string input;
	string copy;
	string result;

	cout << "문자열을 입력: ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열: " << input << endl;
	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	cout << "입력한 문자열: " << input << endl;
	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	cout << "원래 문자열 재설정 \n" ;
	input = copy;
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
}


void p506();
const int arSize = 80;
char *left(const char * str, int n = 1);
void p506() 
{
	char sample[arSize];
	cout << "문자열을 입력: \n";
	cin.get(sample, arSize);
	char *ps = left(sample, 4);
	cout << ps << endl;
	delete[ ] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[ ] ps;
}
char *left(const char * str, int n )
{
	if(n<0) n = 0;
	char *p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++) p[i] = str[i];
	while (i <= n) p[i++] = '\0';
	return p;
}



//함수 오버로딩
int p514();
unsigned long left_(unsigned long num, unsigned ct);
char * left_(const char *str,int n=1);


int p514() 
{
	const char * trip="dsdasd";
	unsigned long n = 12345678;
	int i;
	char *temp;
	for (i = 1; i < 10; i++)
	{
		cout << left_(n, i) << endl;
		temp = left_(trip, i);
		cout << temp << endl;
		delete[] temp;
	}
	return 0;
}

unsigned long left_(unsigned long num, unsigned ct) 
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0) return 0;
	while (n /= 10) digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
		{
			num /= 10;
			return num;
		}
	}
	else
	{
		return num;
	}
	
}

char * left_(const char *str, int n)
{
	if (n < 0)n = 0;
	char *p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++) p[i] = str[i];
	while (i <= n) p[i++] = '\0';
	return p;
}

//void display(const free_throws &ft);
//void set_pc(free_throws &ft);
//free_throws &accumulate(free_throws &target, const free_throws &source);

/*
void display(const free_throws &ft) 
{
}

void set_pc(free_throws &ft) 
{
}

free_throws &accumulate(free_throws &target) {}*/

//함수 템플릿  p520
int funtemp();

template <typename T> 
void Swap(T &a, T &b);

int funtemp() 
{
	int i = 10;
	int j = 20;
	cout << "i,j =" << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면 \n";
	Swap(i, j);
	cout << "이제 i,j = " << i << ", " << j << ",\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x,y = " << x << ", " << y << ".\n";
	cout << "컴파일러가 생성한 double형 교환기를 사용하면 \n";
	Swap(x, y);
	cout << "이제 x,y = " << x << ", " << y << ",\n";
	return 0;
}

template <typename T> void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b ;
	b=temp;
}

//템플릿의 오버로딩
//p522
int twotemps();
template <typename T> void Swap_v2(T &a, T &b);
template <typename T> void Swap_v2(T a[], T b[],int n);
void show(int a[]);
const int Lim = 8;
int twotemps()
{
	int i = 10, j = 20;
	cout << "i,j =" << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면 \n";
	Swap_v2(i, j);
	cout << "이제 i,j = " << i << ", " << "j" << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "원본배열:\n";
	show(d1);
	show(d2);
	Swap_v2(d1, d2, Lim);
	cout << "교환된 배열:\n";
	show(d1);
	show(d2);
	return 0;
}

template <typename T> void Swap_v2(T &a, T &b) 
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <typename T> void Swap_v2(T a[], T b[], int n) 
{
	T temp;
	for (int i = 0; i < n; i++) 
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	
}

void show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[0] << a[1] << "/";
	for (int i = 4; i < Lim; i++) cout << a[i];
	cout << endl;
}

//명시적 특수화
//p528
int twoswap();
template<typename T>void swap_v3(T &a, T &b);


struct job 
{
	char name[40];
	double salary;
	int floor;
};
//명시적 특수화
template<> void swap_v3<job>(job &job1, job &job2);
void show_v3(job &j);
int twoswap()
{ 
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i = 10, j = 20;
	cout << "컴파일러가 생성한 int형 교환기를 사용하면 \n";
	swap_v3(i, j);
	cout << "이제 i,j = " << i << ", " << "j" << ".\n";

	job sue = { "susan Yaffee",73000.60,7 };
	job sidney = { "sidney Taffee",78060.72,9 };
	cout << "교환 전: \n";
	show_v3(sue);
	show_v3(sidney);
	cout << "교환 후: \n";
	show_v3(sue);
	show_v3(sidney);

	return 0; 
}

template<typename T>void swap_v3(T &a, T &b) 
{
	T temp;
	 temp=a;
	a = b;
	b = temp;
}
template<> void swap_v3<job>(job &j1, job &j2) 
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;

}
void show_v3(job &j) 
{
	cout << j.name << ": (" <<j.floor<<"층에 거주) " 
		<< "$"<<j.salary<<endl;
}


int main() 
{
	twoswap();
	return 0;
	funtemp();
	return 0;
	p506();
	return 0;
	p495();
	return 0;
	quiz2();
	return 0;
	/*
	free_throws one;
	free_throws two;
	free_throws four;
	free_throws five;
	free_throws team;
	free_throws dup;

	display(one);
	//display(accumulate(team, two)); // 사실상 같다
	accumulate(team, two);
	accumulate(accumulate(team, two),two);
	display(team);

	//둘이 같다
	accumulate(dup, five) = four;
	dup=four;

	return 0;

	int wallet1 = 3000;
	int wallet2 = 3500;
	cout << "지갑1 = " << wallet1 << endl;
	cout << "지갑2 = " << wallet2 << endl;

	cout << "참조를 이용하여 내용물 교환 : \n";
	swapr(wallet1,wallet2);
	cout << "지갑1 = " << wallet1 << endl;
	cout << "지갑2 = " << wallet2 << endl;

	wallet1 = 3000;
	wallet2 = 3500;
	cout << "포인터를 이용하여 내용물 교환 : \n";
	swapp(&wallet1, &wallet2);
	cout << "지갑1 = " << wallet1 << endl;
	cout << "지갑2 = " << wallet2 << endl;

	wallet1 = 3000;
	wallet2 = 3500;
	cout << "값을 이용하여 내용물 교환 : \n";
	swapv(wallet1, wallet2);
	cout << "지갑1 = " << wallet1 << endl;
	cout << "지갑2 = " << wallet2 << endl;


	return 0;*/

	//참조변수 개념 정리
	int rats = 101;
	int &rodents1 = rats;
	int *pr = &rats;
	int rodents2 = rats;

	rats = 102;
	cout << rodents1 << endl;
	cout << &rodents1 << endl;
	cout << rodents2 << endl;
	cout << &rodents2 << endl;
	cout << rats<< endl;
	cout << &rats << endl;
	cout << *pr << endl;
	cout << pr << endl;
	cout << &pr << endl;

	
	return 0;
	quiz1();
}

void swapr(int &a, int &b) 
{
	int temp;
	temp = a;
	a = b;
	b=temp;

}

void swapp(int *p, int *q) 
{
	int temp;
	temp = *p;
	*p = *q;
	*q= temp;
}

void swapv(int a, int b) 
{
	int temp;
	temp = a;
	a=b;
	b = temp;
}


/*
문1 점(x,y)를 입력받아 그 점이 (x,y)를 중심으로 하고
반지름이 R인 원 내부에 존재하는지를 검사하는 프로그램 작성
	ex 중점(0,0), R =10인 원이라고 할 때
		점 (4,5)는 원 내부에 있고, 
		점 (9,9)는 원 외부에 위치하고 있다.
			중심 : 0,0
			반지름 : 10
			점 위치: 4,5
			점 (4,5)는 원 내부에 있다.
*/
void quiz1() 
{
	int x, y;
	int r = 10;
	cout << "두 점을 입력하세요 :";
	cin >> x >> y;	
	
	if (sqrt(pow(x, 2) + pow(y, 2)) <= r) 
	{
		cout << "점 (" << x << "," << y << " )" << "는 원 내부에 있다";
	}
	else 
	{
		cout << "점 (" << x << "," << y << " )" << "는 원 외부에 있다";
	}
}
/*
선 1의 두 점 (x1, y1)과 (x2, y2)
선 2의 두 점 (x3, y3)과 (x4, y4) 로 주어 진다고 하자
두 선의 교차점을 구하는 프로그램을 작성
크래머 공식
(y1-y2)x-(x1-x2)y = (y1-y2)x1-(x1-x2)y1
(y3-y4)x-(x3-x4)y = (y3-y4)x3-(x3-x4)y3

2
2
5
-1.0
4.0
2.0
-1.0
-2.0
(x,y)=(2.88889,1.11111)
*/
void quiz2() 
{
	double x1, y1,x2,y2,x3,y3,x4,y4;
	
	
	cout << "점 4개를 입력 :"<<endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	double a = (y1-y2) / (x1 - x2);
	double b = y1-(y1-y2)/(x1-x2)*x1;
	
	double c = (y3 - y4) / (x3 - x4);
	double d = y3 - (y3 - y4)/(x3 - x4)*x3;
	
	double x= (d - b) / (a - c);
	
	double y = a * x + b;

	
	if(a==c)
	{
		cout << "두 직선은 평행이다";
	}
	else 
	{
		 cout << "교차점은 ( " << x << " , " << y << " )" << "이다." << endl;
	}
	
	

}