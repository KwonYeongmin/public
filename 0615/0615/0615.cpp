// 0615.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <ctime>

void password(); void binary();

const char *file = "guests.txt";
/*
void binary()
{
	planet pl;
	cout << fixed << right;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << file << " 파일의 현재 내용은 다음과 같습니다.:\n";
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ":"
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;;
		}
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	{
		cerr << "출력을 위해 " << file << " 파일을 열 수 없음" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "행성의 이름을 입력:()";
}

*/
using namespace std;

//내가 한거 잘못한거
/*
bool bf_match(const string data, const char* abc,int *cnt)
{
	
	int pd = 0;
	int px=0;	
	char *mark=new char[data.length()];
	int count = 0;

	while (1) 
	{
		if (((data[pd] == 0) || (abc[px] == 0))) break;
		for (int i = 0; i < data.length(); i++) mark[i] = ' ';

		if (data[pd] == abc[px]) 
		{
			
			mark[pd] = '+';
			cout << data << endl;
			for (int i = 0; i < data.length(); i++)cout << mark[i];
			cout << endl;
			for (int i = 0; i < pd-px; i++) cout << " ";
			cout << abc << endl;
			pd++; px++;
			if (data[pd] == abc[px])
			{
				count++;
			}
			else { px--; }
		}
		else
		{
			pd++;
			
			mark[pd] = '|';
			cout << data << endl;
			for (int i = 0; i < data.length(); i++)cout << mark[i];
			cout << endl;
			for (int i = 0; i < pd - px; i++) cout << " ";
			cout << abc << endl;
		}
		
		
	}
	*cnt=count;
	if(*cnt==strlen(abc)-1) return 1;
	
}*/

int bf_match(const string data, const char* abc, int *cnt);
int kmp_match(const string data, const char* abc, int *cnt);


int main()
{
	const char*abc = "abcad";
	string data = "abcabccabcafegabcaffabcad";

	int j = 0;
	int cnt;
	clock_t start, end;
	
	
	std::cout << "<bf_match>" << endl;
	start= clock();
	int ck1 = bf_match(data, abc, &cnt);
	if (ck1 != -1) 
	{
		std::cout << abc << "는 " << data << "의 " << ck1 << "번째에 있습니다. \n";
	}
	else 
	{
		std::cout << abc << "는 " << data << "에 없습니다. \n";
	}
	end = clock();
	std::cout << "<bf_match>" << endl;
	std::cout << end - start << "ms" << endl;
	std::cout <<"비교를 "<< cnt<<"회 진행" << endl;
	
	std::cout<<endl<< "<kmp match>" << endl;
	cnt = 0;
	start = clock();
	int ck2 = kmp_match(data, abc, &cnt);
	if (ck2 != -1)
	{
		std::cout << abc << "는 "<<data<<"의 " << ck2 << "번째에 있습니다. \n";
	}
	else
	{
		std::cout << abc << "는 " << data << "에 없습니다. \n";
	}
	end = clock();
	std::cout << "<kmp match>" << endl;
	std::cout << end - start << "ms" << endl;
	std::cout << "비교를 " <<cnt<< "회 진행" << endl;

	
	return 0;

	/*
const char *state1 = "Florida";
const char *state2 = "Kansas";
//const char str[12] = "helloworld";
//const char *state3 = "Euphoria";
int len = strlen(state2);
int i;
for (i = 1; i <= len; i++)
{
	cout.write(state2, i);
	cout << endl;
}
cout << "인덱스 감소:\n";
for (i = len; i > 0; i--) cout.write(state2, i) << endl;
cout << "문자열 길이 초과 : \n";
cout.write(state2, len + 5) << endl;

return 0;*/

	/*
	for (int i = 0; i < strlen(data); i++)
	{

		if (data[i] == abc[0])
		{
			if (data[i + 1] == abc[1])
			{
				if (data[i + 2] == abc[2])
				{
					cout <<i<<" : "<< data[i]<<" , "<< i+1 << " : " << data[i + 1] << " , " << i+2 << " : " << data[i + 2] << " , " << endl;
				}
			}
		}
	}*/
		
	/*
	binary();
	return 0;
	char ch;
	ifstream fin;
	fin.open(file);
	if (fin.is_open()) 
	{
		cout << file << "파일의 현재 내용은 다음과 같습니다.:\n";
		while (fin.get(ch)) cout << ch;
		fin.close();
	}
	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "출력을 위해" << file << "파일을 열수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	cout << "새로운 손님 이름들을 입력하십시오(끝내려면 빈줄 입력): \n";
	string name;
	while (getline(cin, name) && name.size() > 0) 
	{
		fout << name << endl;
	}
	fout.close();
	fin.clear();
	fin.open(file);
	if (fin.is_open()) 
	{
		cout << file << "파일의 개정된 내용은 다음과 같습니다.:\n";
		while (fin.get(ch)) cout << ch;
		fin.close();
	}
	cout << "프로그램을 종료합니다.";
		
		return 0;

	*/
	/*
	int input;
	int sum = 0;
	while (cin >> input) 
	{
		sum += input;
	}
	cout << "마지막으로 입력한 값 : " << input << endl;
	cout << "마지막으로 입력한 값 : " << sum << endl;*/
}


