#pragma once
#include<iostream>
#include <string>
typedef struct List
{
	int no;
	std::string name;
	List *left;
	List *right;
	List *up;
}level;

//���ø����� �ٲٱ�
class BinTree
{
private:
	int no;
	std::string name;
	level *head;
	level *tail;

	level *min=NULL;
	level *max=NULL;
public:
	//�ʱ�ȭ
	BinTree(level *n);
	~BinTree();
	//���� -> ��á�ٴ°ž˷��ֱ�
	void addData(level t); 
	//void addFront(level t);
	//void addBack(level t);

	//���� -> ������ ������ ���ٴ� �� �˷��ֱ� 
	void deleteData(int num);
	//void deleteFront(level t);
	//void deleteBack(level t);

	//�˻� -> �ε��� ���
	void setEdge(level t);
	int search(int *num, std::string *str, int mode);
	//��ȣ���
	int search_name(std::string name);
	//�̸� ���
	std::string search_no(int no);
	//��ü ���
	void Print();
	
};





