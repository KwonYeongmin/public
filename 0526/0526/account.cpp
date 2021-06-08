#include "account.h"

using namespace std;

BankAccount::BankAccount()
{
	//초기화
	name = "no name";
	account = "111";
}
BankAccount::BankAccount(const string &name_, const string &account_, double balance_)
{

	name = name_;
	account = account_;
	balance = balance_;
}

void BankAccount::Print()
{
	cout << "이름 : " << name << endl;
	cout << "계좌 : " << account << endl;
	cout << "잔액 : " << balance << endl;

}

//입금
void BankAccount::deposit(double money)
{
	balance += money;
}

//출금
void BankAccount::withdraw(double money)
{
	balance -= money;
}
