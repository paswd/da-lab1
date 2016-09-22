#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "data.h"
#include "sorts.h"

int main(void) {
    TNote in_tmp;
    size_t size = 0;
    TNote *notes = NULL;
    size_t t_size = 0;
    while (in_tmp.Input()) {
        size++;
        if (size > t_size) {
            t_size *= 2;
            if (t_size == 0) {
                t_size = 1;
            }
            notes = (TNote *) realloc(notes, t_size * sizeof(TNote));
        }
        notes[size - 1] = in_tmp;
    }
    if (t_size > size) {
        notes = (TNote *) realloc(notes, size * sizeof(TNote));
    }
    RadixSort(&notes, size);
    for (size_t i = 0; i < size; i++) {
        notes[i].Print();
    }
    free(notes);
    
    return 0;
}
