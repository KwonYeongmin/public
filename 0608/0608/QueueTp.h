#pragma once
#ifndef QUEUEUP_H_
#define QUEUEUP_H_
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class Type>
class Worker 
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public: 
	Worker() :fullname("noname"), id(0L) {}
	Worker(const std::string &s,long n) :fullname(s), id(n) {}
	virtual void ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

template<class Type>
class Waiter :virtual public Worker 
{
private: int panache;
protected: 
	void Data() const;
	void Get();
public: 
	Waiter() :Worker(),panache(0) {}
	Waiter(const std::string &s,long n,int p=0):Worker(s,n),panache(p){}
	void Set();
	void Show() const;
};


template<class Type>
class Singer :virtual public Worker
{
protected:
	enum
	{other,alto,contralto,soprano,bass,baritone,tenor};
	enu{ Vtypes = 7};
	void Data() const;
	void Get();
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() :Worker(), voice(other) {}
	Singer(const std::string &s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker &wk, int v = other) :Worker(s,n),voice(v) {}
	void Set();
	void Show() const;
};

template<class Type>
class SingingWaiter :public Singer,public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	
	SingingWaiter(const Worker &wk, int p = 0,int v=other)
	:Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
	
	SingingWaiter(const Waiter&wt,  int v = other)
	:Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer&wt, int p = 0)
		:Worker(wt), Waiter(wt,p), Singer(wt, v) {}
	void Set();
	void Show() const;
};

template <class Type>
Worker<Type> ::~Worker() {}

template <class Type>
void Worker<Type> ::Data() const 
{
	cout << "사원 이름: " << fullname << endl;
	cout << "사원 번호: " << id ;
}

template <class Type>
void Worker<Type>::Get() 
{
	getline(cin, fullname); 
	cout << "사원번호를 입력: ";
	cin >> id;
	while (cin.get() != '\n') continue;
}


template <class Type>
void Worker<Type>::Set()
{
	getline(cin, fullname);
	cout << "사원번호를 입력: ";
	cin >> id;
	while (cin.get() != '\n') continue;
}

#endif // !QUEUEUP_H_

