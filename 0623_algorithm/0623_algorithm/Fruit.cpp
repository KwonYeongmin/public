#include "Fruit.h"

using namespace std;

//리스트 초기화
MyList::MyList(mystruct *h)
{
	//구조체 초기화
	head = h;
	tail = h;

	while (1)
	{
		if (tail->next == NULL) break; 
		tail = tail->next;
	}
	
}


//노드 추가
int MyList::addFront(mystruct *n)
{
	if (head == NULL) return -1;
	else 
	{
		n->next = head;
		head = n;
		return 1;
	}	
}

int MyList::addBack(mystruct *n)
{
	if (head == NULL) return -1;
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

int MyList::addMiddle(mystruct *n,int index)
{
	if (head == NULL) return -1;
	else
	{
		mystruct *prev = head;
		for (int i = 0; i < index-2;i++) 
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

int MyList::deleteMiddle(int index)
{
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
	//cout << "끝" << endl;
	
	delete index;
}

void MyList:: sorting() 
{
	
	int min_index = head->no;
	mystruct *index;
	index = head->next;
	mystruct *min;
	min = head;
	
	while (index!=NULL)
	{
		if (min_index > index->no)
		{
			min_index = index->no;
			min = index;
			index->next = min;
			index = min;
			Print();
			
			
			//cout<< min->no<<" : " <<min->name << endl;
			cout << "-------" << endl;
		}
		index = index->next;
	}
	//cout << "min: " << min_index << endl;

	delete index;
	delete min;

}
