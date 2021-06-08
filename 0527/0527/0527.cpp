#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

long Solution(int **ary, long size, long r, long c);
void reverseDisplay(int value);

int main()
{
	using namespace std;

	//문제1
	reverseDisplay(12345);
	return 0;
	//지그재그 배열
/*unsigned long size;
cout << "배열의 크기(1~10,000,000) 입력: ";
cin >> size;

int i, n;
//행렬 동적 할당
int **ary = new int*[size];
for (i = 0; i < size; i++) ary[i] = new int[size];

//초기화
for (i = 0; i < size; i++) for (n = 0; n < size; n++) ary[i][n] = 0;

int r, c;
cout << "찾으려는 행 입력: ";
cin >> r;
cout << "찾으려는 열 입력: ";
cin >> c;
cout<<endl<<endl<<"값: "<<Solution(ary,size,r,c)<<endl<<endl;

//동적할당 해제
delete(ary);
for (i = 0; i < size; i++) delete(ary[i]);
return 0;*/

}


//문제2_1
/*
다음 함수를 사용하여 int 값을 역으로 화면에 출력하는 재귀함수를 작성
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
//문제2_2
/*
문자열 값을 역으로 화면에 출력하는 재귀함수를 작성
void reverseDisplay_s(const string& s)
*/


/*
임의의 한 단어를 생성하고
사용자가 한번에 한 문자만을 추측하도록 해서
단어를 맞추는 팩맨 게임을 작성하라
단어의 각 문자는 '*'로 표시된다
사용자가 올바른 추측을 하였을 때 실제 문자가 화면에 표시된다.
사용자가 단어 맞추기를 끝냈을 때 실수한 횟수를 표기하고,
다른 단어로 계속할 것인지를 묻도록 한다.

ex) 생성된 단어->apple

a****
a***e
단어중 한 글자를 입력하시오 ***** > a
							a****
단어중 한 글자를 입력하시오 a**** > p
							ap***
총 xx번 실패, xx번 만에 정답 ! 
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
		if (cnt_ == a.len) { cout << "입력 횟수 초과 종료" << endl; }
		cout << "(1)단어 중 한 글자 입력 (2)정답 입력 :";
		cin >> menu;
		cout << cnt_ << endl;
		switch (menu)
		{
		case 1:
			cout << "단어중 한 글자를 입력하시오 :";
			cin >> temp;
			//처음부터 루프문 돌면서 확인
			//start부터 도는거아님
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
			cout << "정답 입력 :";
			cin >> a.input;
			if (answer_des(&a) == -1)
			{
				cout << "틀렸습니다" << endl; cnt++;
				break;
			}
			else
			{
				cout << "정답입니다" << endl; success(cnt, a.len);
				return 0;
				break;
			}
		}
	}
}

//입력된 문자열 판별
int answer_des(answer *a)
{
	if (strcmp(a->answer, a->input) == 0) return 1;
	else return -1;
}

//입력된 문자 판별
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

//성공
void success(int cnt, int num)
{
	using namespace std;	cout << "총 " << cnt << "번 실패, " << (num - cnt) << "만에 정답 !" << endl;
}

//실패
void fail(const answer *a, int cnt)
{
	using namespace std;
	if (cnt == (a->len - 1))
	{
		cnt++;
		cout << "총 " << cnt << "번 실패로 실패하였습니다." << endl;
	}
}





/*
이때 r 행 c 열의 칸에 어떤 숫자가 적혀있는지 구하려고 한다.
예를 들어 위 그림에서 r = 3 , c = 2 인경우 3행2열의 위치에는 9 가 들어 있다.
지그재그 행렬의 크기 N , 행위위치 r , 열의 위치 c 가 매개변수로 주어질 때 ,
N x N 크기의 지그재그 형렬의 r행 , c열에 들어있는 숫자를 return 하도록
Solution 함수를 완성하라.
제한사항 :
1.	N은1이상 10,000,000 이하의 자연수
2.	r 과 c 는 각각 1 이상 N 이하의 자연수
3.	정답은 2^31 -1 보다 커질수 있음에 주의

*/






//지그재그 배열 만들기
long Solution(int **ary,long size,long r, long c)
{
	using namespace std;
	const int size_ = size;
	int i, n;
	
	int dir = 1;
	int val = 1;
	int cnt = 0;
	int col = 0, row = -1;

	//왼쪽 반
	for (i = 0; i < size + 1; i++)
	{
		for (n = 0; n < i; n++)
		{
			if (n < i - 1) //대각선 이동
			{
				ary[row][col] = val;
				val++;
				col -= dir; row += dir;
			}
			else { ary[row][col] = val; val++; } //상하 또는 좌우 한칸 이동
		}

		if (i % 2 == 0)row++;
		else col++;

		//움직이는 방향바꾸기
		dir *= (-1);
	}

	//오른쪽 반
	if (size_ % 2==0) dir *= (-1);

	col = size-1 , row = 1;
	
	for (i = size - 1; i > 0; i--)
	{
		for (n = i; n > 0; n--)
		{
			if (n != 1) //대각선 이동
			{
				ary[row][col] = val;
				val++;
				col -= dir; row += dir;
			}
			else {ary[row][col] = val; val++; } //상하 또는 좌우 한칸 이동
		}

		if (size_ % 2 == 1) //배열의 크기가 짝수일때
		{
			if (i % 2 == 0) col++;
			else row++;
		}
		else //배열의 크기가 홀수일때
		{
			if (i % 2 == 0) row++;
			else col++;
		}	
		//움직이는 방향 바꾸기
		dir *= (-1);
	}
	
	long res;
	res = ary[r-1][c-1];

	return res;
}
