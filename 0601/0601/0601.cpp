#include <iostream>
#include <string>
#include <new>
#include <time.h>
#include "MyPoint.h"

using namespace std;
const int BUF = 512;
//부모클래스
class cBase //클래스베이스
{
protected: double x; double y;
public: void setXY(double x_, double y_) { this->x = x_; this->y = y_; };
};

class JustTesting
{
public:
	JustTesting(const string &s = "Just Testing", int n = 0) 
	{
		words = s; number = n; cout << words << "생성 \n";
	};
	~JustTesting() { cout << words<<"파괴 \n"; };
	void Show() const { cout << words << ", " << number << endl; }

private:
	string words;
	int number;
};

void reverseDisplay(const string& s);
void quiz(int **arr,int d_x, int d_y, int count);
void drawing(int **arr);

/*
int main() 
{
	char *buffer = new char[BUF];
	JustTesting *pc1, *pc2;
	pc1 = new(buffer)JustTesting;
	pc2 = new JustTesting("Heap1", 20);
	cout << "메모리 블록 주소 : \n" << "buffer: " << (void*)buffer << "	   heap: " << pc2
		<< endl;
	cout << "메모리 내용:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting *pc3,*pc4;
	pc3 = new(buffer + sizeof(JustTesting))
		JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "메모리 내용:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "종료\n";

	return 0;

	MyPoint a;
	MyPoint b(10,30.5);
	
	Rectangle2D rec(0, 0, 4, 4);
	Circle2D circle(0, 0, 40);

	cout << "점 a (" << a.getX() << "," << a.getY() << ")" << endl;
	cout << "점 b (" << b.getX() << "," << b.getY() << ")" << endl;
	double m = 5;
	cout << "점 b를 바꾸기" << endl;
	b.setX(&m);
	b.setY(&m);
	cout << "점 b (" << b.getX() << "," << b.getY() << ")" << endl;
	cout << "a와 b사이의 거리는 " << a.distance(b) << "이다." << endl;
	cout << endl;
	cout<<"직사각형 rec: 중점 ("<<rec.getX()<<","<< rec.getX()<<") , width :"<<rec.getW() <<" , height :"<<rec.getH() <<endl;
	cout << "원 circle : 중점 (" << circle.getX() << "," << circle.getY() << ") ,radius :" << circle.getR() << endl;
	cout << endl;
	if(b.isIn(rec)) cout <<"점 b는 직사각형 rec 내부에 있다."<<endl;
	else cout << "점 b는 직사각형 rec 내부에 없다." << endl;

	if (b.isIn(circle)) cout << "점 b는 원 circle 내부에 있다." << endl;
	else cout << "점 b는 원 circle 내부에 없다." << endl;
	
	return 0;
}*/

int main() 
{
	int x=3, y=3;
	int **arr =  new int*[8];
	for (int i = 0; i < 8; i++) arr[i] = new int[8];

	quiz(arr,x,y,0);
	//drawing(arr);
	
	delete(*arr);
	for (int i = 0; i < 8; i++) delete(arr[i]);
	
	return 0;
	/*
	string str = "abcd";
	reverseDisplay(str);
	return 0;*/
}
// 퀸 자리 1
// 퀸 못 가는 자리 -1
// 갈 수 있는 자리 0
void quiz(int **arr,int d_x, int d_y,int count) 
{
	int i,j;
	srand((unsigned)time(NULL));
	int x, y;
	int dx = d_x;
	int dy = d_y;
	arr[d_x][d_y] = 1;

		//1일 때

		//퀸이 못가는 자리 -1 만들어주기
	//가로 세로
	for (i = 0; i < 8; i++) 
	{
		for (j=0;j<8;j++) 
		{
			if (arr[i][j] != 1) 
			{
				if (i == d_x) arr[i][j] = -1;
				if(j == d_y) arr[i][j] = -1;		
			}
			else 
			{
				arr[i][j] =1;
			}
		}
	}

	//대각선
	for (i=0;i<8;i++) 
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1) 
			{
				arr[i][j] = 1;
			}
			else 
			{
				if (d_x > 6 && d_y > 6) break;
				d_x++;
				d_y++;
				arr[d_x][d_y] = -1;
			}
		}
	}
	d_x = dx; d_y = dy;
	
	
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				if (d_x <1 && d_y < 1) break;
				d_x--;
				d_y--;
				arr[d_x][d_y] = -1;
			}
		}
	}
	d_x = dx; d_y = dy;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				if (d_x >6 && d_y < 1) break;
				d_x++;
				d_y--;
				arr[d_x][d_y] = -1;
			}
		}
	}
	d_x = dx; d_y = dy;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				if (d_x < 2 && d_y > 5) break;
				d_x--;
				d_y++;
				arr[d_x][d_y] = -1;
			}
		}
	}
	d_x = dx; d_y = dy;

	//퀸이 갈 수 있는 자리 0 만들어주기
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j]!= -1 && arr[i][j] != 1) arr[i][j] = 0;

		}
	}
	//drawing(arr);

	int row[64] = {0};
	int col[64] = {0};
	int cnt=0;
	
	//0중에 하나로 이동하기
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (arr[i][j] == 0)
			{
				row[cnt] = i;
				col[cnt] = j;
				cnt++;
			}
		}
	}
	
	int num=0;
	i = 0;
	
	while (1) 
	{
		if (row[i] == 0 && col[i] == 0) break;
		num++; i++; 
	}

	int index = rand() % (num - 1);
	d_x = row[index]; d_y = col[index];
	arr[d_x][d_y] = 1;
	count++;

	cout << d_x << "," << d_y << endl;
	drawing(arr);
	quiz(arr, d_x, d_y, count);
	/*
	if (count < 5) 
	{
		cout <<endl;
	}*/
}

void drawing(int **arr) 
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j=0;j<8;j++) 
		{
			if (arr[i][j] == 1) cout << "■";
			else if (arr[i][j] == -1) cout << "X ";
			else cout << "□";
		}
			cout << endl;
	}
}

void reverseDisplay(const string& s) 
{
	string str = s;

	cout<<s[0];
}