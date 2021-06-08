#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "IntQueue.h"
//#include "IntStack.h"
/*

int main()
{

	srand((unsigned)time(NULL));
	int arr[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		if (i <= 0 && i > 5) arr[i] = 0;
		else if (i <= 5 && i > 15) arr[i] = 1;
		else if (i <= 15 && i > 25) arr[i] = 2;
		else if (i <= 25 && i > 35) arr[i] = 3;
		else if (i <= 35 && i > 50) arr[i] = 4;
		else if (i <= 50 && i > 60) arr[i] = 5;
		else  arr[i] = 6;
	}
	int num[7] = { 0 };
	
	int cnt = 0;
	while(1){
		if (rand() % 7 == 0) { num[0]++; cnt++; }
		else if (rand() % 7 == 1) { num[1]++; cnt++; }
		else if (rand() % 7 == 2) { num[2]++; cnt++; }
		else if (rand() % 7 == 3) { num[3]++; cnt++; }
		else if (rand() % 7 == 4) { num[4]++; cnt++; }
		else if (rand() % 7 == 5) { num[5]++; cnt++; }
		else if (rand() % 7 == 6) { num[6]++; cnt++; }
		
		if (cnt == 100) break;
	}



	for (int i = 0; i < 7; i++)
	{
		printf("num[%d] : %d \n",i,num[i]);
	}

	/*
	a 5%
	b 10%  c 10%  d 10%
	e 15% f 15% 
	g 35%
	


	return 0;
}

*/
	//Que
/*
int main() 
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) { printf("ť�� ������ ���� �Ͽ����ϴ�. \n"); return 1; }
	
	while(1)
	{
		int m, x;

		printf("���� ������ ��:%d /%d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)ã�� (0)���� : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) 
		{
		case 1:
			printf("������ : "); scanf("%d", &x);
			if (Enque(&que, x) == -1) puts("\a ��ť�� �����Ͽ����ϴ�. ");
			break;
		case 2:
			if (Deque(&que, &x) == -1) puts("\a ��ť�� �����Ͽ����ϴ�. ");
			else printf("��ť�� �����ʹ� %d�Դϴ�. \n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1) puts("\a ��ũ�� �����Ͽ����ϴ�. ");
			else printf("��ũ�� �����ʹ� %d�Դϴ�. \n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			printf("ã������ ������ :");
			scanf("%d", &x);
			if (Search(&que, &x) == -1)printf("\a ã������ �����Ͱ� �����ϴ�. \n");
			else printf("ã������ �����Ͱ� %d��° �ֽ��ϴ�\n", x);
			break;
		}

	}
	return 0;
}



int Initialize(IntQueue *q, int max) 
{
	q->max = max;
	q->num = 0;
	q->front = 0;
	q->rear = 0;
	q->que = (int*)calloc(max, sizeof(int));

	if (q->que == -1) return -1;
	else 
	{
		return 1;
	}

}
int Enque(IntQueue *q, int x) 
{
	if (IsFull(q) == -1) return -1;
	else 
	{
		q->rear++;
		q->que[q->rear-1] = x;
		q->num++;
		
		return 1;
	}
}

int Deque(IntQueue *q, int *x) 
{

	if (IsEmpty(q) == -1) return -1;
	else 
	{
		q->num--;
		*x= q->que[q->front] ;
		q->front++;

		return 1;
	}
}

int Peek(const IntQueue *q, int *x) 
{
	if (IsEmpty(q) == -1) return -1;
	else 
	{
		*x = q->que[q->front];
		return 1;
	}
}

void Clear(IntQueue *q) 
{
	q->num = 0;
	q->rear = 0;
}

int Capacity(const IntQueue *q) 
{
	return q->max;
}

int Size(const IntQueue *q) 
{
	return q->num;
}

int IsEmpty(const IntQueue *q) 
{
	if (q->num == 0) return -1;
	else return 1;
}

int IsFull(const IntQueue *q) 
{
	if(q->rear==q->max) return -1;
	else return 1;
}

int Search(const IntQueue *q, int *x) 
{
	if (IsFull(q) == -1) { return -1; }
	else 
	{
		for (int i = q->front; i < q->rear; i++)
		{
			if ((q->que[i]) == *x)
			{
				*x = i + 1;
				return 1;
			}
		}

		for (int i = q->front; i < q->rear; i++)
		{
			if (*x != i) return -1;
		}
		return 1;
	}
	
}

int Print(const IntQueue *q) 
{
	if (IsEmpty(q) == -1) return -1;
	else 
	{
		printf("-----��� ��-----\n");
		for (int i = q->front; i < (q->rear); i++)
		{

			printf("%d \n", q->que[i]);
		}
		printf("-----------------\n");
		return 1;
	}
	
}

void Terminate(const IntQueue *q) 
{
	free(q->que);
}
*/
	//stack
