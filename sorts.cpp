#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"

TNote *CntSort(TVector *arr, TNote *notes) {
	//printf("-----\n");
	//arr->Print();
	int cnts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	TNote *res = new TNote[arr->Size()];
	//TVector *res2 = new TVector;
	//res2->Resize(arr->Size());
	//res->Resize(arr->Size());
	for (size_t i = 0; i < arr->Size(); i++) {
		arr->values[i] %= 10;
		cnts[arr->values[i]]++;
	}
	for (size_t i = 1; i < 10; i++) {
		cnts[i] += cnts[i - 1];
	}
	for (int i = arr->Size() - 1; i >= 0; i--) {
		cnts[arr->values[i]]--;
		res[cnts[arr->values[i]]] = notes[i];
		//res2->values[cnts[arr->values[i]]] = arr->values[i];
	}
	//res2->Print();
	//printf("=====\n");
	return res;
}

void RadixSort(TNote **in_arr, size_t size) {
	TNote *arr = *in_arr;
	TVector *sort_arr = new TVector;
	sort_arr->Resize(size);
	/*arr[0].num_tmp = 0;
	printf("%lld\n", arr[0].num_tmp);*/
	//printf("-----\n");

	//long long *data = new long long[size];
	for (size_t i = 0; i < size; i++) {
		//arr[i].Print();
		//printf("%lld.%lld.%lld\t", (long long) arr[i].key.day, (long long) arr[i].key.month, (long long) arr[i].key.year);
		arr[i].num_tmp = (long long) arr[i].key.year;
		//printf("%lld-", arr[i].num_tmp);
		arr[i].num_tmp += (long long) arr[i].key.month * 10000;
		//printf("%lld-", arr[i].num_tmp);
		arr[i].num_tmp += (long long) arr[i].key.day * 10000 * 100;
		//printf("%lld\n", arr[i].num_tmp);

		//sort_arr->values[i] = arr[i].num_tmp % 10;
	}
	//bool all_nulls = false;
	//printf("=====\n");

	for (int i = 0; i < 8; i++) {
		//bool null_log = true;
		for (size_t i = 0; i < size; i++) {
			sort_arr->values[i] = arr[i].num_tmp % 10;
			arr[i].num_tmp /= 10;
			/*if (sort_arr->values[i] != 0) {
				null_log = false;
			}*/
		}
		/*if (null_log) {
			printf("Exit: true\n");
			break;
		}*/
		TNote *new_arr = CntSort(sort_arr, arr);
		delete [] arr;
		arr = new_arr;
	}
	*in_arr = arr;
}
