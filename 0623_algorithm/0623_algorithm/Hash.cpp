#include "Hash.h"
using namespace std;

//�ؽ� ���̺� �ʱ�ȭ
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
		for (int i = 0; i < size; i++) //size�ڸ� �����
		{
			h->table[i] = NULL;
		}
	}
	
}


//�ؽ����̺� �ı���
Hash::~Hash() {}


//�˻�
//���ڸ� �Է��ϸ� �ε��� ����
int **Hash::Search( int no)
{
	int **arr = { 0 };
	return arr;
}
//�ε��� �Է��ϸ� �̸�����
std::string Hash::Search_name(int **idx)
{
	string id = "none";
	return id;
}

//������ �߰�
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
	cout << "��� �� : " << h->table[index]->no << endl;
}

//������ ����
int Hash::deleteData()
{
	return 0;
}

//�ؽ����̺� ���
void Hash::Print()
{
	ss *tt = h->table[0];
	if (tt == NULL) 
	{
		cout << "�ؽð� ����"; 
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

//��絥���� ����
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
