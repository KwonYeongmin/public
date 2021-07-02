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

/*
level *Search(level *t, const int *num) 
{
	int p;
	int x;
	if (&t->no < num) x = 0;
	else  x = 1;

	if (p == NULL) 
	{
		return NULL;
	}
	else if (x == 0)return t;
	else if (x < 0)Search(t->left,num);
	else Search(t->right, num);
}

level *addData(level *t, const int *num) 
{

}

int deleteData(level **root, const int *num) 
{

}

void Print(const level *t) 
{

}*/


//����
void BinTree::addData(level t)
{
	level *p = head;

	level *n = new level;
	n->name = t.name;
	n->no = t.no;

	if (head == nullptr)
	{
		head = n;
		head->up = nullptr;
		head->left = nullptr;
		head->right = nullptr;
	}
	else
	{
		/*cout << "--p �̵� ��----------------" << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx << endl;*/

		while (p->left != nullptr || p->right != nullptr)
		{
			if (p->no > n->no && p != nullptr)
			{
				if (p->left == NULL) break;
				p = p->left;
			}
			else if (p->no < n->no && p != nullptr)
			{
				if (p->right == NULL) break;
				p = p->right;
			}

		}
		/*cout << "--p �̵� ��---------------- " << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx<<endl;*/
		if (p->no > n->no)
		{
			//����
			p->left = n;
			n->up = p;
		}
		else if (p->no < n->no)
		{
			//������
			p->right = n;
			n->up = p;
		}
		/*cout << "--n ���� ��---------------- ()" << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx;
		cout << ", n: " << n->idx ;
		if (p->left != nullptr) { cout << " , p -> left: " << p->left->idx ; }
		if (p->right != nullptr) { cout << " ,p -> right: " << p->right->idx; }
		cout << endl;*/
	}
	n->left = nullptr;
	n->right = nullptr;
}



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

//	 setEdge(t);
}

//�˻� -> ��ȣ ������ ���� ��ȣ ��� 
int BinTree::Search(int *num, string *str, int mode)
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
				if (p->no > *num) p = p->left;
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
	level *p = new  level;
	level *hh = head;
	int dir = 1;
	p = min;

	while (p!=max)
	{
		if (dir==1)  //����ϸ鼭 �������ų� �ö�
		{
			cout << p->no << " : " << p->name << endl;

			//�ö�
			if (p->no < p->up->no) 
			{
				p = p->up;
			}
			//������
			else 
			{
			
			}
			
			
		}
		else //�׳� �������ų� �ö� //dir=-1
		{
			if (1)
			{

			}
			//�ö�
			else
			{

			}
		}
		if (1) 
		{
			hh = p;
			if (1) {}
		}

		
		
	}
}