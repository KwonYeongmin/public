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
public:
	//리스트 초기화
	MyList(mystruct *h);
	~MyList();
	//노드 추가
	int addFront(mystruct t);
	int addBack(mystruct t);
	int addMiddle(mystruct *n, mystruct *prev);
	int addSort(mystruct t); //index를 내보냄
	int addMiddle_index(mystruct t, int index);

	//노드 삭제
	int deleteFront();
	int deleteBack();
	int deleteMiddle(mystruct *n);
	int deleteMiddle_index(int index);
	//검색
	std::string search_index(int num);
	int search_name(std::string str);
	//리스트 출력
	void Print();
	/*
	std::string getName() { return tail->name; }
	int getNo() { return tail->no; }*/
};

/*
입력 순서와 상관없이 번호 순서대로 정렬된 리스트를 구현하는 프로그램
1. 리스트 초기화
2. 노드 추가
	2.1 제일 앞에 추가
	2.2 맨 뒤에 추가
	2.3 노드 사이에 추가
3. 노드삭제
	3.1 제일 앞 노드삭제
	3.2 맨 뒤 삭제
	3.3 사이 노드 삭제
4.검색
번호를 입력 받아서 해당 번호의 이름 출력
5. 출력 리스트 전체 데이터 출력

메뉴 선택
1. 학생 추가
2. 학생 삭제
3. 전체 출력
4. 종료

1->
*/
