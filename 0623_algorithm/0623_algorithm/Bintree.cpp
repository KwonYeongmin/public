#include "Bintree.h"
using namespace std;
//������
BinTree::BinTree(level *n)
{
	head = NULL;
	tail = NULL;
}
//�Ҹ���
BinTree::~BinTree() { delete[] head; delete[]tail; }

//���� -> ��á�ٴ°ž˷��ֱ�
/*
void BinTree::addFront(level t) 
{
	level *n = new level;
	n->name = t.name;
	n->no = t.no;
	if (head == NULL) 
	{
		n->right = NULL;
		head = n;
		tail = n;
	}
	else 
	{
		n->right = head;
		head = n;
		n->right->left = n;
	}
	head->left = NULL;
}

void BinTree::addBack(level t) 
{
	level *n = new level;
	n->name = t.name;
	n->no = t.no;
	if (head == NULL)
	{
		n->right = NULL;
		head = n;
		tail = n;
	}
	else
	{
		tail->right = n;
		n->left = tail;
		tail = n;

	}
	tail->right = NULL;
}
*/

void BinTree::addData(level t)
{
	level *n = new level;
	level *pl = NULL;
	level *pr = NULL;
	level *p =head;
	n->name = t.name;
	n->no = t.no;

	//��ó���� ������ ������ -> ����0
	if (head == NULL) 
	{
		n->right = NULL; n->left = NULL;
		head = n;
		tail = n;
		n->up = NULL;
	}
	else 
	{
		//cout << p->no << endl;
		//���� �̵�
		while (p->left != NULL || p->right!=NULL)
		{
	
			if (p->no > n->no) 
			{
				//p->left = NULL;
				p = p->left;
			}
			else if (p->no < n->no) 
			{
				//p->right = NULL;
				p = p->right;
			}
			
		}
		if (p->no > n->no) 
		{
			p->left = n;
			n->up = p;
		}
		else if(p->no < n->no)
		{
			p->right = n;
			n->up = p;
		}

		cout << p->no << endl; //11
	}
	n->left = NULL;
	n->right = NULL;
	setEdge(t);
}


//���� -> ������ ������ ���ٴ� �� �˷��ֱ� 
/*
void BinTree::deleteFront(level t)
{
	if (head != NULL)
	{
		head = head->right;
		head->right->left = head;
	}
}

void BinTree::deleteBack(level t) 
{
	if (head != NULL)
	{
		tail = tail->left;
	}
	tail->right = NULL;
}*/

void BinTree::setEdge(level t)
{
	level *pl = head;
	level *pr = head;
	while (pl->no < t.no && pl!=NULL) { pl = pl->left; }
	while (pr->no < t.no&& pr != NULL) { pr=pr->right; }
	min = pl;
	max = pr;
}
void BinTree::deleteData(int index)
{
	if (head == NULL) 
	{
		cout << "����� �����Ͱ� �����ϴ�. ";
	}
	else 
	{
	
	}

	// setEdge(t);
}

//�˻� -> ��ȣ ������ ���� ��ȣ ��� 
int BinTree::search(int *num, string *str, int mode)
{
	int index = 0;
	level *p = head;

	//min���� ã�ƾ� index ��� ����
	//�ö󰥶�
	//while (num > p->no) p = p->up;
	//p=5
	if (mode == 0 ) 
	{
		if (*num == head->no) { index = 0;  *num = p->no; }
		else 
		{
			while (1)
			{
				cout << p->no << " , " << p->name << endl;
				if (p->no > *num) 
				{
					p = p->left;
					
				} 
				else if (p->no < *num) p = p->right;
				if (p == NULL) break;
				index++;
			}
		}
		
		//cout << p->no << " : " << p->name << endl;
	}
	else if (mode == 1) 
	{
		
	}
	*num = p->no;
	*str = p->name;
	return index;
}

//��ȣ���
int BinTree::search_name(std::string name) 
{
	return 1;
}

//�̸� ���
std::string BinTree::search_no(int no) 
{
	return "none";
}

//��ü ���
void BinTree::Print() 
{

}