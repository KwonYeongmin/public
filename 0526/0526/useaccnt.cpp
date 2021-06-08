#include "account.h"
/*
int main()
{
	string name;
	string accntNum;
	double money;
	int ck;
	//이름, 계좌 입력
	cout << "이름을 입력하세요 : ";
	cin >> name;
	if (name.length() > 30) 
	{
		cout << "이름을 30자 넘게 입력할 수 없습니다." << endl; 
		cin >> name;
	}

	
	cout << "계좌를 입력하세요 : ";
	cin >> accntNum;
	if (accntNum.length() > 80)
	{
		cout << "계자를 80자 넘게 입력할 수 없습니다. " << endl; 
		cin >> accntNum;
	}


	//출력
	BankAccount BankAccount(name, accntNum,0);
	cout << "입력 후 출력" << endl;
	BankAccount.Print(); 
	cout << endl;

	cout << "(1)출금 (2)입금 (0)종료 : " << endl;
	cin >> ck;
	switch(ck)
	{
		//입금
	case 1:
		cout << "입금할 금액을 입력하세요 : ";
		cin >> money;
		if(money<0){ cout << "다시 입력해주세요."<<endl; cout << "입금할 금액을 입력하세요 : "; cin >> money; }
		else
		{
			cout << "입금 완료" << endl;

			BankAccount.deposit(money);
			BankAccount.Print();
			cout << endl;
		}
		break;
	case 2:
	}
	if (ck == 1) 
	{
		

		

		//출금
		cout << "출금할 금액을 입력하세요 : ";
		cin >> money;

		cout << "출금 완료" << endl;

		BankAccount.withdraw(money);
		BankAccount.Print();  
		cout << endl;
	
	}
	else if (ck == 0) cout << "프로그램을 종료합니다." << endl;
	else cout << "다시 입력해주세요. " << endl;

	
	return 0;
}

*/