// 0623_algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "singleLinkedList.h"
#include"doubleLinkedList.h"
#include "Bintree.h"
#include <iostream>

using namespace std;

int doubleLinkedList();
void singleLinkedList();

int binTrees()
{
	int size=15;
	//level *trees = (level*)calloc(size,sizeof(level));int count=0;
	level *lev = new level[size]; // [10]안쓰면 무한대로 증가 가능..?
	BinTree trees(lev);

	int menu; 
	int num=0; string str= "none";
	
	while (1)
	{
		cout << "(1).삽입 (2).삭제 (3).검색 (4).출력 (0).종료: " << endl;
		cin >> menu;
		if (menu == 0)
		{
			cout << "종료" << endl;
			return 0;
		}
		switch (menu)
		{
		case 1:
		{
			level temp;
			cout << "< 삽입 >" << endl;
			cout << "삽입하려는 데이터를 입력하세요. "<<endl;
			cout << "번호>> ";
			cin >> temp.no;
			cout << "이름>> ";
			cin >> temp.name;
			trees.addData(temp);
			//count++;if (count>=4) { trees = (level*)malloc(sizeof(level)*5); }
			
		}
		break;

		case 2:
		{
			cout << "< 삭제 >" << endl;
			cout << "번호 입력 >> ";
			cin >> num;
			trees.deleteData(num);
		}
		break;

		case 3:
		{
			cout << "< 검색 > :  (1). 번호로 검색 (2). 이름으로 검색 : " << endl;
			cin >> num;
			if (num == 1) 
			{
				cout << "번호 입력 >> ";
				cin >> num;
				trees.Search(&num,&str,0);
			}
			else if(num==2)
			{
				cout << "이름 입력 >> ";
				cin >> str;
				trees.Search(&num, &str, 1);
			}
			cout<<"[[DATA]] >> " << num << " : " << str << endl;
		}
		break;

		case 4:
		{
			cout << "< 출력 >" << endl;
			trees.Print();
		}
		break;
		}
	}

	delete[] lev;
	return 1;
}


int main()
{
	
	level *lev = new level[12]; 
	BinTree trees(lev);
	level node1 = { 11,"11" };
	level node2 = { 5,"5" };
	level node3 = { 4,"4" };
	level node4 = { 8,"8" };
	level node5 = { 7,"7" };
	level node6 = { 6,"6" };
	level node7 = { 9,"9" };
	level node8 = { 15,"15" };
	level node9 = { 13,"13" };
	level node10 = { 12,"12" };
	level node11 = { 18,"18" };
	level node12 = { 14,"14" };
	trees.addData(node1);
	trees.addData(node2);
	trees.addData(node3); 
	trees.addData(node5);
	trees.addData(node4);
	/*
	trees.addData(node5);
	trees.addData(node6);
	trees.addData(node7);*/
	
	return 0;
	binTrees();
	return 0;
}



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
}