/*
int main() 
{
	IntStack s;
	if (Initialize(&s, 64) == -1) { puts("���� ������ �����Ͽ����ϴ�."); return 1; }

	while (1) {
		int menu, x;
		printf("���� ������ ��:%d / %d \n", Size(&s), Capacity(&s));
		printf("(1) Ǫ��  (2) ��  (3) ��ũ  (4) ���  (5) �� ã��  (0) ���� : ");
		scanf("%d", &menu);
		
		if (menu == 0) break;

		switch(menu)
		{
		case 1:
			printf("������: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1) puts("\a����: Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;
		
		case 2:
			if (Pop(&s, &x) == -1) puts("\a����: �˿� �����Ͽ����ϴ�.");
			else printf("�� �����ʹ� %d�Դϴ�.\n\n", x);
			break;

		case 3:
			if (Peek(&s, &x) == -1) puts("\a����: ��ũ�� �����Ͽ����ϴ�.");
			else printf("��ũ �����ʹ� %d�Դϴ�.\n\n", x);
			break;

		case 4:
			Print(&s);
			break;

		case 5:
			printf("ã������ ������ :");
			scanf("%d", &x);
			if (Search(&s,&x)==-1)printf("ã������ �����Ͱ� �����ϴ�. \n");
			else printf("ã������ �����Ͱ� %d��° �ֽ��ϴ�\n",x);
			break;
		}
	}
	Terminate(&s);


	return 0;
}

int Initialize(IntStack *s, int max) //�ʱ�ȭ ũ�� �迭 ũ�� �Ҵ�
{
	s->max = max;
	s->ptr = 0;
	s->stk = (int*)calloc(s->max, sizeof(int));
	if (s->stk == -1) return -1;
	else return 1;
}

int Push(IntStack *s, int x)  //�迭�� x �־��ֱ�
{
	if (IsFull(s)==-1) return -1;
	else 
	{
		s->stk[s->ptr] = x;
		s->ptr++;
		return 1;
	}
}

int Pop(IntStack *s, int *x) // �迭�� ���� �� ���ֱ�
{
	
	if (IsEmpty(s) == -1) return -1;
	else 
	{
		*x = s->stk[s->ptr-1];
		s->ptr--;
		return 1;
	}
}

int Peek(const IntStack *s, int *x) // �迭�� ���� ���� �� ����
{
	
	if (IsEmpty(s) == -1) return -1;
	else
	{
		*x = s->stk[s->ptr-1];
		return 1;
	}
}

void Clear(IntStack *s) 
{
	s->ptr = 0;
}

int Capacity(const IntStack *s) // �Ҵ�� ����
{
	return s->max;
}

int Size(const IntStack *s) //
{
	return s->ptr;
}

int IsEmpty(const IntStack *s) 
{
	if (s->ptr == 0) return -1; //�����;���
	else return 1;
}

int IsFull(const IntStack *s)
{
	if (s->ptr == s->max) return -1; 
	else return 1;
}

int Search(const IntStack *s, int *x) 
{
	int i;
	for (i = 0; i < s->ptr; i++) 
	{
		if ((s->stk[i])==*x)
		{
			*x = i+1;
			return 1;
		}
	}
	
	for (i = 0; i < s->ptr; i++)
	{
		if (*x != i) return -1;
	}
	
}

int Print(const IntStack *s) 
{
	printf("-----��� ��-----\n");

	for(int i=0;i< (s->ptr);i++)
	{
		
		printf("%d \n",s->stk[i]);
	}
	printf("-----------------\n");
}

void Terminate(const IntStack *s) 
{
	free(s->stk);
}*/