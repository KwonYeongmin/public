#include <iostream>
#include <string>
//#include"acctabc.h"
//#include<cctype>
//#include"brass.h"
//void useBrass1();
//void useBrass2();
//void useBrass3();

const int CLIENTS = 4;

int main() 
{
	return 0;
	//useBrass3();
	
	//useBrass1();
	//return 0;
	//useBrass2();
	//return 0;
}

/*
void useBrass1()
{
	using std::cout;
	using std::endl;
	Brass Piggy("porce Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horce Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Hogg씨의계좌에 %1000 입금:\n";
	Hoggy.Deposit(1000.0);
	cout << "Hogg씨의 현재잔액: $" << Hoggy.Balance() << endl;
	cout << "Piggy씨의 계좌에서 $4200인출:\n";
	Piggy.Withdraw(4200.0);
	cout << "Piggy씨의 현재 잔액:$" << Piggy.Balance() << endl;
	cout << "Hogg씨의 계좌에서 $4200 인출:\n";
	Hoggy.Withdraw(4200.0);
	Hoggy.ViewAcct();
}*/
/*
void useBrass2() 
{
	using std::cout;
	using std::cin;
	using std::endl;

	Brass *p_clients[CLIENTS];
	std::string temp; long tempNum; double tempbal;char kind;
	
	for(int i = 0; i < CLIENTS; i++) 
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌번호을 입력하십시오: ";
		cin >> tempNum;
		cout << "고객의 개설잔액을 입력하십시오: ";
		cin >> tempbal;
		cout << "Brass 계좌는 1"
			<<"BrassPlus계좌에는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1'&&kind != '2'))
			cout << "1아니면 2를 입력하십시오: ";
		if (kind == '1') 
		{
			p_clients[i] = new Brass(temp, tempNum, tempbal);
		}
		else 
		{
			double tmax, trate;
			cout << "당좌 대월 합도 입력: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempNum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n') continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++) 
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	cout << "프로그램을 종료합니다.\n";
}*/

/*
void useBrass3() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	AcctABC *p_clients[CLIENTS];
	std::string temp; long tempNum; double tempbal; char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌번호을 입력하십시오: ";
		cin >> tempNum;
		cout << "고객의 개설잔액을 입력하십시오: ";
		cin >> tempbal;
		cout << "Brass 계좌는 1"
			<< "BrassPlus계좌에는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1'&&kind != '2'))
			cout << "1 또는 2를 입력하십시오: ";
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempNum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한계 입력: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempNum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n') continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	cout << "프로그램을 종료합니다.\n";
}*/