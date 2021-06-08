#include "tabtenn0.h"
#include <iostream>
tableTennisPlayer::tableTennisPlayer(const string &fn,
	const string &ln, bool ht) : firstName(fn), lastName(ln), hasTable(ht) {}

void tableTennisPlayer::Name() const 
{
	std::cout << "������(constructor) ȣ�� "<<std::endl;
	std::cout<< lastName << ", " << firstName ;
}
//�Ҹ��� ȣ�� Ȯ��
tableTennisPlayer::~tableTennisPlayer() 
{
	std::cout <<"�Ҹ���(destructor) ȣ�� "<< lastName << ", " << firstName << std::endl;
}


//�Ļ� Ŭ����
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht)
	: tableTennisPlayer(fn, ln, ht) {rating = r;}

RatedPlayer::RatedPlayer(unsigned int r, const tableTennisPlayer&tp)
	: tableTennisPlayer(tp), rating(r) {}
