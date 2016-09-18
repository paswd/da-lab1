#include <stdio.h>
#include "data.h"

int CharToInt(int sym) {
	if (sym >= '0' && sym <= '9') {
		return sym - '0';
	}
	return 0;
}

int StrToInt(char *str, size_t size) {
	int res = 0;
	for (size_t i = 0; i < size; i++) {
		res *= 10;
		res += CharToInt(str[i]);
	}
	return res;
}

TNote::TNote() {
	this->key.day = 0;
	this->key.month = 0;
	this->key.year = 0;

	this->day_nulls_cnt = 0;
	this->month_nulls_cnt = 0;
	this->year_nulls_cnt = 0;
}

char TNote::PrenullsCnt(char *str) {
	char cnt = 0;
	for (size_t i = 0; i < 4; i++) {
		if (str[i] != '0') {
			break;
		}
		cnt++;
	}
	return cnt;
}

bool TNote::Input(void) {
	int sym = 0;
	char tmp[4];
	size_t pos = 0;
	char element = 0;
	bool mode = false;

	while ((sym = getchar()) != '\n') {
		if (sym == EOF) {
			return false;
		}
		if (!mode) {
			//Key parse block
			if (sym == '\t') {
				mode = true;
				pos = 0;
				continue;
			}
			if (sym == '.' || pos >= 4) {
				switch (element) {
					case 0:
						if (pos >= 4) {
							return false;
						}
						for (size_t i = 0; i < pos; i++) {
							this->key.day = (char) StrToInt(tmp, 4);
							this->day_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
						pos = 0;
						break;
					case 1:
						if (pos >= 4) {
							return false;
						}
						for (size_t i = 0; i < pos; i++) {
							this->key.month = (char) StrToInt(tmp, 4);
							this->month_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
						pos = 0;
						break;
					case 2:
						for (size_t i = 0; i < pos; i++) {
							this->key.year = (char) StrToInt(tmp, 4);
							this->year_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
					default:
						continue;
				}
			}
		} else {
			//Value parse block
			this->value[pos] = sym;
			pos++;
		}
	}
	if (pos > 63) {
		pos = 63;
	}
	this->value[pos] = '\0';
	return true;
}

void TNote::Print(void) {
	for (char i = 0; i < this->day_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d.", (int) this->key.day);

	for (char i = 0; i < this->month_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d.", (int) this->key.month);

	for (char i = 0; i < this->year_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d\t", (int) this->key.year);

	for (int i = 0; i < 64; i++) {
		printf("%c", this->value[i]);
		if (this->value[i] == '\0') {
			break;
		}
	}
}
