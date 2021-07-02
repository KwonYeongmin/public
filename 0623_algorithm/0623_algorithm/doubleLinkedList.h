#pragma once
#include <string>
#include <iostream>
typedef struct DList
{
	int no;
	std::string name;
	struct  DList* next;
	struct  DList* prev;
}DList;


class doubleList
{
private:
	int no;
	std::string name;
	DList *head;
	DList *tail;
public:
	//리스트 초기화
	doubleList();
	~doubleList();
	//노드 추가
	void addFront(DList t);
	void addBack(DList t);
	//void addMiddle(DList t, DList prev);
	void addMiddle(DList t);
	//void addMiddle_index(DList t, int index);

	//노드 삭제
	void deleteFront();
	void deleteBack();
	//void deleteMiddle(DList t);
	void deleteMiddle_index(int index);
	//검색
	std::string search_index(int num);
	int search_name(std::string str);
	int search(int num);
	//리스트 출력
	void Print();

	//void xx(DList t);
};

