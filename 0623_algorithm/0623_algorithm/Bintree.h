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
	//����
	void addData(level t); 
	//����
	void deleteData(int num);
	void setEdge(level t);
	//�˻� -> �ε��� ���
	int Search(int *num, std::string *str, int mode);
	//��ȣ���
	int search_name(std::string name);
	//�̸� ���
	std::string search_no(int no);
	//��ü ���
	void Print();

	/*level *Search(level *t, const int *num);
	level *addData(level *t, const int *num);
	int deleteData(level **root,const int *num);
	void Print(const level *t);*/
};





