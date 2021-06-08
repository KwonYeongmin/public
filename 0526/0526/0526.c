#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
//void operator(char ch, stack *or_s);
void distinction(char ch, queue *q, stack *or_s);
//void postfix(char ch, queue *q);
void Print(stack *or_s, queue *q);

int main() 
{
	int x=0;
	//엔터 아스키 코드 10
	queue postfix_q;
	stack operator_s;
	stack operand_s;

	char temp[50];
	char str[50]="(";
	int i = 0;
	//초기화
	initialize_s(&operator_s, 30);
	initialize_s(&operand_s, 30);
	initialize_q(&postfix_q,30);

	printf("식을 입력하시오. \n");
	scanf("%s",temp);
	//()붙여주기
	strcat(temp, ")");
	strcat(str, temp);
	
	printf("%s", str);

	//계산
	//거꾸로들어가,, 숫자도,,, 거꾸로 들어가,,,,,,,
	//입력하는 대로 바로바로 넣어주기
	//연산자나오면 공백문자 포함
	for (i = strlen(str); i >= 0 ; i--)
	{

		printf("%c",str[i]);
		//distinction(str[i], &postfix_q, &operator_s);
		
	}
	
	return 0;
	

}

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

//연산자 피연산자 구분
void distinction(char ch, queue *q, stack *or_s)
{
	int i, x = 0;
	char arr[6] = { '(','+','-','*','/',')' };

	//연산자이면 연산자 나누기
		if ((ch == arr[0]) || (ch == arr[1]) || (ch == arr[2])||(ch == arr[3])||(ch == arr[4])|| (ch == arr[5]))
		{
			//operator(ch, or_s, q);

			if (ch == arr[0]) {
				Push_s(or_s, ch);
			}
			else if ((ch == arr[1]) || (ch == arr[2]))
			{
				Peek_s(or_s, x);
				if (x == arr[3] || x == arr[4])
				{
					Pop_s(or_s, x);
					Enque_q(q, ch);
				}
				else { Push_s(or_s, ch); }
			}
		}
		//피연산자이면 피연산자 나누기
		else 
		{
			Enque_q(q,ch);
		}
	
	Print(or_s,q);
}
void Print(stack *or_s, queue *q) 
{
	int i;
	for (i = 0; i < or_s->size;i++) 
	{
		printf("stack[%d]: %c \n",i,or_s->stack[i]);
	}
	/*
	for (i = q->front; i < q->size; i++)
	{
		printf("%c \n", q->que[i]);
	}*/
}