#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <string>
#include <vector>
#include <array>
using namespace std;
int practice();
int quiz() 
{
	//0513
	//문제1
	/*문자열을 앞에서부터 읽으나 뒤에서부터 읽으나
	동일한 경우를 palindrome이라고 한다.
	문자열을 입력받아 회문읹 판단하고 결과를 출력한느 프로그램을 작성하라.
	mom => 회문
	stats =>회문
	noon=>회문
	*/
	char str[20];
	cin >> str;
	int cnt = 0;
	for (int i=0; *(str+i)!=0;i++) 
	{
		cnt++;
	}
	int ck=0;
	int value,k;
	
	if (cnt % 2 == 0) value = cnt / 2;
	else value = (cnt-1) / 2;
	

	if (str[0] != str[cnt - 1])
	{
		cout << str << "은 회문이 아니다" << endl;
	}
	else
	{
		for (int k = 0; k < value; k++)
		{
			if (str[k] == str[cnt - k - 1])
			{
				ck++;
			}
		}
		if (ck == value) { cout << str << "은 회문이다" << endl; }
	}


	return 0;
}
int practice() 
{
	int h_f;
	int h_i;
	int w_p;
	cout << "키를 입력하세요(피트)";
	cin >> h_f;
	cout << "키를 입력하세요(인치)";
	cin >> h_i;
	cout << "몸무게를 입력하세요(파운드)";
	cin >> w_p;

	h_f = h_i * 12;
	double BMI;
	BMI = (double)w_p / 2.2 / ((double)h_f / 12 * 0.0254)*((double)h_f / 12 * 0.0254);
	return 0;


}
void q7() 
{
	//p305 프로그래밍 연습
	//7번 구조체,동적메모리할당(벡터, 배열)
	struct car
	{
		string company;
		int year;
	};
	int number;

	cout << "몇 대의 차를 목록으로 관리 하시겠습니까? ";
	cin >> number;

	car *pCar_service = new car[number];
	for (int i = 0; i < number; i++)
	{
		cout << "자동차 #" << i << endl;
		cout << "제작 업체 : ";
		cin >> (pCar_service+i)->company;
		cout << "제작 년도 : ";
		cin >> (pCar_service+i)->year;
	}
	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다" << endl;

	for (int i = 0; i < number; i++)
	{
		cout << (pCar_service + i)->year << "년형 " << (pCar_service + i)->company << endl;
	}

	delete[] pCar_service;
}

