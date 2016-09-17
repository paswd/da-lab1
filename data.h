#ifndef _DATA_H_
#define _DATA_H_

int CharToInt(int sym);
int StrToInt(char *str, size_t size);

class TDate {
public:
	char day;
	char month;
	short int year;
};

class TNote {
private:
	char day_nulls_cnt;
	char month_nulls_cnt;
	char year_nulls_cnt;

	char PrenullsCnt(char *str);
	void TmpClear(char *str);
public:
	TDate key;
	char value[64];

	bool Input(void);
	void Print(void);
};


#endif
