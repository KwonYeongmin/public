#pragma once
#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>

class Stock
{
private:
	//���� :: ���� �Լ����� ���
	std::string company; 
	long shares;
	double share_val;
	double tot_val;
	//�Լ� :: ���� �Լ����� ���
	void set_tot() { tot_val = shares * share_val; }
	
	
public:
	void acquire(const std::string&co, long n, double pr); // �ܺο��� ���� �Լ�
	void buy(long num, double price); // �ܺο��� ���� �Լ�
	void sell(long num, double price); // �ܺο��� ���� �Լ�
	void show(); // �ܺο��� ���� �Լ�

	void update(double price); // public���� ����Ǿ����� �ܺο��� ������ ����
};

#endif // !STOCK00_H_
