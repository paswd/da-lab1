#include <iostream>
#include <stdlib.h>
#include "vector.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

using namespace std;

TVector::TVector() {
    this->Values = NULL;
    this->ArrSize = 0;
}
TVector::~TVector() {
    free(this->Values);
}
bool TVector::Resize(size_t new_size) {
    this->ArrSize = new_size;
    this->Values = (int *) realloc(this->Values, this->ArrSize * sizeof(int));
    if (this->Values == NULL && this->ArrSize != 0) {
        return false;
    }
    return true;
}
size_t TVector::Size() {
    return this->ArrSize;
}
void TVector::Print() {
    for (size_t i = 0; i < this->ArrSize; i++) {
        cout << this->Values[i] << ' ';
    }
    cout << endl;
}
void TVector::Clear() {
    for (size_t i = 0; i < this->ArrSize; i++) {
        this->Values[i] = 0;
    }
}
