#pragma once
#include <iostream>
#include<string>

typedef struct s
{
	int idx;
	std::string name; //��ȭ�ϴ� ��
	s *right;
	s *left;
	s *up;
	int leftVal;
	int rightVal;
}s;
class AVLtrees
{
private:
	s *head;
public:
	AVLtrees(); // ������
	//void test(s t);
	void AddData(s t);
	void SortData(s *p);
	void DeleteData();
	void Search();
	void Print();
};

