#pragma once
#include<iostream>
#include <string>
typedef struct List
{
	int no;
	std::string name;
	List *left;
	List *right;
	List *up;
}level;

//템플릿으로 바꾸기
class BinTree
{
private:
	int no;
	std::string name;
	level *head;
	level *tail;

	level *min=NULL;
	level *max=NULL;
public:
	//초기화
	
	BinTree(level *n);
	~BinTree();
	//삽입
	void addData(level t); 
	//삭제
	void deleteData(int num);
	void setEdge(level t);
	//검색 -> 인덱스 출력
	int Search(int *num, std::string *str, int mode);
	//번호출력
	int search_name(std::string name);
	//이름 출력
	std::string search_no(int no);
	//전체 출력
	void Print();

	/*level *Search(level *t, const int *num);
	level *addData(level *t, const int *num);
	int deleteData(level **root,const int *num);
	void Print(const level *t);*/
};





