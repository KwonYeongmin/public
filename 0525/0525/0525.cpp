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



//���
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

//����1
/*
�б��� 100���� �繰�԰� 100���� �л��� �ִ�.
��� �繰���� ù ���� �����ִ�.
�л��� ���Ƿ� ���鼭
s1�̶�� ù��° �л��� ��� �繰���� ����.
s2�̶�� �ι�° �л��� �繰�� L2���� �����Ͽ� �ϳ��� �ǳʶٸ鼭 �繰���� �ݴ´�.
s3�̶�� ���� °�л��� �繰�� L3���� �����Ͽ�
����° �繰�� ���� ���¸� �����Ѵ�.
s4��� �׹�° �л��� �繰�� L4���� �����Ͽ� �׹�° �繰�� ���� ���¸� �����Ѵ�.
�� �۾��� �л�s100�� L100�繰���� ������ ������ ��ӵȴ�.
��� �л��� ������ ����ϰ� �� ���� � �繰���� �����ִ���
�����ִ� ��� �繰�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�.
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

	//-1�� �������� 1�� ��������
	for (i = 1; i <= 100; i++)
	{
		if (locker[i] % 2 == 1) locker[i] = 1;
		else locker[i] = -1;

	}

	cout << "�����ִ� �繰�� :" << endl << endl;

	for (i = 1; i <= 100; i++)
	{
		if (locker[i] == 1) cout << " ��ȣ " << i << "" << endl;

	}
	
}