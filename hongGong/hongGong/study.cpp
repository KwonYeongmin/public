#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
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
	else { cout << "성공"; }
	//파일에 글쓰기


	//파일 읽어오기
	std::ofstream fout("test.txt");
	//for(int i=0;i<)
	fout << id[0]<<endl;
	/*
	while (!fout.eof())
	{
		fout << "aaa bbb ccc";//id[Index];
		//fin >> id;
		Index++;
	}*/
		
}
typedef struct test 
{
	int score;
	char name[20];
}tt;



void readFile() 
{
	int i, j;
	tt arr[6];
	std::ifstream fin("test.txt", std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	//std::ofstream fout("test3.txt", std::ios_base::in| std::ios_base::out | std::ios_base::binary);
	
	fin.clear();
	if (fin.fail()) { std::cout << "파일 열기 실패" << std::endl; }
	//if (fout.fail()) { std::cout << "파일 열기 실패" << std::endl; }
	for (i = 0; i < 5; i++) 
	{
		fin>>arr[i].name>>arr[i].score;
	}
	arr[5] = { 500,"new" };
	int max;
	for (i = 0; i < 5; i++)
	{
		max = i;
		for (j = i + 1; j < 6; j++)
		{
			if (arr[j].score > arr[max].score)
			{
				int temp = arr[j].score;
				arr[j].score = arr[i].score;
				arr[i].score = temp;
				char tempchar[20];
				strcpy(tempchar, arr[j].name);
				strcpy(arr[j].name, arr[i].name);
				strcpy(arr[i].name, tempchar);
			}
		}
	}
	fin.close();
	
	std::ofstream fout("test.txt", std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	fout.clear();
	for (i = 0; i < 5; i++) 
	{
		fout << arr[i].name<<' ' << arr[i].score << '\n';
	}
	fout.close();
	/*
	tt* t = new tt[5];
	std::string sourcename="test.txt";
	std::ifstream fin(sourcename, std::ios_base::in | std::ios_base::binary);
	//ofstream fout(desname, ios_base::out | ios_base::binary);
		
		//buffer -= 5;
		//fout.write(&buffer, sizeof(char));

	int size;
	if (fin.is_open())
	{
		std::cout << "open success!" << std::endl;
		fin.seekg(0, std::ios::end);
		size = fin.tellg();
	}
	std::cout<<"size : " << size<<std::endl;
	char buffer[1000];// = new char[size];
	char *token;
	//int buf;// = new int[size];
	int i = 0; int idx = 0;
	for (int i = 0; i < size; i++)
	{
		fin.seekg(i, std::ios::beg);
		fin.read(buffer, sizeof(char));
	
		i = 0;
		token = strtok(buffer, " "); 
		while (token != NULL) {
			if (i == 0) {
				strcpy(t[idx].name, token);
			}
			else if (i == 1) 
			{
				t[idx].score = atoi(token);
			}
			i++;
			token = strtok(NULL, " ");
		}
		idx++;

		fin.read(buffer, sizeof(char));
	}

	//std::fout.close();
	
	//cout << "decoding done!" << endl;



	//파일 읽기
	/*
	tt* t = new tt[5];
	FILE* fp = fopen("test.txt", "rb+");// 파일 읽기모드로 열기
	if (fp == NULL) {
		printf("fail to read file");
		return;
	}
	
	char buffer[1001], *token;

	int i = 0;
	int idx = 0;
	while (!feof(fp)) 
	{
		i = 0;//i초기화
		fgets(buffer, 1001, fp);
		token = strtok(buffer, " "); // 
		while (token != NULL) {

			if (i == 0) {
				strcpy(t[idx].name, token);
			}
			else if (i == 1) {
				t[idx].score = atoi(token);
			}
			i++;
			token = strtok(NULL, " ");
		}
		idx++;
	}
	*/
	/*
	int i,j;
	
	
	//읽은 내용이 잘 저장됐는지 출력
	for (int i = 0; i < idx; i++) 
	{
		printf("%s %d\n", t[i].name, t[i].score);
	}
	fin.close();
	//fclose(fp); // 파일 닫기*/
}


int main() 
{
	using namespace std;
	readFile();
	return 0;
	//파일 읽기
	int i,j;
	test arr[6] = { {5,"f"} ,{1,"c"}, {2,"e"}, {3,"b"}, {4,"a"} };
	arr[5] = { 10,"g" };
	//readFile();
//순위 매기기
	int max;
	for (i = 0; i < 5; i++)
	{
		max = i;
		for (j = i + 1; j < 6; j++)
		{
			if (arr[j].score > arr[max].score)
			{
				int temp = arr[j].score;
				arr[j].score = arr[i].score;
				arr[i].score = temp;
				
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		cout << i << " : " << arr[i].name << " : " << arr[i].score << endl;
	}
	//tt(t, idx);
	//accept();
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
	

}