void q8() 
//단어카운트하다가 i==d,i+1==o,i+2==n,i+3==e이 라면 바로 나가기
{
	//p305 프로그래밍 연습
	//8번 개수, 카운팅, 입력된 단어 done은 제외
	char str[120];
	int word_cnt = 0;
	int cnt = 0;
	
	cin>>str[120];
	int i = 0;
	while(1)
	{
		if (str[i])
		{
			word_cnt++;
		}
	if ((str[i]=='d')&& (str[i+1] == 'd')&& (str[i+2] == 'd')&& (str[i+3] == 'd'))
	{
		break;
	}
	}
cout << "총 "<<word_cnt<< "단어가 입력되었습니다."<<endl;
}
/*
int main()
{
	//q7();
	q8();
	return 0;



	clock_t dif1;
	clock_t dif2;
	clock_t cur;
	clock_t start;
	while(1)
	{
		int nCount = (cur - start) / 30;
		int dif2 = (cur - start) % 30;
		if (dif1>30) 
		{
			//update();
		}
		cur = clock();
	}


	return 0;

	int i = 5;
	cout << (i=100) << endl;
	return 0;
	//p231 프로그래밍 연습
	//7번
	struct TCL_analysis_service
	{
		string company_name;
		double diameter;
		double weight;
	};

	TCL_analysis_service pizza_ver;

	cout << "피자 분석 서비스를 위한 정보를 입력해주세요 " << endl;
	cout << "피자 회사의 이름 : " ;
	cin >> pizza_ver.company_name;
	cout << "피자의 지름(m): ";
	cin >> pizza_ver.diameter;
	cout << "피자의 중량(g) : ";
	cin >> pizza_ver.weight;
	
	cout << "피자 회사의 이름 : "<<pizza_ver.company_name <<", 피자의 지름 : "<<pizza_ver.diameter << "(m) ,피자의 중량 : " << pizza_ver.weight <<"g"<<endl<< endl;

	//8번
	TCL_analysis_service *Ppizza_ver=new TCL_analysis_service;
	cout << "피자 분석 서비스를 위한 정보를 입력해주세요 " << endl;
	cout << "피자의 지름(m): ";
	cin >> Ppizza_ver->diameter;
	cout << "피자 회사의 이름 : ";
	cin >> Ppizza_ver->company_name;
	cout << "피자의 중량(g) : ";
	cin >> Ppizza_ver->weight;

	cout << "피자 회사의 이름 : " << Ppizza_ver->company_name << ", 피자의 지름 : " << Ppizza_ver->diameter << "(m) ,피자의 중량 : " << Ppizza_ver->weight << "g" << endl << endl;
	return 0;


	struct candybar 
	{
		string name; 
		double weight;
		int calories;
	};

	
	// 5번 : 초기화
	candybar snack = 
	{ "Mocha Munch" , 2.3 , 350 };

	cout << snack.name << " , " << snack.weight  << " , " << snack.calories<<endl << endl;

	//6번
	candybar chocolate[3] =
	{
	{ "gana" , 2.2 , 300 },
	{ "f" , 3.7 , 200 },
	{ "d" , 4.1 , 100 }
	};
	cout << chocolate[0].name << " , " << chocolate[0].weight << " , " << chocolate[0].calories << endl;
	cout << chocolate[1].name << " , " << chocolate[1].weight << " , " << chocolate[1].calories << endl;
	cout << chocolate[2].name << " , " << chocolate[2].weight << " , " << chocolate[2].calories <<endl << endl;


	//9번
	candybar *pJelly = new candybar[3];

	
	pJelly[0] = { "hari" ,1000,10 };
	pJelly[1] = { "chu" ,2000,20 };
	pJelly[2] = { "pepe" ,3000,30};

	cout << (pJelly + 0)->name << " , " << (pJelly + 0)->weight << " , " << (pJelly + 0)->calories << endl;
	cout << (pJelly + 1)->name << " , " << (pJelly + 1)->weight << " , " << (pJelly + 1)->calories << endl;
	cout << (pJelly + 2)->name << " , " << (pJelly + 2)->weight << " , " << (pJelly + 2)->calories << endl;

	delete [] pJelly;
	
	return 0;


	//2번
	/*
	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cin.getline();
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;return 0;
	*/

	
/*
	//p220
	double a1[4] = { 1.2,1.4,3.6,4.8 };
	
	vector<double> a2(4);

	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	array<double, 4> a3 = { 3.14,2.72,1.62,1.41 };
	array<double, 4> a4;

	a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	a1[-1] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;


	return 0;

	//p204
	char animal[20] = "bear";
	const char *bird = "wren";
	char *ps;

	cout << animal << " and ";
	cout << bird << "\n";
	//cout << ps << "\n";
	cout << " 동물의 종류를 입력하시오.:  ";
	cin >>  animal;

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() 사용전: \n";
	cout << (int*)animal << ":" << animal << endl;
	cout << (int*)ps << ":" << ps << endl;

	return 0;
	//p195
	double *p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]은" << p3[1] << "입니다. \n";
	p3 = p3 + 1;
	cout << "이제는 p3[0]은" << p3[0] << "이고,";
	cout << "p3[1]이" << p3[1] << "입니다.\n";
	cout << &p3[0] << "\n";
	cout << &p3[1] << "\n";
	cout <<  &p3[2] << "\n";
	p3 = p3 - 1;
	delete[] p3;

	return 0;

}*/