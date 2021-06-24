// 0623_algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "singleLinkedList.h"
#include"doubleLinkedList.h"
#include <iostream>

using namespace std;
int doubleLinkedList()
{
	DList *node = new DList[10];
	doubleList list(node);
	int count = 0;
	int menu;

	string name;
	int no;
	while (1)
	{
		cout << "< 메뉴 선택 > " << endl;
		cout << "(1). 학생 추가 (2). 학생 삭제 (3). 전체 출력 (4). 검색 (5).종료 \n";
		cin >> menu;
		if (menu == 5) { return 0; }
		switch (menu)
		{
		case 1:
		{
			
			/*cout << " <학생 추가> " << endl;
			cout << "이름 입력: ";
			cin >> node[count].name;
			cout << "번호 입력: ";
			cin >> node[count].no;
			list.addMiddle(node[count]);
			count++;*/
			
			DList temp;
			cout << " <학생 추가> " << endl;
			cout << "이름 입력: ";
			cin >> temp.name;
			cout << "번호 입력: ";
			cin >> temp.no;
			list.addMiddle(temp);
		}
		break;
		case 2:
		{
			cout << " < 학생 삭제 > " << endl;
			cout << "번호 입력: ";
			cin >> no;
			list.deleteMiddle_index(no);
		}
		break;
		case 3:
		{
			cout << " < 전체 출력 > " << endl;
			list.Print();
		}
		break;
		case 4:
		{
			cout << " < 검색 > : (1). 번호로 검색 (2). 이름으로 검색" << endl;
			cin >> no;
			if (no == 1)
			{
				cout << "번호로 검색 :: " << endl;
				cin >> no;
				if (list.search_index(no) == "-1") cout << "자료가 없습니다.";
				else
				{
					cout << no << " : " << list.search_index(no) << endl;
				}
				break;
			}
			else if (no == 2)
			{
				cout << "이름로 검색 :: " << endl;
				cin >> name;
				if (list.search_name(name) == -1) cout << "자료가 없습니다.";
				else
				{
					cout << no << " : " << list.search_name(name) << endl;
				}
				break;
			}

		}
		break;

		}

	}
	delete node;
	return 1;
}
void singleLinkedList()
{
	mystruct *node = new mystruct[10];
	MyList list(node);
	int count = 0;
	int menu;

	string name;
	int no;
	while (1)
	{
		cout << "< 메뉴 선택 > " << endl;
		cout << "(1). 학생 추가 (2). 학생 삭제 (3). 전체 출력 (4). 검색 (5).종료 \n";
		cin >> menu;
		if (menu == 5) break;
		switch (menu)
		{
		case 1:
		{
			mystruct temp;
			cout << " <학생 추가> " << endl;
			cout << "이름 입력: ";
			cin >> temp.name;
			cout << "번호 입력: ";
			cin >> temp.no;
			//list.addFront(temp);
			list.addSort(temp);
		}
		break;
		case 2:
		{
			cout << " < 학생 삭제 > " << endl;
			cout << "번호 입력: ";
			cin >> no;
			list.deleteMiddle_index(no);
		}
		break;
		case 3:
		{
			cout << " < 전체 출력 > " << endl;
			list.Print();
		}
		break;
		case 4:
		{
			cout << " < 검색 > : (1). 번호로 검색 (2). 이름으로 검색" << endl;
			cin >> no;
			if (no == 1)
			{
				cout << "번호로 검색 :: " << endl;
				cin >> no;
				if(list.search_index(no)=="-1") cout<<"자료가 없습니다.";
				else 
				{
					cout << no << " : " << list.search_index(no) << endl;
				}
				break;
			}
			else if (no == 2)
			{
				cout << "이름로 검색 :: " << endl;
				cin >> name;
				if (list.search_name(name) == -1) cout << "자료가 없습니다.";
				else
				{
					cout << no << " : " << list.search_name(name) << endl;
				}
				break;
			}
		}
		break;
		}
	}
	delete node;
}



int main()
{

	DList *node = new DList[10];
	doubleList list(node);
	DList node1 = { 1,"a" };
	DList node2 = { 2,"b" };
	DList node3 = { 3,"c" };
	DList node4 = { 4,"d" };
	DList node5 = { 5,"f" };
	
	list.addMiddle(node1);
	list.addFront(node2);
	list.addFront(node3);
	list.Print();
	//list.Print();
	/*
	cout << "-------\n";
	list.addMiddle(node2);
	list.Print();
	cout << "-------\n";
	list.addMiddle(node5);
	list.Print();
	cout << "-------\n";

	list.Print();
	cout << "-------\n"; 
	list.addMiddle(node3);
	list.Print();
	
	cout << "-------\n";
	list.addMiddle(node4);
	list.Print();*/

	//doubleLinkedList();
	return 0;
}






