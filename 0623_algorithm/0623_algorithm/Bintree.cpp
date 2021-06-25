#include "Bintree.h"
using namespace std;
//생성자
BinTree::BinTree(level *n)
{
	head = NULL;
	tail = NULL;
}
//소멸자
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


//삽입
void BinTree::addData(level t)
{
	//level *pl = NULL;
	//level *pr = NULL;
	level *p =head;

	level *n = new level;
	n->name = t.name;
	n->no = t.no;

	//맨처음에 들어오는 데이터 
	if (head == NULL) 
	{
		n->right = NULL; n->left = NULL;
		head = n;
		tail = n;
	}
	else 
	{		
		while (p->left != NULL ||  p->right != NULL)
		{
			cout<<"p->no: " << p->no << endl;
			if (p->no > n->no && p != NULL) 
			{
				p = p->left;
			}
			else if (p->no < n->no && p != NULL) 
			{
				p = p->right;
			}
		}
		cout << "ck !! p: " ;
		cout << p->no << endl;
		if (p->no > n->no)
		{
			//왼쪽
			p->left = n;
			n->up = p;
		}
		else if (p->no < n->no) 
		{
		//오른쪽
			p->right = n;
			n->up = p;
		}
		cout << "p: " << p->no;
		cout << ", n: " << n->no;
		if (p->left != NULL) { cout << " , p-<left: " << p->left->no; }
		if (p->right != NULL) { cout << " ,p->right: " << p->right->no; }
		 cout << endl;
	}
	//cout << n->no << endl;
	n->left = NULL;
	n->right = NULL;
	setEdge(t);
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
		cout << "저장된 데이터가 없습니다. ";
	}
	else 
	{
	
	}

//	 setEdge(t);
}

//검색 -> 번호 들어오고 레벨 번호 출력 
int BinTree::Search(int *num, string *str, int mode)
{
	int index = 0;
	level *p = head;

	//min으로 찾아야 index 출력 가능
	//올라갈때
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

//번호출력
int BinTree::search_name(std::string name) 
{
	return 1;
}

//이름 출력
std::string BinTree::search_no(int no) 
{
	return "none";
}

//전체 출력
void BinTree::Print() 
{
	level *p = new  level;
	level *hh = head;
	int dir = 1;
	p = min;

	while (p!=max)
	{
		if (dir==1)  //출력하면서 내려가거나 올라감
		{
			cout << p->no << " : " << p->name << endl;

			//올라감
			if (p->no < p->up->no) 
			{
				p = p->up;
			}
			//내려감
			else 
			{
			
			}
			
			
		}
		else //그냥 내려가거나 올라감 //dir=-1
		{
			if (1)
			{

			}
			//올라감
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