#include<iostream>
#include "stringh.h"
using namespace std;
const int  ArSize = 10; const int  MaxLen = 81;
int main() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	String name; 
	cout << "����?\n";
	// cin >> name;
	cout << name << "�Ӵ�" << ArSize << "�����Է�(enter��):\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin&&cin.get() != '\n') continue;
		if (!cin || temp[0] == '\0') break;
		else sayings[i] = temp;
	}
	int tot = i;
	if (tot > 0) 
	{
		cout << "(������ ���� �Ӵ���� �Է�.)\n";
		for (i = 0; i < tot; i++) 
		{
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		}
		int shortest = 0;
		int first = 0;
		for (i = 1; i < tot; i++) 
		{
			if (sayings[i].length() < sayings[shortest].length()) shortest = i;
			if (sayings[i] < sayings[first])first = i;
		}
	}
}

