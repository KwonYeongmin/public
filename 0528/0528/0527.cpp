#include<iostream>
#include "Circle2D.h"
#include "Rectangle2D.h"
#include "strngbad.h"
using namespace std;

void callme1(StringBad &);
void callme2(StringBad);

void callme1(StringBad &rsb) 
{
	cout << "참조로 전달된\n";
	cout<<"    \""<<rsb<<"\"\n";
}
void callme2(StringBad sb) 
{
	cout << "값으로 전달된\n";
	cout << "    \"" << sb << "\"\n";
}

void Print(const int size, int *A, int*B, int *C, int cnt)
{cout << "횟수 " << cnt << endl;
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
	//들어갈곳 index
	//빠지는 곳 index-1
	

	//A 4번 B 2번
	//A 8번 B 5번 C 2번 
	
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
	//넣어야되는 위치
	index[0] = size;
	xx(size, index,A, B, C,0);

	return 0;

	Rectangle2D r1(2, 2, 2, 2);
	Rectangle2D r3(3,1, 2, 2);
	if (r1.overlaps(r3) == 1) cout << "r3은 r1과 겹쳐진다." << endl;
	else cout << "r3은 r1과 겹쳐지지않는다." << endl;
	
	{
	cout << "내부 블록을 시작한다.\n";
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
	
	cout << "하나의 객체를 다른 객체로 초기화 : \n";
	StringBad sailor = Sports;
	cout << "sailor: " << sailor << endl;
	cout << "하나의 객체를 다른 객체에 대입 : \n";
	StringBad knot;
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "이 블록을 빠져나온다.\n";
	
	}
	cout << "main()의끝\n";

	return 0;

	//Rectangle2D r1(2, 2, 5.5,4.9);
	Rectangle2D r2(5, 5,10.5, 3.2);
	//Rectangle2D r3(3, 5, 2.3,5.4);
	
	if (r1.contains(3, 3))cout << "(3,3)은 r1내부에 있는 점이다." << endl;
	else cout << "(3,3)은 r1외부에 있는 점이다." << endl;


	if (r1.contains(r2) == 1) cout << "r2는 r1내부에 있다" << endl;
	else cout << "r2는 r1외부에 있다." << endl;
	
	if (r1.overlaps(r3) == 1) cout << "r3은 r1과 겹쳐진다." << endl;
	else cout << "r3은 r1과 겹쳐지지않는다." << endl;

	return 0;

	//객체 c1,c2,c3 생성
	Circle2D c1(2, 2, 5.5);
	Circle2D c2(2, 2, 5.5);
	Circle2D c3(4, 5, 10.5);
	
	//둘레,면적 출력
	cout << "c1의 둘레: " << c1.getPerimeter() << " , 면적 : " << c1.getArea() << endl;
	cout << "c2의 둘레: " << c2.getPerimeter() << " , 면적 : " << c2.getArea() << endl;
	cout << "c3의 둘레: " << c3.getPerimeter() << " , 면적 : " << c3.getArea() << endl;

	if (c1.contains(3, 3)) 
	{
		cout<<"(3,3)은 c1내부에 있는 점이다."<<endl;
	}
	else 
	{
		cout << "(3,3)은 c1외부에 있는 점이다." << endl;
	}

	if (c1.contains(c2) == 1)
	{
		cout << "c2는 c1내부에 있다" << endl;
	}
	else
	{
		cout << "c2는 c1외부에 있다." << endl;
	}
	if (c1.overlaps(c3) == 1)
	{
		cout << "c3은 c1과 겹쳐진다." << endl;
	}
	else
	{
		cout << "c3은 c1과 겹쳐지지않는다." << endl;
	}

	return 0;
}


