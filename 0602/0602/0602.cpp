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
	cout << "Hogg���ǰ��¿� %1000 �Ա�:\n";
	Hoggy.Deposit(1000.0);
	cout << "Hogg���� �����ܾ�: $" << Hoggy.Balance() << endl;
	cout << "Piggy���� ���¿��� $4200����:\n";
	Piggy.Withdraw(4200.0);
	cout << "Piggy���� ���� �ܾ�:$" << Piggy.Balance() << endl;
	cout << "Hogg���� ���¿��� $4200 ����:\n";
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
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);
		cout << "���� ���¹�ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempNum;
		cout << "���� �����ܾ��� �Է��Ͻʽÿ�: ";
		cin >> tempbal;
		cout << "Brass ���´� 1"
			<<"BrassPlus���¿��� 2�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1'&&kind != '2'))
			cout << "1�ƴϸ� 2�� �Է��Ͻʽÿ�: ";
		if (kind == '1') 
		{
			p_clients[i] = new Brass(temp, tempNum, tempbal);
		}
		else 
		{
			double tmax, trate;
			cout << "���� ��� �յ� �Է�: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ�: ";
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
	cout << "���α׷��� �����մϴ�.\n";
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
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);
		cout << "���� ���¹�ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempNum;
		cout << "���� �����ܾ��� �Է��Ͻʽÿ�: ";
		cin >> tempbal;
		cout << "Brass ���´� 1"
			<< "BrassPlus���¿��� 2�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1'&&kind != '2'))
			cout << "1 �Ǵ� 2�� �Է��Ͻʽÿ�: ";
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempNum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "���� ��� �Ѱ� �Է�: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ�: ";
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
	cout << "���α׷��� �����մϴ�.\n";
}*/