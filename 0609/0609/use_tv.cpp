
#include <iostream>
#include "tv.h"

int main() 
{
	using std::cout;
	Tv s42;
	Remote grey;

	cout << "42\" TV의 초기 설정값 : \n";
	s42.setting();
	cout << "\n42\" TV의 변경된 설정값: \n";
	s42.onoff(); //켜진 상태
	grey.set_n_mode(s42);
	s42.setting();
	grey.Print();

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.set_n_mode(s42);
	cout << "\n 리모콘 사용후 42\" TV의 설정값: \n";
	s42.setting();
	grey.Print();

	return 0;
}