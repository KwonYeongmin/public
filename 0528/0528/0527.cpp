#include<iostream>
#include "Circle2D.h"
#include "Rectangle2D.h"
#include "strngbad.h"
using namespace std;

void callme1(StringBad &);
void callme2(StringBad);

void callme1(StringBad &rsb) 
{
	cout << "������ ���޵�\n";
	cout<<"    \""<<rsb<<"\"\n";
}
void callme2(StringBad sb) 
{
	cout << "������ ���޵�\n";
	cout << "    \"" << sb << "\"\n";
}

void Print(const int size, int *A, int*B, int *C, int cnt)
{cout << "Ƚ�� " << cnt << endl;
	for (int i = size-1; i >= 0; i--)
	{
		
		cout << "[" << A[i] << "]\t" << "[" << B[i] << "]\t" << "[" << C[i] << "]\t" << endl;
	}
}

void xx(int size,int n, int *A, int *B, int *C,int cnt)
{	
	/*
		if ((A[index[0] - 1] < B[index[1] - 1]) || B[0] == 0)
		{
			B[index[1]] = A[index[0] - 1];
			A[index[0] - 1] = 0;
			index[1]++;
			index[0]--;
			//break;
		}
		if (A[index[0] - 1] < C[index[2] - 1] || C[0] == 0)
		{
			C[index[2]] = A[index[0] - 1];
			A[index[0] - 1] = 0;
			index[2]++;
			index[0]--;
			//break;
		}
		if (B[index[1] - 1] < A[index[0] - 1] || A[0] == 0)
		{
			A[index[0]] = B[index[1] - 1];
			B[index[1] - 1] = 0;
			index[0]++;
			index[1]--;
			//break;
		}
		if (B[index[1] - 1] < C[index[2] - 1] || C[0] == 0)
		{
			C[index[2]] = B[index[1] - 1];
			B[index[1] - 1] = 0;
			index[2]++;
			index[1]--;
			//break;
		}
		if (C[index[2] - 1] < A[index[0] - 1] || A[0] == 0)
		{
			A[index[0]] = C[index[2] - 1];
			C[index[2] - 1] = 0;
			index[0]++;
			index[2]--;
			//break;
		}
		if (C[index[2] - 1] < B[index[1] - 1] || B[0] == 0)
		{
			B[index[1]] = C[index[2] - 1];
			C[index[2] - 1] = 0;
			index[1]++;
			index[2]--;
			//break;

	}

	*/
	//���� index
	//������ �� index-1
	

	//A 4�� B 2��
	//A 8�� B 5�� C 2�� 
	
	/*
	C[0] = A[2];
	A[2] = 0;
	
	B[0] = A[1];
	A[1] = 0;
	
	B[1] = C[0];
	C[0] = 0;
	
	C[0] = A[0];
	A[0] = 0;
	
	B[1] = A[0];
	B[1] = 0;
	
	C[1] = B[0];
	B[0] = 0;
	
	C[2] = A[0];
	A[0] = 0;
	
	B[0] = A[3];
	A[3] = 0;

	C[0] = A[2];
	A[2] = 0;

	C[1] = B[0];
	B[0] = 0;
	
	B[0] = A[1];
	A[1] = 0;

	A[1] = C[1];
	C[1] = 0;

	B[1] = C[0];
	C[0] = 0;

	B[2] = A[1];
	A[1] = 0;

	B[2] = A[1];
	A[1] = 0;

	C[0] = A[0];
	A[0] = 0;

	A[0] = B[2];
	B[2] = 0;

	C[1] = B[1];
	B[1] = 0;

	C[1] = B[1];
	B[1] = 0;
	//3
	B[0] = A[1];
	A[1] = 0;

	C[2] = A[0];
	A[0] = 0;

	C[3] = B[0];
	B[0] = 0;*/
	
	Print(size, A, B, C,cnt++);
	//while(index[2]!=size) 
	
}

int main()
{
	int size;
	cin >> size;
	int *index = new int[size];
	int *A = new int[size];
	int *B = new int[size];
	int *C = new int[size];
	for (int i = 0; i < size; i++)
	{
		A[i] = size - i; B[i] = 0; C[i] = 0;
		if (1 != 0) index[i] = 0;
	}
	//�־�ߵǴ� ��ġ
	index[0] = size;
	xx(size, index,A, B, C,0);

	return 0;

	Rectangle2D r1(2, 2, 2, 2);
	Rectangle2D r3(3,1, 2, 2);
	if (r1.overlaps(r3) == 1) cout << "r3�� r1�� ��������." << endl;
	else cout << "r3�� r1�� ���������ʴ´�." << endl;
	
	{
	cout << "���� ����� �����Ѵ�.\n";
	StringBad headline1("celery Stalks at Midnight");
	StringBad headline2("Lettuce Prey");
	StringBad Sports("Spinach");
	cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports : " << Sports << endl;

	callme1(headline1);
	cout << "headline1: " << headline1 << endl;return 0;
	callme2(headline2);
	cout << "headline2: " << headline2 << endl;
	
	cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ : \n";
	StringBad sailor = Sports;
	cout << "sailor: " << sailor << endl;
	cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ���� : \n";
	StringBad knot;
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "�� ����� �������´�.\n";
	
	}
	cout << "main()�ǳ�\n";

	return 0;

	//Rectangle2D r1(2, 2, 5.5,4.9);
	Rectangle2D r2(5, 5,10.5, 3.2);
	//Rectangle2D r3(3, 5, 2.3,5.4);
	
	if (r1.contains(3, 3))cout << "(3,3)�� r1���ο� �ִ� ���̴�." << endl;
	else cout << "(3,3)�� r1�ܺο� �ִ� ���̴�." << endl;


	if (r1.contains(r2) == 1) cout << "r2�� r1���ο� �ִ�" << endl;
	else cout << "r2�� r1�ܺο� �ִ�." << endl;
	
	if (r1.overlaps(r3) == 1) cout << "r3�� r1�� ��������." << endl;
	else cout << "r3�� r1�� ���������ʴ´�." << endl;

	return 0;

	//��ü c1,c2,c3 ����
	Circle2D c1(2, 2, 5.5);
	Circle2D c2(2, 2, 5.5);
	Circle2D c3(4, 5, 10.5);
	
	//�ѷ�,���� ���
	cout << "c1�� �ѷ�: " << c1.getPerimeter() << " , ���� : " << c1.getArea() << endl;
	cout << "c2�� �ѷ�: " << c2.getPerimeter() << " , ���� : " << c2.getArea() << endl;
	cout << "c3�� �ѷ�: " << c3.getPerimeter() << " , ���� : " << c3.getArea() << endl;

	if (c1.contains(3, 3)) 
	{
		cout<<"(3,3)�� c1���ο� �ִ� ���̴�."<<endl;
	}
	else 
	{
		cout << "(3,3)�� c1�ܺο� �ִ� ���̴�." << endl;
	}

	if (c1.contains(c2) == 1)
	{
		cout << "c2�� c1���ο� �ִ�" << endl;
	}
	else
	{
		cout << "c2�� c1�ܺο� �ִ�." << endl;
	}
	if (c1.overlaps(c3) == 1)
	{
		cout << "c3�� c1�� ��������." << endl;
	}
	else
	{
		cout << "c3�� c1�� ���������ʴ´�." << endl;
	}

	return 0;
}


