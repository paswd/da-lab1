#ifndef _DATA_H_
#define _DATA_H_

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

int CharToInt(int sym);
int StrToInt(char *str, size_t size);

class TDate {
public:
    char Day;
    char Month;
    short int Year;
};

class TNote {
private:
    char DayNullsCnt;
    char MonthNullsCnt;
    char YearNullsCnt;

    char PrenullsCnt(char *str);
    void TmpClear(char *str);
public:
    TDate Key;
    char Value[65];
    long long NumTmp;

    TNote();
    bool Input(void);
    void Print(void);
};


#endif
