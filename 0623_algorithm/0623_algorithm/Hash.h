#pragma once
#include<iostream>
#include <string>
typedef struct sss
{
	int no;
	std::string name;
	struct sss *next;
}ss;
typedef struct
{
	int size;
	ss **table;
}ChainHash;

class Hash
{
private:
	ChainHash *h;
	int **index;
	ss *head;
	ss *tail;
public:
	//해시 테이블 초기화
	Hash(ChainHash *h, int size);
	//해시테이블 파괴자
	~Hash();
	//검색
	int **Search(int no); //숫자를 입력하면 인덱스 나옴
	std::string Search_name(int **idx); //인덱스 입력하면 이름나옴
	//데이터 추가
	void AddData(ss data);
	//데이터 삭제
	int deleteData();
	//해시테이블 출력
	void Print();
	//모든데이터 삭제
	void Clear(ChainHash *h);
	void terminate(ChainHash *h, int size);
};

