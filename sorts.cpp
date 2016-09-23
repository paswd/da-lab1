#include <stdio.h>
#include "vector.h"
#include "data.h"

const size_t shift = 9;
const size_t base = 512; //2 ^ shift

TNote *CntSort(TVector *arr, TNote *notes) {
    int *cnts = new int[base];
    for (size_t i = 0; i < base; i++) {
        cnts[i] = 0;
    }
    TNote *res = new TNote[arr->Size()];

    for (size_t i = 0; i < arr->Size(); i++) {
        cnts[arr->Values[i]]++;
    }

    for (size_t i = 1; i < base; i++) {
        cnts[i] += cnts[i - 1];
    }

    for (int i = arr->Size() - 1; i >= 0; i--) {
        cnts[arr->Values[i]]--;
        res[cnts[arr->Values[i]]] = notes[i];
    }
    delete [] cnts;
    return res;
}

void RadixSort(TNote **in_arr, size_t size) {
    TNote *arr = *in_arr;
    TVector *sort_arr = new TVector;
    sort_arr->Resize(size);

    for (size_t i = 0; i < size; i++) {
        arr[i].NumTmp = (long long) arr[i].Key.Day;
        arr[i].NumTmp += (long long) arr[i].Key.Month * 100;
        arr[i].NumTmp += (long long) arr[i].Key.Year * 10000;
    }

    for (size_t j = 0; j < 32; j++) {
        bool all_nulls = true;
        for (size_t i = 0; i < size; i++) {
            if (arr[i].NumTmp != 0) {
                all_nulls = false;
            }
            sort_arr->Values[i] = (int) arr[i].NumTmp & (base - 1);
            arr[i].NumTmp = arr[i].NumTmp >> shift;
        }
        if (all_nulls) {
            break;
        }
        TNote *new_arr = CntSort(sort_arr, arr);
        delete [] arr;
        arr = new_arr;
    }
    *in_arr = arr;
    delete sort_arr;
}
