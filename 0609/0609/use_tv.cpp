
#include <iostream>
#include "tv.h"

int main() 
{
	using std::cout;
	Tv s42;
	Remote grey;

	cout << "42\" TV�� �ʱ� ������ : \n";
	s42.setting();
	cout << "\n42\" TV�� ����� ������: \n";
	s42.onoff(); //���� ����
	grey.set_n_mode(s42);
	s42.setting();
	grey.Print();

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.set_n_mode(s42);
	cout << "\n ������ ����� 42\" TV�� ������: \n";
	s42.setting();
	grey.Print();

	return 0;
}