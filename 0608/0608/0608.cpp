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
	cout << "������ ���� �Է�: ";
	cin >> l;

	int n;
	cout << "���ε��� ���� �Է�: ";
	cin >> n;
	int *v = new int[n];
	
	cout << "���ε��� ��ġ �Է�: ";
	for ( i = 0; i < n;i++ ) cin >> v[i];


	//����
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
	//�Ÿ��� max��
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
	cout << "int ī��Ʈ:" << HasFriend<int>::ct << "; ";
	cout << "double ī��Ʈ:" << HasFriend<double>::ct << endl;
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
	cout << "��ü�� ������� �ʾҴ�: ";
	counts();
	HasFriend<int>hfi1(10);
	cout << "hfi1 ������: ";
	counts();
	HasFriend<int>hfi2(20);
	cout << "hfi2 ���� ��: ";
	counts(); 
	HasFriend<double>hfdb(10.5);
	cout << "hfdb������: ";
	counts();
	report(hfi1);
	report(hfi2);
	report(hfdb);
	return 0;
	/*
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "4 3.5�� ���� int double���� �Է��϶�(�������� 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0) 
	{
		if (!nebula.push(ni, nb)) break;
	}

	while (nebula.pop(ni, nb)) cout << ni << ", " << nb << endl;
	cout << "���α׷��� �����մϴ�.\n";

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
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n"
		<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�. \n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n') continue;
		if (!isalpha(ch)) { cout << '\a'; continue; }

		switch (ch)
		{
		case 'A':
		case 'a':cout << "�߰��� �ֹ����� ��ȣ�� �Է�: ";
			cin >> po;
			if (st.isfull()) cout << "������ ���� �� �ֽ��ϴ�.\n";
			else st.push(po);
			break;
		case 'p':
		case 'P':
			if (st.isempty()) cout << "������ ����ֽ��ϴ�\n";
			else { st.pop(po); cout << "#" << po << "�ֹ����� ó���߽��ϴ�."; break; }

		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n"
			<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�,\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	
}*/

//p1064

/*void stkoptr() 
{
	const int Num = 10;
	srand(time(0));
	cout << "������ũ���Է�:";
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


