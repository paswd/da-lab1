#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "data.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

typedef TNote Item;

class TQueueNode {
public:
    Item Value;
    TQueueNode *Next;
};

class TQueue {
private:
    TQueueNode *FirstEl;
    TQueueNode *LastEl;
    int Error;
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
