#include "tabtenn0.h"
#include <iostream>
tableTennisPlayer::tableTennisPlayer(const string &fn,
	const string &ln, bool ht) : firstName(fn), lastName(ln), hasTable(ht) {}

void tableTennisPlayer::Name() const 
{
	std::cout << "생성자(constructor) 호출 "<<std::endl;
	std::cout<< lastName << ", " << firstName ;
}
//소멸자 호출 확인
tableTennisPlayer::~tableTennisPlayer() 
{
	std::cout <<"소멸자(destructor) 호출 "<< lastName << ", " << firstName << std::endl;
}


//파생 클래스
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht)
	: tableTennisPlayer(fn, ln, ht) {rating = r;}

RatedPlayer::RatedPlayer(unsigned int r, const tableTennisPlayer&tp)
	: tableTennisPlayer(tp), rating(r) {}