int bf_match(const string data, const char* abc, int *cnt)
{
	int pd = 0; int px = 0;
	unsigned int m, i;
	int count = 0;
	char *mark = new char[data.length()];
	int ck=0;

	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < data.length(); i++) mark[i] = ' ';

		if (data[pd] == abc[px])
		{
			pd++; px++; count++;
			ck++;
			//출력
			mark[pd - 1] = '+';
			std::cout << data << endl;
			for (i = 0; i < data.length(); i++)std::cout << mark[i];
			std::cout << endl;
			for (int i = 0; i < pd - px; i++) std::cout << " ";
			std::cout << abc << endl;
		}
		else
		{
			px = 0; 
			pd -= (ck-1); ck = 0;
			mark[pd] = '|';
			std::cout << data << endl;
			for (i = 0; i < data.length(); i++) std::cout << mark[i];
			std::cout << endl;
			for (i = 0; i < pd - px; i++) std::cout << " ";
			std::cout << abc << endl;
		}
	}
	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}


int kmp_match(const string data, const char* abc, int *cnt)
{
	int pd = 0; int px = 0;
	unsigned int m, i;
	int count = 0;
	char *mark = new char[data.length()];
	int ck = 0;
	while (1)
	{
		if ((data[pd] == 0) || (abc[px] == 0)) break;
		for (i = 0; i < data.length(); i++) mark[i] = ' ';

		if (data[pd] == abc[px])
		{
			pd++; px++;
			ck++; count++;
			//출력
			mark[pd - 1] = '+';
			std::cout << data << endl;
			for (i = 0; i < data.length(); i++)std::cout << mark[i];
			std::cout << endl;
			for (int i = 0; i < pd - px; i++) std::cout << " ";
			std::cout << abc << endl;
		}
		else
		{
			if (ck != 0)
			{
				for (m = 0; m < strlen(abc); m++)
				{
					if (data[ck - 1] == abc[m])
					{
						px = m + 1;
						break;
					}
				}	
				ck = 0; 
			}
			else { px = 0; pd = pd - px + 1; }
			
			//출력
			mark[pd] = '|';
			std::cout << data << endl;
			for (i = 0; i < data.length(); i++) std::cout << mark[i];
			std::cout << endl;
			for (i = 0; i < pd - px; i++) std::cout << " ";
			std::cout << abc << endl;
		}
	}

	if (abc[px] == '\0')
	{
		*cnt = count;
		return (pd - px);
	}
	else return -1;
}


void password() 
{
	using namespace std;

	string filename;
	std::cout << "새 파일을 위한 이름 입력: ";
	cin >> filename;
	ofstream fout(filename.c_str());
	fout << "비밀 번호 노출에 주의하십시오.\n";
	std::cout << "비밀 번호를 입력: ";
	fout << "귀하의 비밀번호는 ";
	//문자로 읽기,,,


	while (1)
	{
		char temp;
		cin >> temp;
		if (temp == 13) break;
		fout << temp;
	}
	std::cout << "입니다.\n";
	fout.close();

	ifstream fin_(filename.c_str());
	std::cout << filename << " 파일의 내용은 다음과 같습니다.\n";
	char ch_;
	while (fin_.get(ch_)) std::cout << ch_;
	std::cout << "프로그램을 종료합니다.\n";
	fin_.close();
}

inline void eatline() { while(std::cin.get() != '\n') continue; }
struct planet 
{
	char name[20];
	double population;
	double g;
};

//p1434,p1444
