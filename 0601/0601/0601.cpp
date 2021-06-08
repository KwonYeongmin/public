#include <iostream>
#include <string>
#include <new>
#include <time.h>
#include "MyPoint.h"

using namespace std;
const int BUF = 512;
//�θ�Ŭ����
class cBase //Ŭ�������̽�
{
protected: double x; double y;
public: void setXY(double x_, double y_) { this->x = x_; this->y = y_; };
};

class JustTesting
{
public:
	JustTesting(const string &s = "Just Testing", int n = 0) 
	{
		words = s; number = n; cout << words << "���� \n";
	};
	~JustTesting() { cout << words<<"�ı� \n"; };
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
	cout << "�޸� ��� �ּ� : \n" << "buffer: " << (void*)buffer << "	   heap: " << pc2
		<< endl;
	cout << "�޸� ����:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting *pc3,*pc4;
	pc3 = new(buffer + sizeof(JustTesting))
		JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "�޸� ����:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "����\n";

	return 0;

	MyPoint a;
	MyPoint b(10,30.5);
	
	Rectangle2D rec(0, 0, 4, 4);
	Circle2D circle(0, 0, 40);

	cout << "�� a (" << a.getX() << "," << a.getY() << ")" << endl;
	cout << "�� b (" << b.getX() << "," << b.getY() << ")" << endl;
	double m = 5;
	cout << "�� b�� �ٲٱ�" << endl;
	b.setX(&m);
	b.setY(&m);
	cout << "�� b (" << b.getX() << "," << b.getY() << ")" << endl;
	cout << "a�� b������ �Ÿ��� " << a.distance(b) << "�̴�." << endl;
	cout << endl;
	cout<<"���簢�� rec: ���� ("<<rec.getX()<<","<< rec.getX()<<") , width :"<<rec.getW() <<" , height :"<<rec.getH() <<endl;
	cout << "�� circle : ���� (" << circle.getX() << "," << circle.getY() << ") ,radius :" << circle.getR() << endl;
	cout << endl;
	if(b.isIn(rec)) cout <<"�� b�� ���簢�� rec ���ο� �ִ�."<<endl;
	else cout << "�� b�� ���簢�� rec ���ο� ����." << endl;

	if (b.isIn(circle)) cout << "�� b�� �� circle ���ο� �ִ�." << endl;
	else cout << "�� b�� �� circle ���ο� ����." << endl;
	
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
// �� �ڸ� 1
// �� �� ���� �ڸ� -1
// �� �� �ִ� �ڸ� 0
void quiz(int **arr,int d_x, int d_y,int count) 
{
	int i,j;
	srand((unsigned)time(NULL));
	int x, y;
	int dx = d_x;
	int dy = d_y;
	arr[d_x][d_y] = 1;

		//1�� ��

		//���� ������ �ڸ� -1 ������ֱ�
	//���� ����
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

	//�밢��
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

	//���� �� �� �ִ� �ڸ� 0 ������ֱ�
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
	
	//0�߿� �ϳ��� �̵��ϱ�
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
			if (arr[i][j] == 1) cout << "��";
			else if (arr[i][j] == -1) cout << "X ";
			else cout << "��";
		}
			cout << endl;
	}
}

void reverseDisplay(const string& s) 
{
	string str = s;

	cout<<s[0];
}