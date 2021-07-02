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
	doubleList();
	~doubleList();
	//��� �߰�
	void addFront(DList t);
	void addBack(DList t);
	//void addMiddle(DList t, DList prev);
	void addMiddle(DList t);
	//void addMiddle_index(DList t, int index);

	//��� ����
	void deleteFront();
	void deleteBack();
	//void deleteMiddle(DList t);
	void deleteMiddle_index(int index);
	//�˻�
	std::string search_index(int num);
	int search_name(std::string str);
	int search(int num);
	//����Ʈ ���
	void Print();

	//void xx(DList t);
};

