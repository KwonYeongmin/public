#include <stdio.h>
#include <stdlib.h>
#include "init.h"


//Queue
int initialize_q(queue *q, int max)
{
	q->max = max;
	q->front = q->rear = q->size = 0;
	q->que = (double*)calloc(max, sizeof(double));

	if (q->que == NULL) return -1;
	else return 1;
}


int Deque_q(queue *q, char *x)
{
	if (IsEmpty_q(q) == -1) return -1;
	else
	{
		q->size--;
		*x = q->que[q->front];
		q->front++;

		return 1;
	}
}
int Enque_q(queue *q, char x)
{
	if (IsFull_q(q) == -1) return -1;
	else
	{
		q->rear++;
		q->que[q->rear - 1] = x;
		q->size++;

		return 1;
	}
}
int Size_q(const queue *q)
{
	return q->size;
}
int Capacity_q(const queue *q)
{
	return q->max;
}
int IsFull_q(const queue *q)
{
	if (q->size == q->max) return -1;
}
int IsEmpty_q(const queue *q)
{
	if (q->size == 0) return -1;
}


void Terminate_q(queue *q)
{
	free(q->que);
}



//Stack
int initialize_s(stack *s, int max)
{
	s->max = max;
	s->size = 0;
	s->stack = (double*)calloc(max, sizeof(double));

	if (s->stack == NULL) return -1;
	else return 1;
}

int Pop_s(stack *s, char *x)
{
	if (IsEmpty_s(s) == -1) return -1;
	else
	{
		*x = s->stack[s->size - 1];
		s->size--;
		return 1;
	}
}
int Peek_s(stack *s, char *x)
{
	if (IsEmpty_s(s) == -1) return -1;
	else
	{
		*x = s->stack[s->size - 1];
		return 1;
	}
}
int Push_s(stack *s, char x)
{
	if (IsFull_s(s) == -1) return -1;
	else
	{
		s->stack[s->size] = x;
		s->size++;
		return 1;
	}
}

int Size_s(const stack *s)
{
	return s->size;
}

int Capacity_s(const stack *s)
{
	return s->max;
}

int IsFull_s(const stack *s)
{
	if (s->size == s->max) return -1;
}

int IsEmpty_s(const stack *s)
{
	if (s->size == 0) return -1;

}

void Terminate_s(stack *s)
{
	free(s->stack);
}