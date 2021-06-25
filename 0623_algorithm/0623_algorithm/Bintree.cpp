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

//삽입 -> 꽉찼다는거알려주기
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

	//맨처음에 들어오는 데이터 -> 레벨0
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
		//레벨 이동
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


//삭제 -> 삭제할 데이터 없다는 거 알려주기 
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
		cout << "저장된 데이터가 없습니다. ";
	}
	else 
	{
	
	}

	// setEdge(t);
}

//검색 -> 번호 들어오고 레벨 번호 출력 
int BinTree::search(int *num, string *str, int mode)
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

}