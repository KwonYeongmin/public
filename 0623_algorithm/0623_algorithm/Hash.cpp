#include "Hash.h"
using namespace std;

//해시 테이블 초기화
Hash::Hash(ChainHash *hh, int size) //size=13
{
	h = hh;
	
	if ((h->table = new ss*[size]) == NULL)
	{
		h->size = 0;
	}
	else 
	{
		h->size = size;
		for (int i = 0; i < size; i++) //size자리 만들기
		{
			h->table[i] = NULL;
		}
	}
	
}


//해시테이블 파괴자
Hash::~Hash() {}


//검색
//숫자를 입력하면 인덱스 나옴
int **Hash::Search( int no)
{
	int **arr = { 0 };
	return arr;
}
//인덱스 입력하면 이름나옴
std::string Hash::Search_name(int **idx)
{
	string id = "none";
	return id;
}

//데이터 추가
void Hash::AddData(ss tdata)
{
	int index = ( tdata.no) % 13 ;
	//0 1 2 3 4 5 6 7 8 9 10 11 12
	head = (h->table[index]);
	ss *p = (h->table[index]);
	
	if (head == NULL) 
	{
		(h->table[index]) = &tdata;
		//(h->table[index]->next) = NULL;
		//h->table[index]->next = NULL;
	}
	else 
	{	
		//cout << p->no << " : " << p->name << endl;
		while (p!=NULL)
		{
			p = p->next; 
		}
		p = &tdata;
		tdata.next = NULL;
		//cout << p->no << " : " << p->name << endl;
	}
	cout << "헤드 값 : " << h->table[index]->no << endl;
}

//데이터 삭제
int Hash::deleteData()
{
	return 0;
}

//해시테이블 출력
void Hash::Print()
{
	ss *tt = h->table[0];
	if (tt == NULL) 
	{
		cout << "해시가 없음"; 
	}
	while(tt!=NULL)
	//for (int i = 0; i < 2; i++)
	{
		cout << tt[0].no<<" : ";
		cout << tt[0].name<<endl;
		tt = tt->next;
	
		/*
		cout << tt[i].no << " : ";
		cout << tt[i].name << endl;
		*/
	}
	
	
}

//모든데이터 삭제
void Hash::Clear(ChainHash *h)
{

}

void Hash::terminate(ChainHash *h,int size)
{
	delete[] h->table;

	for (int i = 0; i < size; i++) 
	{
		delete[] h->table[i];
	}
}
