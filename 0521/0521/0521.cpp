#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int quiz1();
int quiz2();
int quiz3(int n);
int quiz4(int n);


//p557 5번
template <typename T> T max5(T arr[5])
{
	T max = arr[0];

	for (int i = 0; i < 5; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	return max;
}

//p557 6번
template <typename T> T maxn(T *arr, int n)
{
	cout << "ok";
	T max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	return max;
}
//문자열 배열의 명시적 특수화
template <> 
char* maxn<char*>(char **str, int n) 
{
	char *max= str[0];
	for (int i = 0; i < n; i++)
	{
		if (strlen(max) < strlen(str[i])) max = str[i];
	}
	
	return max;
}

int main() 
{
	quiz4(100);
	return 0;
	for (;;) 
	{
		int n;
		cin >> n;
		if (n == 0) break;
		quiz4(n);
		
	}
	return 0;
	quiz3(100);
	quiz3(10000);

	return 0;

	//확인문제6
	int arr3[6] = { 1,7,3,4,5 ,2};
	double arr4[4] = { 1.3,1.2,3.4,2.4 };
	cout << "arr3배열에서 가장 큰 항목: " << maxn(arr3,6) << endl;
	cout << "arr4배열에서 가장 큰 항목: " << maxn(arr4,4) << endl;

	
	char *str[10]; 
	for(int i=0;i<10;i++)str[i]= new char[80];
	cout << "문자열을 입력하세요:  //종료를 원하면end입력" << endl;
	
	int i = 0;
	
	while (1)
	{
		cin >> str[i];
		if (strcmp(str[i], "end") == 0)
		{
			cout << "max: 문자열" <<maxn(str, i+1)<<endl; break;
		}
		i++;
	}
	return 0;
	int arr1[5] = { 1,2,3,4,5 };
	double arr2[5] = { 1.3,1.2,3.4,2.4,5.7 };
	cout << "arr1배열에서 가장 큰 항목: " << max5(arr1) << endl;
	cout << "arr2배열에서 가장 큰 항목: " << max5(arr2) << endl;
	
	return 0;


}

/*
두 직사각형에 대해 중심점의 x좌표, y좌표값 , 폭 , 높이를
입력받아 두번째 직사각형이 첫번째 직사각형의 내부에 있는지, 
첫번째 직사각형과 겹치는지를 결정하는 프로그램을 작성하라
첫번째 사각형: x,y,width,height 입력 : (2.5,4) 2.5 43
첫번째 사각형: x,y,width,height 입력 : (1.5,5) 0.5 3
중심점y + 높이/2
*/
int quiz1() 
{
	double x1, y1, width1, height1;
	double x2, y2, width2, height2;

	cout << "첫번째 사각형의 x,y,폭 높이를 입력: "<<endl;
	cin >> x1>> y1>> width1>> height1;
	cout << "두번째 사각형의 x,y,폭 높이를 입력: " << endl;
	cin >> x2 >> y2 >> width2 >> height2;

	const double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	const double r1 = sqrt(pow((width1 / 2), 2) + pow((height1 / 2), 2));
	const double r2 = sqrt(pow((width2 / 2), 2) + pow((height2 / 2), 2));
	
	if (dis >= r1 + r2) 
	{
		 cout << "두 직사각형은 겹쳐지지 않는다" << endl; 
	}
	else 
	{
		if ((width1 > width2) && (height1 > height2)) 
		{
			if (((x2 + width2 / 2) <= (x1 + width1 / 2)) && ((y2 + height2 / 2) <= (y1 + height1 / 2)) && ((y2 - height2 / 2) >= (y1 - height1 / 2)) && ((x2 - width2 / 2) >= (x1 - width1 / 2)))
			{
				cout << "두번째 직사각형은 첫번째 직사각형의 내부에 위치한다." << endl;
			}
		}
		else if ((width1 < width2) && (height1 < height2)) 
		{	
			if (((x2 + width2 / 2) >= (x1 + width1 / 2)) && ((y2 + height2 / 2) >= (y1 + height1 / 2)) && ((y2 - height2 / 2) <= (y1 - height1 / 2)) && ((x2 - width2 / 2) <= (x1 - width1 / 2)))
			{
				cout << "첫번째 직사각형은 두번째 직사각형의 내부에 위치한다." << endl;
			}
		}
		
		else { cout << "두 직사각형은 겹쳐진다" << endl; }
		
	}

	return 0;
}
int quiz2() 
{
	double x1, y1, r2;
	double x2, y2, r1;

	cout << "첫번 째 원의 중점x,y,반지름을 입력: " << endl;
	cin >> x1 >> y1 >> r1 ;
	cout << "두번 째 원의 중점 x,y,반지름을 입력: " << endl;
	cin >> x2 >> y2 >> r2;

	const double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	
	if (dis >= r1 + r2) cout << "두 원은 겹쳐지지 않는다" << endl;
	else 
	{
		if (r1 > r2)cout << "두번째 원은 첫번째 원의 내부에 있다." << endl;
		else if (r1 < r2)cout << "첫번째 원은 두번째 원의 내부에 있다." << endl;
	}

	return 0;
}





/*동전을 백만번 던지는 것을 시뮬레이션하고 앞면과 뒷면의 수를 출력하는 프로그램 작성
다음과 같이 각 앞뒤가 몇 %씩 나오는지 계산해 출력
100번째 일때 앞면 00% 뒷면 00%
1000번째 일때 앞면 00% 뒷면 00%
...
10000번째 일때 앞면 00% 뒷면 00%
100000번째 일때 앞면 00% 뒷면 00%


첫번째 
50%,50%
두번째 

*/

//랜덤 함수 이용하기
int quiz3(int n) 
{
	double front=0;
	double back=0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		if ((rand() % 2) == 0)//동전이 앞이 나올 때
		{
			front++;
		}
		else //동전이 앞이 나올 때
		{
			back++;
		}
		if (i == n)
		{
			cout << n<<"번째 일때"<< endl;
			cout << "앞면이 나올 확률" << front / i *100<< "%"<<endl;
			cout << "앞면이 나올 확률" << back / i *100<< "%" << endl;
		}
	}
	
	return 0;
}

