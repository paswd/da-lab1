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

char TNote::PrenullsCnt(char *str) {
	char cnt = 0;
	for (char i = 0; i < 4; i++) {
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
	char pos = 0;
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
						for (char i = 0; i < pos; i++) {
							this->key->day = (char) StrToInt(tmp, 4);
							this->day_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
						pos = 0;
						break;
					case 1:
						if (pos >= 4) {
							return false;
						}
						for (char i = 0; i < pos; i++) {
							this->key->month = (char) StrToInt(tmp, 4);
							this->month_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
						pos = 0;
						break;
					case 2:
						for (char i = 0; i < pos; i++) {
							this->key->year = (char) StrToInt(tmp, 4);
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
}

void TNote::Print(void) {
	for (char i = 0; i < this->day_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d", (int) this->day);

	for (char i = 0; i < this->month_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d", (int) this->month);

	for (char i = 0; i < this->year_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d", (int) this->year);
}
