#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"

int main(void) {
	TNote in_tmp;
	TQueue *queue = new TQueue;
	while (in_tmp.Input()) {
		queue->Push(in_tmp);
	}
	while (!queue->IsEmpty()) {
		queue->Pop().Print();
		printf("\n");
	}
	return 0;
}
