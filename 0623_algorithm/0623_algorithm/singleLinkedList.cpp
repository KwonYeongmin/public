#include "singleLinkedList.h"

using namespace std;

//����Ʈ �ʱ�ȭ
MyList::MyList(mystruct *h)
{
	//����ü �ʱ�ȭ
	head = NULL;
	tail = NULL;
}
MyList::~MyList( ) 
{
	delete head;
	delete tail;
}

//��� �߰�
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
		head = n;
		tail = n;
		
	}
	else
	{
	/*	mystruct *index = head;

		while (1)
		{
		//	if (index->next== NULL)break;
			//index = index->next;
		}*/
		tail->next = n;
		tail=n;
		tail->next = NULL;
		
		
	}
	return 1;
}
//
int MyList::addMiddle(mystruct *n, mystruct *prev)
{
	if (head == NULL) return -1;
	else
	{
		n->next = prev->next;
		prev->next=n;
		return 1;
	}
}
int MyList::addMiddle_index(mystruct t, int index)
{
	mystruct *n = new mystruct;
	n->name = t.name;
	n->no = t.no;
	if (head == NULL) 
	{
		head = n;
		tail = n;
		tail->next = NULL;
	}
	else
	{
		mystruct *prev = head;
		for (int i = 0; i < index-1; i++)
		{
			prev = prev->next;
		}
		n->next = prev->next;
		prev->next = n;

		return 1;
	}
}

int MyList::addSort(mystruct t) 
{
	int index=0;
	mystruct *p = new mystruct;
	//��ġ ã��
	if (head != NULL)// && head->next!=NULL) 
	{
		p = head;
		while (1)
		{
			if (p->next != NULL)
			{
				if (p->next->no < t.no)break;
			}
			else
			{
				if (p->no < t.no) break; 
			}		
			p = p->next;
			index++;
		}
		addMiddle_index(t, index-1);
	}
	else { addMiddle_index(t, index); }
	
	
	return 1;
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

//�ε����� ����
int MyList::deleteMiddle_index(int index)
{
	if (head == NULL) return -1;
	else
	{
		mystruct *prev = head;
		for (int i = 0; i < index; i++)
		{
			prev = prev->next;
		}
		mystruct *d = prev->next;

		prev->next = d->next;
		delete d;


		return 1;
	}
}
//�˻�
//��ȣ�� �˻�

std::string MyList::search_index(int num)
{
	if (head == NULL) 
	{
		return "-1";
	}
	else 
	{
		mystruct *index = head;
		while (index->no != num)
		{
			index = index->next;
		}
		return index->name;
	}
}
//�̸����� �˻�
int MyList::search_name(string str) 
{
	if (head == NULL) { return -1; }
	else 
	{
		mystruct *index = head;
		while (index->name != str)
		{
			index = index->next;
		}
		
		return  index->no;
	}
} 
//����Ʈ ���
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
/*
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
			
			//index�� min�ٲ��ֱ�
			min->next= index->next;
			cout<< index->name <<" , "<<index->next->name<<endl;
			min->next = index;
			//index->next = min;
			Print();
			cout << "-------" << endl;
		}
		index = index->next;
	}
	delete index;
	delete min;

}*/
