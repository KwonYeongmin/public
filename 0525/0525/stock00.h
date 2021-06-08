#pragma once
#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>

class Stock
{
private:
	//변수 :: 내부 함수에서 사용
	std::string company; 
	long shares;
	double share_val;
	double tot_val;
	//함수 :: 내부 함수에서 사용
	void set_tot() { tot_val = shares * share_val; }
	
	
public:
	void acquire(const std::string&co, long n, double pr); // 외부에서 쓰인 함수
	void buy(long num, double price); // 외부에서 쓰인 함수
	void sell(long num, double price); // 외부에서 쓰인 함수
	void show(); // 외부에서 쓰인 함수

	void update(double price); // public에서 선언되었으나 외부에서 사용된적 없음
};

#endif // !STOCK00_H_
