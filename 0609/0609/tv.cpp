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
		cout << "���� = " << volume << endl;
		cout << "ä�� = " << channel << endl;
		//�߰�
		
		cout << "��� = "
			<< (mode == Antenna ? "�����Ĺ��" : "���̺� ���") << endl;
		cout << "�Է� = " << (input == TV ? "TV" : "DVD") << endl;
		
	}
}


void Remote::Print()
{
	using std::cout;
	using std::endl;
	cout << "��� 2 = "
	<< (n_mode == NORMAL ? "�Ϲ� ���" : "��ȭ ���") << endl;
}

void Tv::n_mode_(Remote &r) { r.n_mode = (r.n_mode == r.NORMAL) ? r.TALK : r.NORMAL; }
