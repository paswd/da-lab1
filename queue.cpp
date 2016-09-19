#include <iostream>
#include "queue.h"
#include "data.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

using namespace std;

//const Item queue_empty = -9000000000000000000;

TQueue::TQueue() {
    this->FirstEl = NULL;
    this->LastEl = NULL;
    this->Error = 0;
}
TQueue::~TQueue() {
    TQueueNode *node_del = this->FirstEl;
    while (node_del) {
        TQueueNode *tmp = node_del->Next;
        delete node_del;
        node_del = tmp;
    }
}

void TQueue::Push(Item value) {
    TQueueNode *nw = new TQueueNode;
    if (!nw) {
        this->Error = 1;
        return;
    }
    nw->Value = value;
    nw->Next = NULL;
    if (this->LastEl != NULL) {
        this->LastEl->Next = nw;
    } else {
        this->FirstEl = nw;
    }
    this->LastEl = nw;
}

Item TQueue::Pop() {
    if (this->FirstEl == NULL) {
        cout << "Queue is empty" << endl;
        this->LastEl = NULL;
        //return queue_empty;
        TNote nt_empty;
        return nt_empty;
    }
    Item result = this->FirstEl->Value;
    TQueueNode *node_del = this->FirstEl;
    this->FirstEl = node_del->Next;
    delete node_del;
    return result;
}

Item TQueue::First() {
    return this->FirstEl->Value;
}

bool TQueue::IsEmpty() {
    if (this->FirstEl == NULL) {
        this->LastEl = NULL;
        return true;
    }
    return false;
}

void TQueue::Print() {
    TQueueNode *ths = this->FirstEl;
    while (ths) {
        //cout << ths->Value << " ";
        ths = ths->Next;
    }
    cout << endl;
}
