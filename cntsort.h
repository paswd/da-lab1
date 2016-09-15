#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector {
private:
	size_t size;
public:
	int *arr;
	
	Vector();
	~Vector();
	bool resize(size_t new_size);
	size_t size();
};


#endif
