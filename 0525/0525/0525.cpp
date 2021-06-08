#include <string>
#include <iostream>

using namespace std;

void quiz();

int main()
{
	
	
	quiz();

	return 0;
}

	

/*
class Person
{
private :
	long ID_number;
	string name;
public :
	string name;

	long Getnumber() 
	{
		return ID_number; 
	}

	void SetName(string name) 
	{
		//return name;
	}
};



//헤더
class stock 
{

private:
	std::string company;
	void set_tot();
	void set_companyName();
public: 
	void Show();
	void SetName(string com);
};

void stock::Show() 
{
	std::cout << company << std::endl;
}
void SetName(string _name) 
{
	//name=_name;
}
*/

//문제1
/*
학교에 100개의 사물함과 100명의 학생이 있다.
모든 사물함은 첫 날은 닫혀있다.
학생이 교실로 들어가면서
s1이라는 첫번째 학생은 모든 사물함을 연다.
s2이라는 두번째 학생은 사물함 L2부터 시작하여 하나씩 건너뛰면서 사물함을 닫는다.
s3이라는 세번 째학생은 사물함 L3부터 시작하여
세번째 사물함 마다 상태를 변경한다.
s4라는 네번째 학생은 사물함 L4부터 시작하여 네번째 사물함 마다 상태를 변경한다.
이 작업을 학생s100이 L100사물함을 변경할 때까지 계속된다.
모든 학생이 교실을 통과하고 난 다음 어떤 사물함이 열려있는지
열려있는 모든 사물함 번호를 출력하는 프로그램을 작성하라.
*/

void quiz() 
{
	int i, j;
	int state = -1;


	int locker[101] = { -1 };

	for (j = 1; j < 101; j++)
	{
		for (int i = j; i <= 100; i++)
		{
			if (i % j == 0) locker[i]++;
		}
	}

	//-1이 닫혀있음 1이 열려있음
	for (i = 1; i <= 100; i++)
	{
		if (locker[i] % 2 == 1) locker[i] = 1;
		else locker[i] = -1;

	}

	cout << "열려있는 사물함 :" << endl << endl;

	for (i = 1; i <= 100; i++)
	{
		if (locker[i] == 1) cout << " 번호 " << i << "" << endl;

	}
	
}