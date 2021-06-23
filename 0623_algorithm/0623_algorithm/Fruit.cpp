#include "Fruit.h"

using namespace std;

//리스트 초기화
MyList::MyList(mystruct *h)
{
	//구조체 초기화
	head = NULL;
	tail = NULL;
	/*
	while (tail!=NULL)
	{
		//if (tail->next == NULL) break; 
		tail = tail->next;
	}*/

}
MyList::~MyList( ) 
{
	delete head;
	delete tail;
}

//노드 추가
int MyList::addFront(mystruct t)
{
	mystruct *n = new mystruct;
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
	cout << "헤드 " << head->no << " , " << head->name << endl;
	cout << "꼬리 " << tail->no << " , " << tail->name << endl;
	
	return 1;
		
}

int MyList::addBack(mystruct t)
{
	mystruct *n = new mystruct;
	n->name = t.name;
	n->no = t.no;
	if (head == NULL) 
	{
		n->next = NULL;
		tail = n;
		head = n;
	}
	else
	{
		mystruct *index = head;

		while (1)
		{
			if (index->next== NULL)break;
			index = index->next;
		}
		tail->next = n;
		tail=n;
		tail->next = NULL;
		
		return 1;
	}
	
}
//
int MyList::addMiddle(mystruct *n, mystruct *prev)//int index)
{
	/*
	if (head == NULL) return -1;
	else
	{
		//mystruct *prev = head;
		for (int i = 0; i < index-2;i++) 
		{
			prev = prev->next;
		}

		n->next = prev->next;
		prev->next = n;

		
		return 1;
	}*/
	if (head == NULL) return -1;
	else
	{
		n->next = prev->next;
		prev->next=n;
		return 1;
	}
}
int MyList::addMiddle_(mystruct t, int index)
{
	mystruct *n = new mystruct;
	n->name = t.name;
	n->no = t.no;
	if (head == NULL) return -1;
	else
	{
		mystruct *prev = head;
		for (int i = 0; i < index - 2; i++)
		{
			prev = prev->next;
		}

		n->next = prev->next;
		prev->next = n;


		return 1;
	}
}
int MyList::deleteFront()
{
	if (head == NULL) return -1;
	else
	{
		head = head->next;

		
		return 1;
	}
	
}

int MyList::deleteBack()
{
	if (head == NULL) return -1;
	else
	{
		mystruct *index=head;
		
		while (1)
		{
			if (index->next->next == NULL)break;
			index = index->next;
		}
		
		tail = index;
		tail->next = NULL;

		
		return 1;
	}
}

int MyList::deleteMiddle(mystruct *n)
{
	//인덱스로 삭제
	/*
	if (head == NULL) return -1;
	else
	{
		mystruct *prev = head;
		for (int i = 0; i < index-2; i++)
		{
			prev = prev->next;
		}
		mystruct *d = prev->next;

		prev->next = d->next;
		delete d;

	
		return 1;
	}*/
	if (head == NULL) return -1;
	else
	{
		mystruct *prev = head;
		while (1) 
		{
			prev = prev->next;
			if (prev != n)break;
		}
		prev->next=n->next;	
		return 1;
	}
}

//검색
std::string MyList::search()
{
	std::string str = "none";
	return str;
}

//리스트 출력
void MyList::Print() 
{
	mystruct *index;
	index = head;
	
	while (index != NULL)
	{
		cout<<index->no << ": " << index->name << std::endl;
		index = index->next;
	}	
	delete index;
}

void MyList:: sorting() 
{
	
	int min_index = head->no;
	mystruct *index;
	index = head->next;
	mystruct *min;
	min = head;
	mystruct *temp;
	while (index!=NULL)
	{
		if (min_index > index->no)
		{
			min_index = index->no;
			
			//index와 min바꿔주기
			min->next= index->next;
			cout<< index->name <<" , "<<index->next->name<<endl;
			min->next = index;
			//index->next = min;
			Print();
			cout << "-------" << endl;
		}
		index = index->next;
	}
	//cout << "min: " << min_index << endl;

	delete index;
	delete min;

}

int MyList::isEmpty(mystruct *s) 
{
	if (head == NULL) return -1;
	else return 1;
}
