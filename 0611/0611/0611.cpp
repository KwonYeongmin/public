
#include <iostream>
#include<vector>
#include<ctime>
#include  <algorithm>
#include <iterator>
#include <cstdlib> 

using namespace std;
void Show(const int n) { cout << n << " "; }

vector<int> Lotto(int n, int s)
{
	srand((unsigned int)time(0));
	vector<int> lotto;
	//rand()써서
	/*
	for (int i = 0; i < s; i++)
	{
		int number = rand() % n + 1;
		lotto.push_back(number);
	}	*/
	
	for (int i = 0; i < n; i++) lotto.push_back(i + 1);
	vector<int>::iterator it;
	
	random_shuffle(lotto.begin(), lotto.end());
	lotto.erase(lotto.begin() + s + 1, lotto.end());
	
	
	return lotto;
}

int main() 
{
	int select;
	cout << "임의의 수를 선택: \n";
	cin >> select;

	vector<int> winners;
	winners = Lotto(51,select);
	sort(winners.begin(), winners.end());
	cout << "로또 번호 :\n";
	for_each(winners.begin(), winners.end(), Show);

	return 0;
}