#pragma once
#include <string>
#include <iostream>
typedef struct DList
{
	int no;
	std::string name;
	struct  DList* next;
	struct  DList* prev;
}DList;


class doubleList
{
private:
	int no;
	std::string name;
	DList *head;
	DList *tail;
public:
	//����Ʈ �ʱ�ȭ
	doubleList(DList *h);
	~doubleList();
	//��� �߰�
	void addFront(DList t);
	void addBack(DList t);
	void addMiddle(DList *n, DList *prev);
	void addMiddle_index(DList t, int index);

	//��� ����
	void deleteFront();
	void deleteBack();
	void deleteMiddle(DList *n);
	void deleteMiddle_index(int index);
	//�˻�
	std::string search_index(int num);
	int search_name(std::string str);
	//����Ʈ ���
	void Print();
};

