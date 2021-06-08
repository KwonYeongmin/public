#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

long Solution(int **ary, long size, long r, long c);
void reverseDisplay(int value);

int main()
{
	using namespace std;

	//����1
	reverseDisplay(12345);
	return 0;
	//������� �迭
/*unsigned long size;
cout << "�迭�� ũ��(1~10,000,000) �Է�: ";
cin >> size;

int i, n;
//��� ���� �Ҵ�
int **ary = new int*[size];
for (i = 0; i < size; i++) ary[i] = new int[size];

//�ʱ�ȭ
for (i = 0; i < size; i++) for (n = 0; n < size; n++) ary[i][n] = 0;

int r, c;
cout << "ã������ �� �Է�: ";
cin >> r;
cout << "ã������ �� �Է�: ";
cin >> c;
cout<<endl<<endl<<"��: "<<Solution(ary,size,r,c)<<endl<<endl;

//�����Ҵ� ����
delete(ary);
for (i = 0; i < size; i++) delete(ary[i]);
return 0;*/

}


//����2_1
/*
���� �Լ��� ����Ͽ� int ���� ������ ȭ�鿡 ����ϴ� ����Լ��� �ۼ�
reverseDisplay(12345)
54321
*/
void reverseDisplay(int value)
{
	using namespace std;
	double val;
	val = value % 10;
	value *= 0.1;
	if (val > 10) val = val * 0.1;
	cout << val;
	if (val > 1) reverseDisplay(value);

}
//����2_2
/*
���ڿ� ���� ������ ȭ�鿡 ����ϴ� ����Լ��� �ۼ�
void reverseDisplay_s(const string& s)
*/


/*
������ �� �ܾ �����ϰ�
����ڰ� �ѹ��� �� ���ڸ��� �����ϵ��� �ؼ�
�ܾ ���ߴ� �Ѹ� ������ �ۼ��϶�
�ܾ��� �� ���ڴ� '*'�� ǥ�õȴ�
����ڰ� �ùٸ� ������ �Ͽ��� �� ���� ���ڰ� ȭ�鿡 ǥ�õȴ�.
����ڰ� �ܾ� ���߱⸦ ������ �� �Ǽ��� Ƚ���� ǥ���ϰ�,
�ٸ� �ܾ�� ����� �������� ������ �Ѵ�.

ex) ������ �ܾ�->apple

a****
a***e
�ܾ��� �� ���ڸ� �Է��Ͻÿ� ***** > a
							a****
�ܾ��� �� ���ڸ� �Է��Ͻÿ� a**** > p
							ap***
�� xx�� ����, xx�� ���� ���� ! 
*/


typedef struct
{
	char answer[10];
	char input[10];
	char output[10];
	int len;
}answer;

int des(answer *a, char temp, int start, int *x);
int answer_des(answer *a);
void success(int cnt, int num);
void fail(const answer *a, int cnt);
void init(answer *a) 
{
	strcpy(a->answer,"apple");
	a->len = strlen(a->answer);
	for (int i = 0; i < a->len; i++) 
	{
		a->output[i] = '*';
	}
	a->output[a->len + 1] = 0;
}
int quiz1()
{
	using namespace std;
	int menu, x = 0, cnt = 0, cnt_ = 0;
	answer a;
	init(&a);
	char temp;

	while (1)
	{
		if (cnt_ == a.len) { cout << "�Է� Ƚ�� �ʰ� ����" << endl; }
		cout << "(1)�ܾ� �� �� ���� �Է� (2)���� �Է� :";
		cin >> menu;
		cout << cnt_ << endl;
		switch (menu)
		{
		case 1:
			cout << "�ܾ��� �� ���ڸ� �Է��Ͻÿ� :";
			cin >> temp;
			//ó������ ������ ���鼭 Ȯ��
			//start���� ���°žƴ�
			for (int i = 0; i < a.len; i++)
			{
				if (des(&a, temp, i, &x) == 1)
				{
					cnt_++; a.output[x] = temp;
				}
			}
			cout << a.output << endl;

			cnt++;
			break;
		case 2:
			cout << "���� �Է� :";
			cin >> a.input;
			if (answer_des(&a) == -1)
			{
				cout << "Ʋ�Ƚ��ϴ�" << endl; cnt++;
				break;
			}
			else
			{
				cout << "�����Դϴ�" << endl; success(cnt, a.len);
				return 0;
				break;
			}
		}
	}
}

