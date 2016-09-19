#include <stdio.h>
#include "vector.h"
#include "queue.h"
#include "data.h"
#include "sorts.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

int main(void) {
    TNote in_tmp;
    TQueue *queue = new TQueue;
    size_t i = 0;
    while (in_tmp.Input()) {
        queue->Push(in_tmp);
        i++;
    }
    size_t size = i;
    TNote *notes = new TNote[size];
    i = 0;
    while (!queue->IsEmpty()) {
        notes[i] = queue->Pop();
        i++;
    }
    RadixSort(&notes, size);
    //printf("Point\n");
    for (i = 0; i < size; i++) {
        notes[i].Print();
    }
    //printf("Stop Point\n");
    //delete [] res;
    delete [] notes;
    delete queue;
    
    return 0;
}
