#include "AVLtrees.h"
using namespace std;
AVLtrees::AVLtrees()
{
	head = nullptr;
}

void AVLtrees::AddData(s t)
{
	s *p = head;

	s *n = new s;
	n->name = t.name;
	n->idx = t.idx;

	if (head == nullptr)
	{
		head = n;
		head->up = nullptr;
		head->left = nullptr;
		head->right = nullptr;
	}
	else
	{
	/*	cout << "--p 이동 전----------------" << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx << endl;*/

		while (p->left != nullptr || p->right != nullptr)
		{
			if (p->idx > n->idx && p != nullptr)
			{
				if (p->left == NULL) break;
				//p->leftVal++;
				p = p->left; 
			}
			else if (p->idx < n->idx && p != nullptr)
			{
				if (p->right == NULL) break;
				//p->rightVal++;
				p = p->right; 
			}
		}
	/*	cout << "--p 이동 후---------------- " << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx<<endl;*/
		if (p->idx > n->idx) { p->left = n; p->leftVal++;}
		else if (p->idx < n->idx) { p->right = n; p->rightVal++;}
		n->up = p;	
		//cout << "p: " << p->idx << " , p.left: " << p->leftVal << " ,p.right: " << p->rightVal << endl;
		/*cout << "--n 연결 후---------------- ()" << endl;
		cout << "head: " << head->idx << endl;
		cout << "p: " << p->idx;
		cout << ", n: " << n->idx ;
		if (p->left != nullptr) { cout << " , p -> left: " << p->left->idx ; }
		if (p->right != nullptr) { cout << " ,p -> right: " << p->right->idx; }
		cout << endl;*/
		cout << p->idx << endl;
		cout << "p->leftVal : " << p->leftVal << " , p->rightVal : " << p->rightVal << endl;
		
		//if (p->left != nullptr&&p->right != nullptr) { SortData(p); }
	}
	n->leftVal = 0;
	n->rightVal = 0;
	n->left = nullptr;
	n->right = nullptr;
	
	//if (p->left != nullptr&&p->right != nullptr) { SortData(p); }
}

void AVLtrees::SortData(s *p)
{
	cout << p->idx << endl;
	
	//경우

	if (p->left != nullptr&&p->right != nullptr) 
	{
		if (abs(p->right - p->left) >= 2)
		{
			//RR
			if (p->right!=nullptr&&p->right->right != nullptr)
			{
				s* uu;
				//middle
				p->up->right = p->right;
				p->right->up = p->up;
				uu = p->right;
				//min
				p->up = p->right;
				p->right = nullptr;
				uu->left = p;
				cout << "uu.left: " << uu->left << " , uu: " << uu << " , uu.right" << uu->right << endl;
				
			}
			//RL
			else if (p->right != nullptr&&p->right->left != nullptr) 
			{
				//RR로 만들기

			}
			//LL
			else if (p->left != nullptr&&p->left->left != nullptr)
			{
			
			}
			//LR
			else if (p->left != nullptr&&p->left->right != nullptr)
			{
			
			}
		}
	}

	
	//RR
	//RL
	//LL
	//LR

}

void AVLtrees::DeleteData()
{

}

void AVLtrees::Search()
{

}

void AVLtrees::Print()
{

}