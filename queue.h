#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef long long Item;

class TQueueNode {
public:
	Item value;
	TQueueNode *next;
};

class TQueue {
private:
	TQueueNode *first;
	TQueueNode *last;
	int error;
public:
	TQueue();
	~TQueue();

	void Push(Item value);
	Item Pop();
	Item First();
	bool IsEmpty();
	void Print();
};

#endif