/*각 아이템이 지정된 확률에 맞게 정확히 나올 수 있도록
프로그램을 작성하시오*/
int quiz4(int num) 
{
	int j = 0;
	int n = num;
	double item[11] = { 0 };
	//double item[11] = { 1,3,3,5,5,5,10,10,10,10,38 }; //0~10
	//double t_item[11] = { 1,3,3,5,5,5,10,10,10,10,38 };
	srand((unsigned)time(NULL));

	//int cnt = 0;
	int i;
	int arr[100];

	for (i = 0; i < 100; i++) 
	{
		if (i == 0) arr[i] = 0;
		else if (i >= 1 && i <4) arr[i] = 1; //3
		else if (i >= 4 && i < 7) arr[i] = 2; //3
		else if (i >= 7 && i < 12) arr[i] = 3; //5
		else if (i >= 12 && i < 17) arr[i] = 4; //5
		else if (i >= 17 && i < 22) arr[i] = 5; //5
		else if (i >= 22 && i < 32) arr[i] = 6; //10
		else if (i >= 32 && i < 42) arr[i] = 7; //10
		else if (i >= 42 && i < 52) arr[i] = 8; //10
		else if (i >= 52 && i < 62) arr[i] = 9; //10
		else arr[i] = 10;//38
	}

	int cnt[11] = { 0 };

	for (i = 0; i < 100; i++)
	{
		if (arr[rand() % 11] == 0) { cnt[0]++; }
		if (arr[rand() % 11] == 1) { cnt[1]++; }
		if (arr[rand() % 11] == 2) cnt[2]++;
		if (arr[rand() % 11] == 3) cnt[3]++;
		if (arr[rand() % 11] == 4) cnt[4]++;
		if (arr[rand() % 11] == 5) cnt[5]++;
		if (arr[rand() % 11] == 6) cnt[6]++;
		if (arr[rand() % 11] == 7) cnt[7]++;
		if(arr[rand() % 11] == 8) cnt[8]++;
		if (arr[rand() % 11] == 9) cnt[9]++;
		if (arr[rand() % 11] == 10) cnt[10]++;
	}
	for (i = 0; i < 11; i++)printf("%d \n",cnt[i]);
	//총합
	//int sum = 100;
	/*
	while (cnt<100) 
	{
				//n이 백일때
		int t = rand() % 100;
		if (t == 0) // 나머지가 0이 될 경우 한번이니까 ++
		{ 
			item[0]++;  
		} 
		else if (t < 3) // 경우 세번이니까 0++1
		{
			item[1]++;
			item[2]++;
		} 		
		else if (t < 5) // 경우 다섯번이니까 0++1
		{
			item[3]++; 
			item[4]++; 
			item[5]++; 
		}
		else if (t < 10) // 경우 열번이니까 0++1
		{ 
			item[6]++; 
			item[7]++; 
			item[8]++; 
			item[9]++;
			j++;
		}
		else if(t < 38) // 38번의 경우니까 0++1 
		{ item[10]++;
		}

		cnt++;
		if ((cnt == n)) break;
	}*/

	cout << n << "일 때" << endl;
	cout << j << endl;
	//for (i = 0; i < 11; i++) cout << i + 1 << " :: " << item[i]/n*100 << endl; //확률 계산

	/*
	while(1)
	{
		int t = rand() % 100;
		
		if (t == 0) // 0
		{
			if (t_item[0] == 0)  continue; 
			t_item[0]--;
			cnt++;
		}
		else if (t < 4) // 1,2,3
		{ 
			if (t_item[1] == 0) continue;
			t_item[1]--;
			cnt++;
		}
		else if (t < 7) // 4,5,6
		{
			if (t_item[2] == 0) continue;
			t_item[2]--;
			cnt++;
		}
		else if (t < 12) // 7,8,9,10,11
		{
			if (t_item[3] == 0) continue;
			t_item[3]--;
			cnt++;
		}
		else if (t < 17) // 12,13,14,15,16
		{
			if (t_item[4] == 0) continue;
			t_item[4]--;
			cnt++;
		}
		else if (t < 22) // 17,18,19,20,21
		{
			if (t_item[5] == 0) continue;
			t_item[5]--;
			cnt++;
		}
		else if (t < 32) // 22~31
		{
			if (t_item[6] == 0) continue;
			t_item[6]--;
			cnt++;
		}
		else if (t < 42) // 32~41
		{
			if (t_item[7] == 0) continue;
			t_item[7]--;
			cnt++;
		}
		else if (t < 52) // 42~51
		{
			if (t_item[8] == 0) continue;
			t_item[8]--;
			cnt++;
		}
		else if (t < 62) // 52~61
		{
			if (t_item[9] == 0) continue;
			t_item[9]--;
			cnt++;
		}
		else if (t == 62)
		{
			if (t_item[10] == 0) continue;
			t_item[10]--;
			cnt++;
		}
		if (cnt == 62) break;
		
	}

	for (i = 0; i < 11; i++) cout << i << " :: " << item[i] / n * 100.0 << endl;
	*/
	return 0;
}


/*
//p616
namespace pers 
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person &);
	void showPerson(const Person &);
}
namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};

	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[],int n);
}

//619
namespace pers
{
	using std::cout;
	using std::cin;
	void getPeson(Person &rp)
	{
		cout << "이름을 입력하세요: " << endl;
		cout << rp.fname; 
		cout << "성씨를 입력하세요: " << endl;
		cout << rp.lname;
	}
	void showPerson(const Person &rp) { cout << rp.lname<<" , " << rp.fname; }
}*/


