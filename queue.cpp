#include <iostream>
#include "queue.h"

using namespace std;

const Item queue_empty = -9000000000000000000;

T_Queue::T_Queue() {
	this->first = NULL;
	this->last = NULL;
	this->error = 0;
}
T_Queue::~T_Queue() {
	T_QueueNode *node_del = this->first;
	while (node_del) {
		T_QueueNode *tmp = node_del->next;
		delete node_del;
		node_del = tmp;
	}
}

void T_Queue::Push(Item value) {
	T_QueueNode *nw = new T_QueueNode;
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

Item T_Queue::Pop() {
	if (this->first == NULL) {
		cout << "Queue is empty" << endl;
		this->last = NULL;
		return queue_empty;
	}
	Item result = this->first->value;
	T_QueueNode *node_del = this->first;
	this->first = node_del->next;
	delete node_del;
	return result;
}

Item T_Queue::First() {
	return this->first->value;
}

bool T_Queue::IsEmpty() {
	if (this->first == NULL) {
		this->last = NULL;
		return true;
	}
	return false;
}

void T_Queue::Print() {
	T_QueueNode *ths = this->first;
	while (ths) {
		cout << ths->value << " ";
		ths = ths->next;
	}
	cout << endl;
}
