#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector {
private:
	size_t arr_size;
public:
	int *values;
	
	Vector();
	~Vector();
	bool resize(size_t new_size);
	size_t size();
	void print();
};


#endif
