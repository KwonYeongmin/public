#pragma once
#include<iostream>
#include <string>
typedef struct sss
{
	int no;
	std::string name;
	struct sss *next;
}ss;
typedef struct
{
	int size;
	ss **table;
}ChainHash;

class Hash
{
private:
	ChainHash *h;
	int **index;
	ss *head;
	ss *tail;
public:
	//�ؽ� ���̺� �ʱ�ȭ
	Hash(ChainHash *h, int size);
	//�ؽ����̺� �ı���
	~Hash();
	//�˻�
	int **Search(int no); //���ڸ� �Է��ϸ� �ε��� ����
	std::string Search_name(int **idx); //�ε��� �Է��ϸ� �̸�����
	//������ �߰�
	void AddData(ss data);
	//������ ����
	int deleteData();
	//�ؽ����̺� ���
	void Print();
	//��絥���� ����
	void Clear(ChainHash *h);
	void terminate(ChainHash *h, int size);
};

