#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class Type>
class Queue 
{
private:
	enum { SIZE = 10 };
	int size;
	Type *items;
	int top;
public:
	Queue(int ss = SIZE); //여기에 문제잇음 ㅜㅜ
	Queue(const Queue &q);
	~Queue() { delete[] items; };
	bool isempty() { return top == 0; };
	bool isfull() { return top == size; }
	bool Enque(const Type &item);
	bool Deque(Type &item);
	Queue & operator= (const Queue & q);
};

template <class Type>
Queue <Type>::Queue(int ss) : stacksize = ss,top(0)
{
	items = new Type[stacksize];
}
template <class Type>
Queue <Type>::Queue(const Queue &q) 
{
	size = q.size;
	top = q.top;
	items = new Type[size];
	for (int i = 0; i < top; i++) items[i] = q.items[i];
}
template <class Type>
bool Queue<Type>::Enque(const Type &item)
{
	if (top < size) { items[top++] = item; return true; }
	else return false;
}

template <class Type>
bool Queue<Type>::Deque(Type &item)
{
	if (top > 0) { item = items[--top]; return true; }
	else return false;
}
template <class Type>
Queue<Type>&Queue<Type>::operator= (const Queue<Type> &q)
{

}


#endif // !QUEUE_H_

