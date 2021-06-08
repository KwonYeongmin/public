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


//p557 5��
template <typename T> T max5(T arr[5])
{
	T max = arr[0];

	for (int i = 0; i < 5; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	return max;
}

//p557 6��
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
//���ڿ� �迭�� ����� Ư��ȭ
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

	//Ȯ�ι���6
	int arr3[6] = { 1,7,3,4,5 ,2};
	double arr4[4] = { 1.3,1.2,3.4,2.4 };
	cout << "arr3�迭���� ���� ū �׸�: " << maxn(arr3,6) << endl;
	cout << "arr4�迭���� ���� ū �׸�: " << maxn(arr4,4) << endl;

	
	char *str[10]; 
	for(int i=0;i<10;i++)str[i]= new char[80];
	cout << "���ڿ��� �Է��ϼ���:  //���Ḧ ���ϸ�end�Է�" << endl;
	
	int i = 0;
	
	while (1)
	{
		cin >> str[i];
		if (strcmp(str[i], "end") == 0)
		{
			cout << "max: ���ڿ�" <<maxn(str, i+1)<<endl; break;
		}
		i++;
	}
	return 0;
	int arr1[5] = { 1,2,3,4,5 };
	double arr2[5] = { 1.3,1.2,3.4,2.4,5.7 };
	cout << "arr1�迭���� ���� ū �׸�: " << max5(arr1) << endl;
	cout << "arr2�迭���� ���� ū �׸�: " << max5(arr2) << endl;
	
	return 0;


}

/*
�� ���簢���� ���� �߽����� x��ǥ, y��ǥ�� , �� , ���̸�
�Է¹޾� �ι�° ���簢���� ù��° ���簢���� ���ο� �ִ���, 
ù��° ���簢���� ��ġ������ �����ϴ� ���α׷��� �ۼ��϶�
ù��° �簢��: x,y,width,height �Է� : (2.5,4) 2.5 43
ù��° �簢��: x,y,width,height �Է� : (1.5,5) 0.5 3
�߽���y + ����/2
*/
int quiz1() 
{
	double x1, y1, width1, height1;
	double x2, y2, width2, height2;

	cout << "ù��° �簢���� x,y,�� ���̸� �Է�: "<<endl;
	cin >> x1>> y1>> width1>> height1;
	cout << "�ι�° �簢���� x,y,�� ���̸� �Է�: " << endl;
	cin >> x2 >> y2 >> width2 >> height2;

	const double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	const double r1 = sqrt(pow((width1 / 2), 2) + pow((height1 / 2), 2));
	const double r2 = sqrt(pow((width2 / 2), 2) + pow((height2 / 2), 2));
	
	if (dis >= r1 + r2) 
	{
		 cout << "�� ���簢���� �������� �ʴ´�" << endl; 
	}
	else 
	{
		if ((width1 > width2) && (height1 > height2)) 
		{
			if (((x2 + width2 / 2) <= (x1 + width1 / 2)) && ((y2 + height2 / 2) <= (y1 + height1 / 2)) && ((y2 - height2 / 2) >= (y1 - height1 / 2)) && ((x2 - width2 / 2) >= (x1 - width1 / 2)))
			{
				cout << "�ι�° ���簢���� ù��° ���簢���� ���ο� ��ġ�Ѵ�." << endl;
			}
		}
		else if ((width1 < width2) && (height1 < height2)) 
		{	
			if (((x2 + width2 / 2) >= (x1 + width1 / 2)) && ((y2 + height2 / 2) >= (y1 + height1 / 2)) && ((y2 - height2 / 2) <= (y1 - height1 / 2)) && ((x2 - width2 / 2) <= (x1 - width1 / 2)))
			{
				cout << "ù��° ���簢���� �ι�° ���簢���� ���ο� ��ġ�Ѵ�." << endl;
			}
		}
		
		else { cout << "�� ���簢���� ��������" << endl; }
		
	}

	return 0;
}
int quiz2() 
{
	double x1, y1, r2;
	double x2, y2, r1;

	cout << "ù�� ° ���� ����x,y,�������� �Է�: " << endl;
	cin >> x1 >> y1 >> r1 ;
	cout << "�ι� ° ���� ���� x,y,�������� �Է�: " << endl;
	cin >> x2 >> y2 >> r2;

	const double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	
	if (dis >= r1 + r2) cout << "�� ���� �������� �ʴ´�" << endl;
	else 
	{
		if (r1 > r2)cout << "�ι�° ���� ù��° ���� ���ο� �ִ�." << endl;
		else if (r1 < r2)cout << "ù��° ���� �ι�° ���� ���ο� �ִ�." << endl;
	}

	return 0;
}





/*������ �鸸�� ������ ���� �ùķ��̼��ϰ� �ո�� �޸��� ���� ����ϴ� ���α׷� �ۼ�
������ ���� �� �յڰ� �� %�� �������� ����� ���
100��° �϶� �ո� 00% �޸� 00%
1000��° �϶� �ո� 00% �޸� 00%
...
10000��° �϶� �ո� 00% �޸� 00%
100000��° �϶� �ո� 00% �޸� 00%


ù��° 
50%,50%
�ι�° 

*/

//���� �Լ� �̿��ϱ�
int quiz3(int n) 
{
	double front=0;
	double back=0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		if ((rand() % 2) == 0)//������ ���� ���� ��
		{
			front++;
		}
		else //������ ���� ���� ��
		{
			back++;
		}
		if (i == n)
		{
			cout << n<<"��° �϶�"<< endl;
			cout << "�ո��� ���� Ȯ��" << front / i *100<< "%"<<endl;
			cout << "�ո��� ���� Ȯ��" << back / i *100<< "%" << endl;
		}
	}
	
	return 0;
}

/*�� �������� ������ Ȯ���� �°� ��Ȯ�� ���� �� �ֵ���
���α׷��� �ۼ��Ͻÿ�*/
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
	//����
	//int sum = 100;
	/*
	while (cnt<100) 
	{
				//n�� ���϶�
		int t = rand() % 100;
		if (t == 0) // �������� 0�� �� ��� �ѹ��̴ϱ� ++
		{ 
			item[0]++;  
		} 
		else if (t < 3) // ��� �����̴ϱ� 0++1
		{
			item[1]++;
			item[2]++;
		} 		
		else if (t < 5) // ��� �ټ����̴ϱ� 0++1
		{
			item[3]++; 
			item[4]++; 
			item[5]++; 
		}
		else if (t < 10) // ��� �����̴ϱ� 0++1
		{ 
			item[6]++; 
			item[7]++; 
			item[8]++; 
			item[9]++;
			j++;
		}
		else if(t < 38) // 38���� ���ϱ� 0++1 
		{ item[10]++;
		}

		cnt++;
		if ((cnt == n)) break;
	}*/

	cout << n << "�� ��" << endl;
	cout << j << endl;
	//for (i = 0; i < 11; i++) cout << i + 1 << " :: " << item[i]/n*100 << endl; //Ȯ�� ���

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
		cout << "�̸��� �Է��ϼ���: " << endl;
		cout << rp.fname; 
		cout << "������ �Է��ϼ���: " << endl;
		cout << rp.lname;
	}
	void showPerson(const Person &rp) { cout << rp.lname<<" , " << rp.fname; }
}*/


