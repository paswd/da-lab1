#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

TNote *CntSort(TVector *arr, TNote *notes) {
    //printf("-----\n");
    //arr->Print();
    int cnts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    TNote *res = new TNote[arr->Size()];
    //TVector *res2 = new TVector;
    //res2->Resize(arr->Size());
    //res->Resize(arr->Size());
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
        //res2->Values[cnts[arr->Values[i]]] = arr->Values[i];
    }
    //res2->Print();
    //printf("=====\n");
    return res;
}

void RadixSort(TNote **in_arr, size_t size) {
    TNote *arr = *in_arr;
    TVector *sort_arr = new TVector;
    sort_arr->Resize(size);
    /*arr[0].NumTmp = 0;
    printf("%lld\n", arr[0].NumTmp);*/
    //printf("-----\n");

    //long long *data = new long long[size];
    for (size_t i = 0; i < size; i++) {
        //arr[i].Print();
        //arr[i].NumTmp = (long long) arr[i].Key.Year;
        //printf("%lld-", arr[i].NumTmp);
        //arr[i].NumTmp += (long long) arr[i].Key.Month * 10000;
        //printf("%lld-", arr[i].NumTmp);
        //arr[i].NumTmp += (long long) arr[i].Key.Day * 10000 * 100;
        //printf("%lld\n", arr[i].NumTmp);
        arr[i].NumTmp = (long long) arr[i].Key.Day;
        arr[i].NumTmp += (long long) arr[i].Key.Month * 100;
        arr[i].NumTmp += (long long) arr[i].Key.Year * 10000;

        //sort_arr->Values[i] = arr[i].NumTmp % 10;
    }
    //bool all_nulls = false;
    //printf("=====\n");

    for (int i = 0; i < 8; i++) {
        //bool null_log = true;
        for (size_t i = 0; i < size; i++) {
            sort_arr->Values[i] = arr[i].NumTmp % 10;
            arr[i].NumTmp /= 10;
            /*if (sort_arr->Values[i] != 0) {
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
