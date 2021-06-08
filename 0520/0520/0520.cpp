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

	cout << "���ڿ��� �Է�: ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ�: " << input << endl;
	result = version1(input, "***");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
	cout << "�Է��� ���ڿ�: " << input << endl;
	result = version2(input, "###");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	cout << "���� ���ڿ� �缳�� \n" ;
	input = copy;
	result = version3(input, "@@@");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
}


void p506();
const int arSize = 80;
char *left(const char * str, int n = 1);
void p506() 
{
	char sample[arSize];
	cout << "���ڿ��� �Է�: \n";
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



//�Լ� �����ε�
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

//�Լ� ���ø�  p520
int funtemp();

template <typename T> 
void Swap(T &a, T &b);

int funtemp() 
{
	int i = 10;
	int j = 20;
	cout << "i,j =" << i << ", " << j << ".\n";
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ� \n";
	Swap(i, j);
	cout << "���� i,j = " << i << ", " << j << ",\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x,y = " << x << ", " << y << ".\n";
	cout << "�����Ϸ��� ������ double�� ��ȯ�⸦ ����ϸ� \n";
	Swap(x, y);
	cout << "���� x,y = " << x << ", " << y << ",\n";
	return 0;
}

template <typename T> void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b ;
	b=temp;
}

//���ø��� �����ε�
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
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ� \n";
	Swap_v2(i, j);
	cout << "���� i,j = " << i << ", " << "j" << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "�����迭:\n";
	show(d1);
	show(d2);
	Swap_v2(d1, d2, Lim);
	cout << "��ȯ�� �迭:\n";
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

//����� Ư��ȭ
//p528
int twoswap();
template<typename T>void swap_v3(T &a, T &b);


struct job 
{
	char name[40];
	double salary;
	int floor;
};
//����� Ư��ȭ
template<> void swap_v3<job>(job &job1, job &job2);
void show_v3(job &j);
int twoswap()
{ 
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i = 10, j = 20;
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ� \n";
	swap_v3(i, j);
	cout << "���� i,j = " << i << ", " << "j" << ".\n";

	job sue = { "susan Yaffee",73000.60,7 };
	job sidney = { "sidney Taffee",78060.72,9 };
	cout << "��ȯ ��: \n";
	show_v3(sue);
	show_v3(sidney);
	cout << "��ȯ ��: \n";
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
	cout << j.name << ": (" <<j.floor<<"���� ����) " 
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
	//display(accumulate(team, two)); // ��ǻ� ����
	accumulate(team, two);
	accumulate(accumulate(team, two),two);
	display(team);

	//���� ����
	accumulate(dup, five) = four;
	dup=four;

	return 0;

	int wallet1 = 3000;
	int wallet2 = 3500;
	cout << "����1 = " << wallet1 << endl;
	cout << "����2 = " << wallet2 << endl;

	cout << "������ �̿��Ͽ� ���빰 ��ȯ : \n";
	swapr(wallet1,wallet2);
	cout << "����1 = " << wallet1 << endl;
	cout << "����2 = " << wallet2 << endl;

	wallet1 = 3000;
	wallet2 = 3500;
	cout << "�����͸� �̿��Ͽ� ���빰 ��ȯ : \n";
	swapp(&wallet1, &wallet2);
	cout << "����1 = " << wallet1 << endl;
	cout << "����2 = " << wallet2 << endl;

	wallet1 = 3000;
	wallet2 = 3500;
	cout << "���� �̿��Ͽ� ���빰 ��ȯ : \n";
	swapv(wallet1, wallet2);
	cout << "����1 = " << wallet1 << endl;
	cout << "����2 = " << wallet2 << endl;


	return 0;*/

	//�������� ���� ����
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
��1 ��(x,y)�� �Է¹޾� �� ���� (x,y)�� �߽����� �ϰ�
�������� R�� �� ���ο� �����ϴ����� �˻��ϴ� ���α׷� �ۼ�
	ex ����(0,0), R =10�� ���̶�� �� ��
		�� (4,5)�� �� ���ο� �ְ�, 
		�� (9,9)�� �� �ܺο� ��ġ�ϰ� �ִ�.
			�߽� : 0,0
			������ : 10
			�� ��ġ: 4,5
			�� (4,5)�� �� ���ο� �ִ�.
*/
void quiz1() 
{
	int x, y;
	int r = 10;
	cout << "�� ���� �Է��ϼ��� :";
	cin >> x >> y;	
	
	if (sqrt(pow(x, 2) + pow(y, 2)) <= r) 
	{
		cout << "�� (" << x << "," << y << " )" << "�� �� ���ο� �ִ�";
	}
	else 
	{
		cout << "�� (" << x << "," << y << " )" << "�� �� �ܺο� �ִ�";
	}
}
/*
�� 1�� �� �� (x1, y1)�� (x2, y2)
�� 2�� �� �� (x3, y3)�� (x4, y4) �� �־� ���ٰ� ����
�� ���� �������� ���ϴ� ���α׷��� �ۼ�
ũ���� ����
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
	
	
	cout << "�� 4���� �Է� :"<<endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	double a = (y1-y2) / (x1 - x2);
	double b = y1-(y1-y2)/(x1-x2)*x1;
	
	double c = (y3 - y4) / (x3 - x4);
	double d = y3 - (y3 - y4)/(x3 - x4)*x3;
	
	double x= (d - b) / (a - c);
	
	double y = a * x + b;

	
	if(a==c)
	{
		cout << "�� ������ �����̴�";
	}
	else 
	{
		 cout << "�������� ( " << x << " , " << y << " )" << "�̴�." << endl;
	}
	
	

}