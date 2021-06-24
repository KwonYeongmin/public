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

//��� �߰�
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

//��� ����
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

//�˻�
std::string doubleList::search_index(int num) { return "none"; }
int doubleList::search_name(std::string str) { return 1; }

//����Ʈ ���
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