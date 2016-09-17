#include <iostream>
#include <stdlib.h>
#include "vector.h"

using namespace std;

TVector::TVector()
{
	this->values = NULL;
	this->arr_size = 0;
}
TVector::~TVector()
{
	free(this->values);
}
bool TVector::resize(size_t new_size)
{
	this->arr_size = new_size;
	this->values = (int *) realloc(this->values, this->arr_size * sizeof(int));
	if (this->values == NULL && this->arr_size != 0) {
		return false;
	}
	return true;
}
size_t TVector::size()
{
	return this->arr_size;
}
void TVector::print()
{
	for (size_t i = 0; i < this->arr_size; i++) {
		cout << this->values[i] << ' ';
	}
	cout << endl;
}
