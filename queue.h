#ifndef _QUEUE_H_
#define 

#include "data.h"

typedef TNote Item;

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
