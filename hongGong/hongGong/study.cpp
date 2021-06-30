#include <iostream>
#include <string>
#include <fstream>
/*

void swapr(int &a, int &b) 
{
	int temp;
	temp = a; a = b; b = temp;	
}

void swapp(int *a, int *b)
{
	int temp; temp = *a; *a = *b; *b = temp;
}

void swapv(int a, int b)
{
	int temp; temp = a;a = b;b = temp;
}

int main() 
{
	using namespace std;

	int jeno = 22;
	int mark = 23;
	cout << endl<<"<기본 값>" << endl;
	cout << "jeno의 나이: " << jeno << "살" ;
	cout << " , mark의 나이: " << mark << "살" << endl;

	cout << "<참조 이용>" << endl;
	swapr(jeno, mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;
	jeno = 22; mark = 23;
	cout << "<포인터 이용>" << endl;
	swapp(&jeno, &mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;
	jeno = 22; mark = 23;
	cout << "<값으로 전달 이용>" << endl;
	swapv(jeno, mark);
	cout << "jeno의 나이: " << jeno << "살";
	cout << " , mark의 나이: " << mark << "살" << endl;

	return 0;

	int rats = 101;
	int & rodents = rats;
	int *p = &rats;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents<<endl;

	int bunnies = 50;
	p = &bunnies;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents << endl;

	rodents = bunnies;
	cout << "rats = " << rats;
	cout << " , p = " << *p;
	cout << " , rodents = " << rodents << endl;
	return 0;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << " , rats = " << rats;
	cout << " , rodents = " << rodents << endl;

	cout << "bunnies의 주소 = " << (unsigned long)&bunnies;
	cout << "rats의 주소 = " << (unsigned long)&rats;
	cout << " , rodents의 주소 = " << (unsigned long)&rodents << endl;
	return 0;
	/*
	int rats = 101;
	int value = rats;
	int *pointer = &rats;
	int & reference = rats;
	cout << "rats = " << rats;
	cout << " , value = " << value;
	cout << " , *pointer = " << *pointer;
	cout << ", reference = " << reference << endl;
	reference++;
	cout << "rats = " << rats;
	cout << " , value = " << value;
	cout << " , *pointer = " << *pointer;
	cout << ", reference = " << reference << endl;

	cout << "rats의 주소 = " << (unsigned long)&rats;
	cout << " , value의 주소 = " << (unsigned long)&value<<endl;
	cout << "pointer의 값 = " << (unsigned long)pointer;
	cout << ", reference의 주소 = " << (unsigned long)&reference << endl;
	
	return 0;
}*/

template <class T>
T sum(T a, T b) 
{
	return a + b;
}

class A 
{
private: double x; double y;
public:
	A(double x_,double y_):x(x_),y(y_)
	{
		std::cout << x + y << std::endl;
	}
};

class B :public A
{
private: 
	double x; double y;
public:
	B(double x_, double y_) :A(x_, y_) { x = x_; y = y_; std::cout << (x - y) << std::endl; }
};


void accept() 
{
	using namespace std;
	int Index = 0;
	//int arr[5] = { 1,5,7,9,10 };
	std::string id[5] = { "none" ,"A","B","C","D"};
	std::ifstream fin("test.txt");
	if (fin.fail()) { std::cout << "실패!" << std::endl; }
	//파일에 글쓰기


	//파일 읽어오기
	std::ofstream fout("test.txt");
	for(int i=0;i<)
	fout << id[0]<<endl;
	/*
	while (!fout.eof())
	{
		fout << "aaa bbb ccc";//id[Index];
		//fin >> id;
		Index++;
	}*/
		
}

int main() 
{
	using namespace std;
	accept();
	return 0;
	/*
	cout.fill('*');
	const char * staff[2] = { "윤성일","박순용" };
	long bonus[2] = { 900,1350 };
	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << " : $ ";
		cout.width(7);
		cout << bonus[i] << "\n";
	}*/
	
	const char * staff[2] = { "이제노","정재현" };
	string me = "권영민";
	for (int i = 0; i < 2; i++)
	{
		cout << staff[i];
		cout.width(8); cout.fill('ㅎ');
		cout << me<<endl;
	}

	return 0;
	cout.width(12);
	cout << "hello"<<endl; 
	cout.width(12);
	cout << "안녕하세요" << endl;
	cout.width(12);
	cout << "bye" << endl;
	cout.width(12);
	cout << "안녕히계세요" << endl;
	return 0;
	int w = cout.width();
	cout << "디폴트 필드 폭 = " << w << " : \n";

	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << " N * N " << ":\n";

	for (long i = 1; i <= 100; i *= 10) 
	{
		cout.width(5);
		cout << i << ':';
		cout.width(8);
		cout << i * i << ":\n";
	}

	return 0;
	cout << "하나의 정수를 입력: ";
	int n;
	cin >> n;
	cout << "n		n*n \n";
	cout << n << "		" << (unsigned long)n * n << " (10진법) \n";

	cout << hex;
	cout << n << "		";
	cout << n*n << " (16진법)\n";
	
	cout << oct << n << "		" << n * n << " (8진법)\n";

	dec(cout);
	cout << n << "		" << n * n << " (10진법)\n";
	
	return 0;
	
	std::cout << "12345678901234567890\n";
	char ch = 'k';
	int t = 273;
	std::cout << ch << " : \n";
	std::cout << t << " : \n";
	std::cout << -t << " : \n";

	double f1 = 1.200;
	std::cout << f1 << " : \n";
	std::cout << (f1+1.0/9.0) << " : \n";

	double f2 = 1.67E2;
	std::cout << f2 << " : \n";
	f2 += 1.0 / 9.0;
	std::cout << f2 << " : \n";
	std::cout<<(f2*1.0e4)<< " : \n";

	double f3 = 2.3e-4;
	std::cout << f3 << " : \n";
	std::cout << f3/10 << " : \n";

	return 0;
	std::cout << "안녕하십니까";
	std::cout<<std::flush;
	std::cout << "잠시만 기다려 주십시오." << std::endl;
}