#include<iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "stacktp.h"
using namespace std;
//void stacktem();

int light_distance()
{
	int i, j;
	long l;
	cout << "도로의 길이 입력: ";
	cin >> l;

	int n;
	cout << "가로등의 개수 입력: ";
	cin >> n;
	int *v = new int[n];
	
	cout << "가로등의 위치 입력: ";
	for ( i = 0; i < n;i++ ) cin >> v[i];


	//정렬
	for (i = 0; i < n - 1; i++)
	{
		int ck = 0;
		for (j = n - 1; j > i; j--)
		{
			if (v[j] < v[j - 1])
			{
				int temp = v[j];
				v[j] = v[j - 1];
				v[j-1]=temp;
				ck++;
			}
		}
		if (ck == 0)break;
	}
	int d=0;
	double dis;

	int *vv = new int[n-1];
	for (i = 0; i < n - 1; i++) 
	{
		vv[i] = v[i+1] - v[i];
		//cout << i << ": " << vv[i] << endl;
	}
	//거리의 max값
	int max = vv[0];
	for (i = 0; i < n - 2; i++) 
	{
		if (max < vv[i]) max = vv[i];
	}
	dis = (double)max/2.0;
	d = max/2;

	if (dis > d) d += 1;
	
	delete[] v; 
	return d;
	
	
}


//p1083
template <template <typename T> class Thing>
class Crab 
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int &a, double &x) { return s1.pop(a) && s2.pop(x); }
};

//p1087

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T &i) : item(i) { ct++; }
	HasFriend() { ct--; }
	friend void counts();
	friend void report(HasFriend<T> &);
};
template <typename T>
int HasFriend<T>::ct = 0;

void counts() 
{
	cout << "int 카운트:" << HasFriend<int>::ct << "; ";
	cout << "double 카운트:" << HasFriend<double>::ct << endl;
}

void report(HasFriend<int> &hf) 
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

void report(HasFriend<double> &hf) 
{
	cout << "HasFriend<couble>: " << hf.item << endl;
}




int main() 
{
	cout << "객체가 선언되지 않았다: ";
	counts();
	HasFriend<int>hfi1(10);
	cout << "hfi1 선언후: ";
	counts();
	HasFriend<int>hfi2(20);
	cout << "hfi2 선언 후: ";
	counts(); 
	HasFriend<double>hfdb(10.5);
	cout << "hfdb선언후: ";
	counts();
	report(hfi1);
	report(hfi2);
	report(hfdb);
	return 0;
	/*
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "4 3.5와 같이 int double쌍을 입력하라(끝내려면 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0) 
	{
		if (!nebula.push(ni, nb)) break;
	}

	while (nebula.pop(ni, nb)) cout << ni << ", " << nb << endl;
	cout << "프로그램을 종료합니다.\n";

	return 0;
	cout<<"d: "<<light_distance();
	
	return 0;*/
}

//p1056
/*
void stacktem()
{
	Stack<string> st;
	char ch;
	string po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n"
		<< "종료하러면 Q를 입력하십시오. \n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n') continue;
		if (!isalpha(ch)) { cout << '\a'; continue; }

		switch (ch)
		{
		case 'A':
		case 'a':cout << "추가할 주문서의 번호를 입력: ";
			cin >> po;
			if (st.isfull()) cout << "스택이 가득 차 있습니다.\n";
			else st.push(po);
			break;
		case 'p':
		case 'P':
			if (st.isempty()) cout << "스택이 비어있습니다\n";
			else { st.pop(po); cout << "#" << po << "주문서를 처리했습니다."; break; }

		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n"
			<< "종료하러면 Q를 입력하십시오,\n";
	}
	cout << "프로그램을 종료합니다.\n";
	
}*/

//p1064

/*void stkoptr() 
{
	const int Num = 10;
	srand(time(0));
	cout << "스택의크기입력:";
	int  stacksize;
	cin >> stacksize;
	Stack<const char *>st(stacksize);
	
	const char * in[Num] = { "1:f","2:f","3:f","4:f","5:f","6:f","7:f","8:f","9:f","10:f" };

	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num) 
	{
		if (st.isempty()) st.push(in[nextin++]);
		else if (st.isfull()) st.pop(out[processed++]);
		else if (rand() % 2 && nextin < Num) st.push(in[processed++]);
		else  st.pop(out[processed++]);
	}
}*/


