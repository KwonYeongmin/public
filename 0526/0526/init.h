#pragma once
#ifndef __Stack
#define __Stack

typedef struct
{
	int size;
	int max;
	char *stack;
}stack;

typedef struct
{
	int front;
	int rear;
	int size;
	int max;
	char *que;
}queue;


int initialize_s(stack *s,int max);
int Pop_s(stack *s,int *x);
int Peek_s(stack *s, int *x);
int Push_s(stack *s,int x);
int Size_s(const stack *s);
int Capacity_s(const stack *s);
int IsFull_s(const stack *s);
int IsEmpty_s(const stack *s);
void Terminate_s(stack *s);

int initialize_q(queue *q, int max);
int Deque_q(queue *q, int *x);
int Enque_q(queue *q, int x);
int Size_q(struct queue *q);
int Capacity_q(struct queue *q);
int IsFull_q(const queue *q);
int IsEmpty_q(const queue *q);
void Terminate_q(queue *q);
#endif // !__Stack
