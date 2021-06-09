#include "tv.h"
#include <iostream>

bool Tv::volup() 
{
	if (volume < MaxVal) { volume++; return true; }
	else { return false; }
}
bool Tv::voldown() 
{
	if (volume >MinVal) { volume--; return true; }
	else { return false; }
}
void Tv::chanup() 
{
	if (channel < maxchannel) channel++;
	else channel = 1;
}

void Tv::chandown()
{
	if (channel > 1) channel--;
	else channel = maxchannel;
}

void Tv::setting() const 
{
	using std::cout;
	using std::endl;
	cout << "TV = " << (state == off ? "OFF" : "ON") << endl;
	if (state == on) 
	{
		cout << "볼륨 = " << volume << endl;
		cout << "채널 = " << channel << endl;
		//추가
		
		cout << "모드 = "
			<< (mode == Antenna ? "지상파방송" : "케이블 방송") << endl;
		cout << "입력 = " << (input == TV ? "TV" : "DVD") << endl;
		
	}
}


void Remote::Print()
{
	using std::cout;
	using std::endl;
	cout << "모드 2 = "
	<< (n_mode == NORMAL ? "일반 모드" : "대화 모드") << endl;
}

void Tv::n_mode_(Remote &r) { r.n_mode = (r.n_mode == r.NORMAL) ? r.TALK : r.NORMAL; }
