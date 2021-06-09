/*
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
public:
	QueueTP();
	~QueueTP();

private:
	enum { !_SIZE = 10 };
	class Node
	{
	public: Item item;
			Node * next;
			Node(xonst Item &i): item(i),next(0){}
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP &q) :qsize(0) {}
	QueueTP & operator=(const QueueTP &q) { return *this; }
};
#endif //!QUEUETP_H_*/



