#include "doubleLinkedList.h"
using std::cout;
using std::endl;



doubleList::doubleList(DList *h)
{
	head = NULL;
	tail = NULL;
	tail->prev = head;
	head->next = tail;
}
doubleList::~doubleList() 
{
	delete[] head;
	delete[] tail;
}

//노드 추가
void doubleList::addFront(DList t)
{
	DList *n = new DList;
	n->name = t.name;
	n->no = t.no;

	if (head == NULL)
	{
		n->next = NULL;
		head = n;
		tail = n;
	}
	else
	{
		n->next = head;
		head = n;
	}
	tail->next = NULL;
}
void doubleList::addBack(DList t)
{
	DList *n = new DList;
	n->name = t.name;
	n->no = t.no;

}
void doubleList::addMiddle(DList *n, DList *prev)
{

}
void doubleList::addMiddle_index(DList t, int index)
{

}

//노드 삭제
void doubleList::deleteFront() 
{
	if (head != NULL) 
	{
		head = head->next;
	} 
}
void doubleList::deleteBack() { }
void doubleList::deleteMiddle(DList *n) { }
void doubleList::deleteMiddle_index(int index) {  }

//검색
std::string doubleList::search_index(int num) { return "none"; }
int doubleList::search_name(std::string str) { return 1; }

//리스트 출력
void doubleList::Print() 
{
	DList *index = new  DList;
	index = head;

	while (index != NULL)
	{
		cout << index->no << ": " << index->name << endl;
		index = index->next;
	}
	//delete[] index;
}