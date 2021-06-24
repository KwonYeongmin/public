#include "doubleLinkedList.h"
using std::cout;
using std::endl;



doubleList::doubleList(DList *h)
{
	head = NULL;
	tail = NULL;

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
		n->next->prev=n;
	}
	head->prev = NULL;
}

void doubleList::addBack(DList t)
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
		tail->next = n;
		n->prev = tail;
		tail = n;

	}
	tail->next = NULL;
}


void doubleList::addMiddle(DList t) 
{
	DList *n = new DList;
	n->name = t.name;
	n->no = t.no;
	
	DList *p = new DList;
	p = head;
	
	if (head == NULL) { addFront(t); }
	else
	{
		while (1)
		{
			if (p->no<t.no) 
			{
				p = p->next;
			}
			else
			{
				n->next = p;
				//p = n;
				//n->next->prev = n;
				break;
			}
			if (p->next == NULL) { addBack(t); }
		}
	}

}
/*
void doubleList::addMiddle_index(DList t, int no) //숫자 no 뒤에 넣기
{
	DList *n = new DList;
	n->name = t.name;
	n->no = t.no;
	
	DList *p = new DList;
}*/

//노드 삭제
void doubleList::deleteFront() 
{
	if (head != NULL) 
	{	
		head = head->next;
		head->next->prev = head;
	} 
}

void doubleList::deleteBack() 
{
	if (head != NULL)
	{
		tail=tail->prev;
	}
	tail->next = NULL;
}


void doubleList::deleteMiddle_index(int no) 
{
	DList *p = new DList;
	p = head;
	if (head != NULL) 
	{
		//이진 검색 구현
		//숫자를 넣으면 인덱스가 나오도록
		for (int i = 0; i < search(no); i++) 
		{
			p = p->next;
		}
		/*while (1)
		{	if (p->no == no) break;p = p->next; }*/

		if (p->prev == NULL) 
		{
			deleteFront();
		}
		else if (p->next == NULL) 
		{
			deleteBack();
		}
		else 
		{
			p->prev->next = p->next;
		}
	}
}
//인덱스 값으로 나옴
//숫자를 넣으면 인덱스가 나오도록
int doubleList::search(int no)
{
	int index=0;
	DList *hh = new DList;
	DList *tt = new DList;
	DList *p = new DList;
	p = head;
	hh = head;
	tt = tail;
	if (head != NULL)
	{
		if (head == tail)
		{
			index = 1;
			return index;
		}
		else
		{
			while (p->no <= tt->no)
			{
				hh = hh->next;
				tt = tt->prev;
				p = hh;
				//cout << p->no << hh->no << tt->no << endl;
				if (p->no == no) { break; }
				else if (p->no < no) {tt = tail; }
				else  { hh = head; }
			}
			hh = head;

			while (1) 
			{
				if (hh == p) break;
				index++;
				hh = hh->next;
			}
		}
	}
	return index;
}

std::string doubleList::search_index(int num) 
{
	DList *p = new DList;
	p = head;
	for (int i = 0; i < search(num); i++) 
	{
		p = p->next;
	}
	return p->name; 
}

int doubleList::search_name(std::string str)
{
	if (head == NULL) { return -1; }
	else
	{
		DList *p = head;
		while (p->name != str)
		{
			p = p->next;
		}
		return  p->no;
	}
}

//리스트 출력
void doubleList::Print() 
{
	DList *index = new  DList;
	index = head;

	while (index != NULL)
	{
		cout << index->no << ": " << index->name<< endl;
		index = index->next;
	}
	//delete[] index;
}