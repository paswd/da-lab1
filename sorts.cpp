#include <stdio.h>
#include "vector.h"
#include "data.h"

TNote *CntSort(TVector *arr, TNote *notes) {
    int cnts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    TNote *res = new TNote[arr->Size()];

    for (size_t i = 0; i < arr->Size(); i++) {
        arr->Values[i] %= 10;
        cnts[arr->Values[i]]++;
    }

    for (size_t i = 1; i < 10; i++) {
        cnts[i] += cnts[i - 1];
    }

    for (int i = arr->Size() - 1; i >= 0; i--) {
        cnts[arr->Values[i]]--;
        res[cnts[arr->Values[i]]] = notes[i];
    }
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

    for (int i = 0; i < 8; i++) {
        for (size_t i = 0; i < size; i++) {
            sort_arr->Values[i] = arr[i].NumTmp % 10;
            arr[i].NumTmp /= 10;
        }
        
        TNote *new_arr = CntSort(sort_arr, arr);
        delete [] arr;
        arr = new_arr;
    }
    *in_arr = arr;
    delete sort_arr;
}
