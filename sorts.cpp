#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"

TVector *CntSortScheme(TVector *arr) {
	int cnts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	TVector *res = new TVector;
	res->Resize(arr->Size());
	for (size_t i = 0; i < arr->Size(); i++) {
		arr->values[i] %= 10;
		cnts[arr->values[i]]++;
	}
	for (size_t i = 1; i < 10; i++) {
		cnts[i] += cnts[i - 1];
	}
	for (int i = arr->Size() - 1; i >= 0; i--) {
		printf("I: %d\n", i);
		cnts[arr->values[i]]--;
		res->values[cnts[arr->values[i]]] = arr->values[i];
	}
	return res;
}
