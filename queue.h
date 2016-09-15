#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef long long Item;

class T_QueueNode {
public:
	Item value;
	T_QueueNode *next;
};

class T_Queue {
private:
	T_QueueNode *first;
	T_QueueNode *last;
	int error;
public:
	T_Queue();
	~T_Queue();

	void Push(Item value);
	Item Pop();
	Item First();
	bool IsEmpty();
	void Print();
};

#endif
