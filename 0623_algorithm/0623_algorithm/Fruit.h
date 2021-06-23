#pragma once
#include <string>
#include <iostream>

typedef struct MyStruct
{
	int no;
	std::string name;
	struct  MyStruct* next;
}mystruct;

class MyList
{

private:
	int no;
	std::string name;
	mystruct *head;
	mystruct *tail;
	int size;
public:
	//����Ʈ �ʱ�ȭ
	MyList(mystruct *h);
	~MyList();
	//��� �߰�
	int addFront(mystruct t);
	int addBack(mystruct t);
	int addMiddle(mystruct *n, mystruct *prev);
	int addMiddle_(mystruct n, int index);

	//��� ����
	int deleteFront();
	int deleteBack();
	int deleteMiddle(mystruct *n);
	//�˻�
	std::string search();
	//����Ʈ ���
	void Print();
	std::string getName() { return tail->name; }
	int getNo() { return tail->no; }
	//����
	void sorting();// {}
	//
	int isEmpty(mystruct *s);
};

/*
�Է� ������ ������� ��ȣ ������� ���ĵ� ����Ʈ�� �����ϴ� ���α׷�
1. ����Ʈ �ʱ�ȭ
2. ��� �߰�
	2.1 ���� �տ� �߰�
	2.2 �� �ڿ� �߰�
	2.3 ��� ���̿� �߰�
3. ������
	3.1 ���� �� ������
	3.2 �� �� ����
	3.3 ���� ��� ����
4.�˻�
��ȣ�� �Է� �޾Ƽ� �ش� ��ȣ�� �̸� ���
5. ��� ����Ʈ ��ü ������ ���

�޴� ����
1. �л� �߰�
2. �л� ����
3. ��ü ���
4. ����

1->
*/
