#ifndef _VECTOR_H_
#define _VECTOR_H_

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

class TVector {
private:
    size_t ArrSize;
public:
    int *Values;
    
    TVector();
    ~TVector();
    bool Resize(size_t new_size);
    size_t Size();
    void Print();
    void Clear();
};


#endif