//�Էµ� ���ڿ� �Ǻ�
int answer_des(answer *a)
{
	if (strcmp(a->answer, a->input) == 0) return 1;
	else return -1;
}

//�Էµ� ���� �Ǻ�
int des(answer *a, char temp, int start, int *x)
{
	for (int i = start; i < a->len; i++)
	{
		if (a->answer[i] == temp)
		{
			*x = i;
			return 1;
		}
	}
	return -1;
}

//����
void success(int cnt, int num)
{
	using namespace std;	cout << "�� " << cnt << "�� ����, " << (num - cnt) << "���� ���� !" << endl;
}

//����
void fail(const answer *a, int cnt)
{
	using namespace std;
	if (cnt == (a->len - 1))
	{
		cnt++;
		cout << "�� " << cnt << "�� ���з� �����Ͽ����ϴ�." << endl;
	}
}





/*
�̶� r �� c ���� ĭ�� � ���ڰ� �����ִ��� ���Ϸ��� �Ѵ�.
���� ��� �� �׸����� r = 3 , c = 2 �ΰ�� 3��2���� ��ġ���� 9 �� ��� �ִ�.
������� ����� ũ�� N , ������ġ r , ���� ��ġ c �� �Ű������� �־��� �� ,
N x N ũ���� ������� ������ r�� , c���� ����ִ� ���ڸ� return �ϵ���
Solution �Լ��� �ϼ��϶�.
���ѻ��� :
1.	N��1�̻� 10,000,000 ������ �ڿ���
2.	r �� c �� ���� 1 �̻� N ������ �ڿ���
3.	������ 2^31 -1 ���� Ŀ���� ������ ����

*/






//������� �迭 �����
long Solution(int **ary,long size,long r, long c)
{
	using namespace std;
	const int size_ = size;
	int i, n;
	
	int dir = 1;
	int val = 1;
	int cnt = 0;
	int col = 0, row = -1;

	//���� ��
	for (i = 0; i < size + 1; i++)
	{
		for (n = 0; n < i; n++)
		{
			if (n < i - 1) //�밢�� �̵�
			{
				ary[row][col] = val;
				val++;
				col -= dir; row += dir;
			}
			else { ary[row][col] = val; val++; } //���� �Ǵ� �¿� ��ĭ �̵�
		}

		if (i % 2 == 0)row++;
		else col++;

		//�����̴� ����ٲٱ�
		dir *= (-1);
	}

	//������ ��
	if (size_ % 2==0) dir *= (-1);

	col = size-1 , row = 1;
	
	for (i = size - 1; i > 0; i--)
	{
		for (n = i; n > 0; n--)
		{
			if (n != 1) //�밢�� �̵�
			{
				ary[row][col] = val;
				val++;
				col -= dir; row += dir;
			}
			else {ary[row][col] = val; val++; } //���� �Ǵ� �¿� ��ĭ �̵�
		}

		if (size_ % 2 == 1) //�迭�� ũ�Ⱑ ¦���϶�
		{
			if (i % 2 == 0) col++;
			else row++;
		}
		else //�迭�� ũ�Ⱑ Ȧ���϶�
		{
			if (i % 2 == 0) row++;
			else col++;
		}	
		//�����̴� ���� �ٲٱ�
		dir *= (-1);
	}
	
	long res;
	res = ary[r-1][c-1];

	return res;
}
