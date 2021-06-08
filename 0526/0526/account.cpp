#include "account.h"

using namespace std;

BankAccount::BankAccount()
{
	//�ʱ�ȭ
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
	cout << "�̸� : " << name << endl;
	cout << "���� : " << account << endl;
	cout << "�ܾ� : " << balance << endl;

}

//�Ա�
void BankAccount::deposit(double money)
{
	balance += money;
}

//���
void BankAccount::withdraw(double money)
{
	balance -= money;
}
