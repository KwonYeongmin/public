/*
#pragma once
#ifndef WORKER0_H_
#define WORKER0_H_
#include <string>
class Worker
{
private:
	std::string fullname;
	long id;
public :
	Worker() :fullname("no name"), id(0L) {}
	Worker(const std::string &s,long n) :fullname(s), id(n) {}
	virtual ~Worker() ;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};
class Waiter: virtual public Worker
{
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const std::string &s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker &wk,int p=0) :Worker(wk), panache(p) {}
	void Set();
	void Show() const;
protected:
	int panache;
};

class Singer: virtual public  Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes=7};
	static char *pv[Vtypes];
	int voice;

public:
	Singer() :Worker(), voice(other) {}
	Singer(const std::string &s, long n, int v = other) :Worker(s, n), voice(v) {}
	void Set();
	void Show() const;
};

class SingingWaiter:public Singer,public Waiter
{
public:
	SingingWaiter() :Worker(), Waiter(), Singer() {}
	SingingWaiter(const std::string &wk, int p = 0, int v = Singer::other) : Worker(wk),Waiter(wk, p), Singer(wk, v) {}
	void Show() const;
	void Set();
};


#endif // !WORKER0_H_

*/
