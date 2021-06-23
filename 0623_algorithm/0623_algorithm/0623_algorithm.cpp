// 0623_algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "Fruit.h"
#include <iostream>

using namespace std;

int main()
{
	//기존
	/*
	mystruct *node1 = new mystruct;
	node1->no = 4;
	node1->name = "strawberry";
	node1->next = NULL;

	mystruct *node2 = new mystruct;
	node1->next = node2;
	node2->no = 2;
	node2->name = "banana";
	node2->next = NULL;
	MyList list(node1);
	list.Print();
	return 0;

	// 새로운 노드
	mystruct *node3 = new mystruct;
	node3->no = 3;
	node3->name = "apple";

	// 새로운 노드
	mystruct *node4 = new mystruct;
	node4->no = 1;
	node4->name = "pineApple";




	list.addBack(node4);
	list.Print();
	cout << "node3 추가"<<endl;
	list.addMiddle(node3,node1);
	list.Print();*/
	/*
	cout << node2->name<<" node2 삭제" << endl;
	list.deleteMiddle(node2);
	list.Print();*/
	//cout << "<sorting>" << endl;
	//list.sorting();
	//list.Print();

	//cout << "정렬후" << endl;
	//list.Print();



	mystruct *node = new mystruct[10];
	MyList list(node);
	int count = 0;
	int menu;
	int submenu;
	string name;
	int no;
	while (1)
	{
		cout << "< 메뉴 선택 > " << endl;
		cout << "(1). 학생 추가 (2). 학생 삭제 (3). 학생 출력 (4). 종료 \n";
		cin >> menu;
		if (menu == 4) break;
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
			//list.addBack(temp);
			//list.addBack(temp);
			list.addMiddle_(temp,1);
			list.Print();
		}
		break;
		case 2:
		{
		}
		break;
		case 3:
		{
			list.Print();
		}
		break;
		}
		/*
		switch (menu)
		{
		case 1:
		{
			std::cout << "1.앞에 추가 2. 중간 추가 3. 뒤에 추가 4. 종료 \n";
			cin >> submenu;
			if (submenu == 1)
			{
				std::cout << "데이터 입력 >> " << std::endl;
				std::cout << "인덱스 입력: ";
				//cin >> node[count]->no;
				cin >> node->no;
				std::cout << "이름 입력: ";
				//cin >> node[count]->name;
				cin >> node->name;
				//list.addFront(node[count]);
				//list.addFront(node);
				count++;
				break;
			}
			else if (submenu == 2)
			{
				int num;
				std::cout << "추가하고 싶은 순서 입력: ";
				cin >> num;
				std::cout << "데이터 입력 >> " << std::endl;
				std::cout << "인덱스 입력: ";
				//cin >> node[count]->no;
				cin >> node->no;
				std::cout << "이름 입력: ";
				//cin >> node[count]->name;
				cin >> node->name;
				//list.addMiddle(node[count], node[count-1]);
				//list.addMiddle(node, node);
				count++;
				break;
			}
			else if (submenu == 3)
			{
				std::cout << "데이터 입력 >> " << std::endl;
				std::cout << "인덱스 입력: ";
				//cin >> node[count]->no;
				cin >> node->no;
				std::cout << "이름 입력: ";
				//cin >> node[count]->name;
				cin >> node->name;
				//list.addBack(node[count]);
				//list.addBack(node);
				count++;
				break;
			}
			else if (submenu == 4) { break; }
		}

		case 2:
		{
			std::cout << "1.맨앞 삭제 2. 중간 삭제 3. 뒤 삭제 4. 종료 \n";
			cin >> submenu;
			if (submenu == 1)
			{
				//list.deleteFront();
				break;
			}
			else if (submenu == 2)
			{
				int num;
				std::cout << "삭제하고 싶은 자료 순서 입력: ";
				cin >> num;
				//list.deleteMiddle(node[count - 1]);
				//list.deleteMiddle(node);
				break;
			}
			else if (submenu == 3)
			{
				//list.deleteBack();
				//list.Print();
				break;
			}
			else if (submenu == 4) { break; }
		}

		case 3:
			//list.Print();
			break;
		}

	}
	delete node;
	for (int i = 0; i < count; i++)
	{
		//delete node[i];
	}*/
		
	}
	return 0;
}

/*

cout << "리스트 출력 :: " << endl;
list.Print();

//list.addMiddle(node3, node1);
cout << node1->name << " 다음에 ";
cout << "추가 후 리스트 출력 :: " << endl;
list.Print();

list.addFront(node4);
cout << "맨 앞에 노드 추가 후 리스트 출력 :: " << endl;
list.Print();

//노드 삭제
cout << " // 삭제 //" << endl;
//cout << "맨 뒤에 노드 삭제 후 리스트 출력 :: " << endl;

//"apple";
list.deleteBack();
list.Print();


//cout << node3<<" 뒤의 노드 삭제 후 리스트 출력 :: " << endl;

//list.deleteFront();
//list.Print();
*/




