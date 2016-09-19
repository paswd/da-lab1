#ifndef _VECTOR_H_
#define _VECTOR_H_

class TVector {
private:
	size_t arr_size;
public:
	int *values;
	
	TVector();
	~TVector();
	bool Resize(size_t new_size);
	size_t Size();
	void Print();
};


#endif
