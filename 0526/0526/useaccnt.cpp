#include "account.h"
/*
int main()
{
	string name;
	string accntNum;
	double money;
	int ck;
	//�̸�, ���� �Է�
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	if (name.length() > 30) 
	{
		cout << "�̸��� 30�� �Ѱ� �Է��� �� �����ϴ�." << endl; 
		cin >> name;
	}

	
	cout << "���¸� �Է��ϼ��� : ";
	cin >> accntNum;
	if (accntNum.length() > 80)
	{
		cout << "���ڸ� 80�� �Ѱ� �Է��� �� �����ϴ�. " << endl; 
		cin >> accntNum;
	}


	//���
	BankAccount BankAccount(name, accntNum,0);
	cout << "�Է� �� ���" << endl;
	BankAccount.Print(); 
	cout << endl;

	cout << "(1)��� (2)�Ա� (0)���� : " << endl;
	cin >> ck;
	switch(ck)
	{
		//�Ա�
	case 1:
		cout << "�Ա��� �ݾ��� �Է��ϼ��� : ";
		cin >> money;
		if(money<0){ cout << "�ٽ� �Է����ּ���."<<endl; cout << "�Ա��� �ݾ��� �Է��ϼ��� : "; cin >> money; }
		else
		{
			cout << "�Ա� �Ϸ�" << endl;

			BankAccount.deposit(money);
			BankAccount.Print();
			cout << endl;
		}
		break;
	case 2:
	}
	if (ck == 1) 
	{
		

		

		//���
		cout << "����� �ݾ��� �Է��ϼ��� : ";
		cin >> money;

		cout << "��� �Ϸ�" << endl;

		BankAccount.withdraw(money);
		BankAccount.Print();  
		cout << endl;
	
	}
	else if (ck == 0) cout << "���α׷��� �����մϴ�." << endl;
	else cout << "�ٽ� �Է����ּ���. " << endl;

	
	return 0;
}

*/