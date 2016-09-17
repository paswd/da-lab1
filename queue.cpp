#include <iostream>
#include "queue.h"

using namespace std;

const Item queue_empty = -9000000000000000000;

TQueue::TQueue() {
	this->first = NULL;
	this->last = NULL;
	this->error = 0;
}
TQueue::~TQueue() {
	TQueueNode *node_del = this->first;
	while (node_del) {
		TQueueNode *tmp = node_del->next;
		delete node_del;
		node_del = tmp;
	}
}

void TQueue::Push(Item value) {
	TQueueNode *nw = new TQueueNode;
	if (!nw) {
		this->error = 1;
		return;
	}
	nw->value = value;
	nw->next = NULL;
	if (this->last != NULL) {
		this->last->next = nw;
	} else {
		this->first = nw;
	}
	this->last = nw;
}

Item TQueue::Pop() {
	if (this->first == NULL) {
		cout << "Queue is empty" << endl;
		this->last = NULL;
		return queue_empty;
	}
	Item result = this->first->value;
	TQueueNode *node_del = this->first;
	this->first = node_del->next;
	delete node_del;
	return result;
}

Item TQueue::First() {
	return this->first->value;
}

bool TQueue::IsEmpty() {
	if (this->first == NULL) {
		this->last = NULL;
		return true;
	}
	return false;
}

void TQueue::Print() {
	TQueueNode *ths = this->first;
	while (ths) {
		cout << ths->value << " ";
		ths = ths->next;
	}
	cout << endl;
}
