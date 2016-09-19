#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"
#include "sorts.h"

int main(void) {
	/*TNote in_tmp;
	TQueue *queue = new TQueue;
	while (in_tmp.Input()) {
		queue->Push(in_tmp);
	}
	while (!queue->IsEmpty()) {
		queue->Pop().Print();
		printf("\n");
	}*/

	TVector *arr = new TVector;
	const size_t size = 10;
	arr->Resize(size);
	for (int i = 0; i < size; i++) {
		scanf("%d", arr->values + i);
	}
	printf("Start arr:\n");
	arr->Print();
	TVector *n_arr = CntSortScheme(arr);
	printf("Result arr:\n");
	n_arr->Print();
	delete arr;
	delete n_arr;
	return 0;
}
