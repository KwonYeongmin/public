#pragma once
#include <string>
#include <iostream>

using namespace std;
class BankAccount
{
public:
	BankAccount();
	BankAccount(const string &name_, const string &account_, double balance_=0.0);
	void Print();
	void deposit(double money);
	void withdraw(double money);
	//~BankAccount();
private:
	string name;
	string account;
	double balance;
};


