/*
#include<iostream>
#include<cstdlib>
#include <ctime>

using std::cout;
class Grand
{
public:
	Grand(int h = 0) :hold(h) {}
	virtual void Speak()const { cout << "���� GrandŬ�����̴�!\n"; }
	virtual int Value()const { return hold; }
private:
	int hold;
};

class Superb : public Grand
{
public:
	Superb(int h = 0) :Grand(h) {}
	void Speak() const { cout << "���� superbŬ�����̴�!"; }
	virtual void Say() const { cout << "���� ������ �ִ� superb�� ����" << Value() << "�̴�.\n"; }
};

class Magnificent : public Superb
{
public:
	Magnificent(int h = 0, char c = 'A') :Superb(h), ch(c) {}
	void Speak() const { cout << "���� Magnificent Ŭ�����̴�!!\n"; }
	void Say() const { cout << "���� ������ �ִ� ���ڴ�"<<ch<<"�̰�, ������"<<Value()<<"�̴�.\n" ; }
private:
	char ch;
};
Grand *GetOne();
int main() 
{
	std::srand(std::time(0));
	Grand *pg;
	Superb *ps;
	for (int i = 0; i < 5; i++) 
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		else 
			cout << "����ȯ�� �����߽��ϴ�.\n";
	}

	return 0;
}

Grand *GetOne() 
{
	Grand *p = new Grand(std::rand() % 100);
	switch (std::rand() % 3)
	{
	case 0:
		p = new Grand(std::rand() % 100); 
		break;
	case 1:
		p = new Superb(std::rand() % 100); 
		break;
	case 2:
		p = new Magnificent(std::rand() % 100,'A'+std::rand()%26); 
		break;
	}

	return p;
}*/