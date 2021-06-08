#pragma once
#ifndef WORKER_H_
#define WORKER_H_
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() :fullname("no name"), id(0L) {}
	Worker(const std::string &s, long n) :fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter :virtual public Worker
{
private: int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const std::string &s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker &wk, int p = 0) :Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};



class Singer :virtual public Worker
{
protected:
	enum
	{
		other, alto, contralto, soprano, bass, baritone, tenor
	};
	enum{ Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() :Worker(), voice(other) {}
	Singer(const std::string &s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker &wk, int v = other) :Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};


class SingingWaiter :public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}

	SingingWaiter(const std:: string &s, long n ,int p = 0, int v = other)
		:Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker &wk,  int p = 0, int v = other)
		:Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter&wt, int v = other)
		:Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer&wt, int p = 0)
		:Worker(wt), Waiter(wt, p), Singer(wt) {}
	void Set();
	void Show() const;
};


Worker ::~Worker() {}


void Worker::Data() const
{
	cout << "사원 이름: " << fullname;
	cout << "사원 번호: " << id;
}

void Worker::Get() 
{
	getline(cin, fullname);
	cout << "사원번호를 입력: ";
	cin >> id;
	while (cin.get() != '\n') continue;
}


void Waiter::Set()
{

	cout << "웨이터의 이름을 입력: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "직종: 웨이터\n";
	Worker::Data();
	Data();
}


void Waiter::Data() const
{
	cout << "웨이터 등급 : " << panache << endl;
}


void Waiter::Get()
{
	cout << "웨이터 등급을 입력하십시오 : " << panache << endl;
	cin >> panache;
	while (cin.get() != '\n') continue;
}


 char * Singer::pv[Singer::Vtypes] = { "other","alto","contralto","soprano","bass","baritone","tenor" };


void Singer::Set()
{
	cout << "가수의 이름을 입력: ";
	Worker::Get();
	Get();
}


void Singer::Show() const
{
	cout << "직종: 가수 \n";
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "목소리 유형: " << pv[voice] << endl;
}


void Singer::Get()
{
	cout << "가수의 목소리 유형 번호를 입력하십시오:\n ";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3) cout << endl;
	}
	if (i % 4 != 0) cout << '\n';
	cin >> voice;
	while (cin.get() != '\n') continue;
}


void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}


void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}


void SingingWaiter::Set()
{
	cout << "가수 겸 웨이터의 이름을 입력하십시오: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "직종: 가수겸웨이터\n";
	Worker::Data();
	Data();
}
#endif // !WORKER_H_

