#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
//void operator(char ch, stack *or_s);
void distinction(char ch, queue *q, stack *f_s);
//void postfix(char ch, queue *q);
void Print(stack *f_s, queue *q);

/*
int main()
{




	return 0;
	int x = 0;
	//���� �ƽ�Ű �ڵ� 10
	queue postfix_q;
	stack operator_s;
	stack operand_s;

	char temp[50];
	char str[50] = "(";
	int i = 0;
	//�ʱ�ȭ
	initialize_s(&operator_s, 30);
	initialize_s(&operand_s, 30);
	initialize_q(&postfix_q, 30);

	printf("���� �Է��Ͻÿ�. \n");
	//scanf("%s", temp);
	strcpy(temp, "(4*2+12)*(123+7)");
	//()�ٿ��ֱ�
	strcat(temp, ")");
	strcat(str, temp);

	//���
	i = 0;

	for (i = 0; i <strlen(str)+1; i++)
	{

		//printf("%c", str[i]);
		distinction(str[i], &postfix_q, &operator_s);

	}
	
	return 0;


}*/

/*
void operator(char ch, stack *or_s, queue *q)
{

	int x=0;
	char arr[6]={ '(','+','-','*','/',')' };


}
void postfix(char ch,queue *q)
{
	printf("%c",ch);
}*/

//������ �ǿ����� ����
void distinction(char ch, queue *q, stack *f_s)
{
	int i, x = 0;
	char arr[6] = { '(','+','-','*','/',')' };

	//�������̸� ������ ������

	if ((ch == arr[0]) || (ch == arr[1]) || (ch == arr[2]) || (ch == arr[3]) || (ch == arr[4]) || (ch == arr[5]))
	{
		//operator(ch, or_s, q);

		if (ch == arr[0]) {
			Push_s(f_s, ch);
			printf("%c \n",ch);
		}
		else if ((ch == arr[1]) || (ch == arr[2]))
		{
			Peek_s(f_s, x);
			if (x == arr[3] || x == arr[4])
			{
				Pop_s(f_s, x);
				Enque_q(q, ch);
				printf("%c \n", ch);
			}
			else 
			{
				Push_s(f_s, ch); 
				printf("%c \n", ch);
			}
		}
	}
	//�ǿ������̸� �ǿ����� ������
	else
	{
		//Enque_q(q, ch);
	}

	Print(f_s, q);
}
void Print(stack *f_s, queue *q)
{
	int i;
	for (i = 0; i < f_s->size; i++)
	{
		printf("stack[%d]: %c \n", i, f_s->stack[i]);
	}
	/*
	for (i = q->front; i < q->size; i++)
	{
		printf("%c \n", q->que[i]);
	}*/
}