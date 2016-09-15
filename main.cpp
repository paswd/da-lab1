#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	Vector *arr = new Vector;
	arr->resize(2);
	arr->values[0] = 3;
	arr->values[1] = 2;
	arr->print();
	cout << arr->size() << endl;
	arr->resize(4);
	arr->values[2] = 1;
	arr->values[3] = 6;
	arr->print();
	cout << arr->size() << endl;
	arr->resize(2);
	arr->print();
	cout << arr->size() << endl;
	delete arr;
	return 0;
}
