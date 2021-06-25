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
	//삽입 -> 꽉찼다는거알려주기
	void addData(level t); 
	//void addFront(level t);
	//void addBack(level t);

	//삭제 -> 삭제할 데이터 없다는 거 알려주기 
	void deleteData(int num);
	//void deleteFront(level t);
	//void deleteBack(level t);

	//검색 -> 인덱스 출력
	void setEdge(level t);
	int search(int *num, std::string *str, int mode);
	//번호출력
	int search_name(std::string name);
	//이름 출력
	std::string search_no(int no);
	//전체 출력
	void Print();
	
};





